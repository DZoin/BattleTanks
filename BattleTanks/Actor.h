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
	void draw(Canvas &canvas);

	virtual const Rectangle getBoundingBox() const;
	const sides::Side getCollisionSide(Rectangle &other) const;
	virtual void handleTileCollisions(std::vector<Actor*> &collisionRects) = 0;
	virtual void handleCollision(Actor* collidingActor) = 0;
	std::vector<Actor*> checkCollision(std::vector<Actor*> &actors);

	const inline float getX() const { return _x; }
	const inline float getY() const { return _y; }

	void setSourceRectW(int value);
	void setSourceRectH(int value);
protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	Rectangle _boundingBox;

	float _x, _y;
};

