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
}

Actor::~Actor() {}

void Actor::draw(Canvas &canvas, int x, int y)
{
	SDL_Rect destinationRectangle = { x, y, _sourceRect.w * globals::ACTOR_SCALE, _sourceRect.h * globals::ACTOR_SCALE };
	canvas.blitSurface(_spriteSheet, &_sourceRect, &destinationRectangle);
}

void Actor::update() {}

