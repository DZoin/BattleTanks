#pragma once
#include <SDL_image.h>
#include <string>
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

protected:
	SDL_Rect _sourceRect;
	SDL_Texture* _spriteSheet;

	float _x, _y;
};

