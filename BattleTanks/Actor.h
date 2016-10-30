#pragma once
#include <SDL_image.h>

class Actor
{
public:
	Actor() {}
	Actor(int x, int y) :
		_x(x), _y(y) {}
	virtual ~Actor() {}
	virtual void update() = 0;
	virtual void draw() const = 0;

protected:
	int _x, _y;
};

