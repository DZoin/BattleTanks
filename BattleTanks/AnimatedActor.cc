#include "AnimatedActor.h"
#include "Canvas.h"
#include "Actor.h"
#include "Globals.h"

// Animates our sprites

AnimatedActor::AnimatedActor() {}

AnimatedActor::AnimatedActor(Canvas &canvas, const std::string &filePath, 
	int sourceX, int sourceY, int width, int height, 
	float posX, float posY, float timeToUpdate)
	: Actor(canvas, filePath, sourceX, sourceY, width, height, posX, posY), 
	_frameIndex(0), _timeToUpdate(timeToUpdate), _visible(true), _currentAnimationOnce(false), _currentAnimation("") {}

void AnimatedActor::addAnimation(int frames, int x, int y, std::string name, int width, int height, Vector2 offset)
{
	std::vector<SDL_Rect> rectnagles;

	for (int i = 0; i < frames; i++)
	{
		SDL_Rect newRect = { (i + x) * width, y, width, height };
		rectnagles.push_back(newRect);
	}
	_animations.insert(std::pair<std::string, std::vector<SDL_Rect>>(name, rectnagles));
	_offsets.insert(std::pair<std::string, Vector2>(name, offset));
}

void AnimatedActor::resetAnimations()
{
	_animations.clear();
	_offsets.clear();
}

void AnimatedActor::playAnimation(std::string animation, bool once)
{
	_currentAnimationOnce = once;
	if (_currentAnimation != animation)
	{
		_currentAnimation = animation;
		_frameIndex = 0;
	}
}

void AnimatedActor::setVisible(bool visible)
{
	_visible = visible;
}

void AnimatedActor::stopAnimation()
{
	_frameIndex = 0;
	animationDone(_currentAnimation);
}

void AnimatedActor::update(int elapsedTime)
{
	Actor::update();

	_timeElapsed += elapsedTime;
	if (_timeElapsed > _timeToUpdate)
	{
		_timeElapsed -= _timeToUpdate;
		if (_frameIndex < _animations[_currentAnimation].size() - 1)
		{
			_frameIndex++;
		}
		else
		{
			if (_currentAnimationOnce == true)
			{
				setVisible(false);
			}
			_frameIndex = 0;
			animationDone(_currentAnimation);
		}
	}
}

void AnimatedActor::draw(Canvas &canvas, int x, int y)
{
	if (_visible)
	{
		SDL_Rect destinationRectangle;
		destinationRectangle.x = x + _offsets[_currentAnimation].x;
		destinationRectangle.y = y + _offsets[_currentAnimation].y;
		destinationRectangle.w = _sourceRect.w * globals::ACTOR_SCALE;
		destinationRectangle.h = _sourceRect.h * globals::ACTOR_SCALE;

		SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
		canvas.blitSurface(_spriteSheet, &sourceRect, &destinationRectangle);
	}
}


