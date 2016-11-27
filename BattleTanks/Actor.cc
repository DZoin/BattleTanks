#include "Actor.h"
#include "Canvas.h"
#include "Globals.h"

Actor::Actor() {}

Actor::Actor(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) : _x(posX), _y(posY)
{
	_sourceRect.x = sourceX;
	_sourceRect.y = sourceY;
	_sourceRect.w = width;
	_sourceRect.h = height;

	_spriteSheet = SDL_CreateTextureFromSurface(canvas.getRenderer(), canvas.loadImage(filePath));

	if (_spriteSheet == NULL)
	{
		printf("\nError: Unable to load image\n");
	}

	_boundingBox = Rectangle(_x, _y, width * globals::ACTOR_SCALE, height * globals::ACTOR_SCALE);

}

Actor::~Actor() {}

void Actor::draw(Canvas &canvas, int x, int y)
{
	SDL_Rect destinationRectangle = { x, y, _sourceRect.w * globals::ACTOR_SCALE, _sourceRect.h * globals::ACTOR_SCALE };
	canvas.blitSurface(_spriteSheet, &_sourceRect, &destinationRectangle);
}

void Actor::update() 
{
	_boundingBox = Rectangle(_x, _y, _sourceRect.w * (globals::ACTOR_SCALE), _sourceRect.h * (globals::ACTOR_SCALE));
}

const Rectangle Actor::getBoundingBox() const
{
	return _boundingBox;
}

// Side getCollisionSide
// Determine which side the collision happened on
const sides::Side Actor::getcollisionSide(Rectangle &other) const
{
	int amtRight, amtLeft, amtTop, amtBottom;
	amtRight = getBoundingBox().getRight() - other.getLeft();
	amtLeft = other.getRight() - getBoundingBox().getLeft();
	amtTop = other.getBottom() - getBoundingBox().getTop();
	amtBottom = getBoundingBox().getBottom() - other.getTop();

	int vals[4] = { abs(amtRight), abs(amtLeft), abs(amtLeft), abs(amtRight) };
	int lowest = vals[0];
	for (int i = 0; i < 4; i++)
	{
		if (vals[i] < lowest)
		{
			lowest = vals[i];
		}
	}

	return lowest == abs(amtRight) ? sides::RIGHT :
		lowest == abs(amtLeft) ? sides::LEFT :
		lowest == abs(amtTop) ? sides::TOP :
		lowest == abs(amtBottom) ? sides::BOTTOM :
		sides::NONE;
}

