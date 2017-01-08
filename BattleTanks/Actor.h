#pragma once
#include <SDL_image.h>
#include <string>
#include <vector>
#include "Rectangle.h"
#include <SDL.h>


#include "Globals.h"
class Canvas;
class Actor;

class Actor
{
public:
	Actor();
	Actor(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual ~Actor();
	virtual void update();
	void draw(Canvas &canvas, int x, int y);

	const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle &other) const;
	virtual void handleTileCollisions(std::vector<Rectangle> &collisionRects) = 0;
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	Rectangle _boundingBox;

	float _x, _y;
};

