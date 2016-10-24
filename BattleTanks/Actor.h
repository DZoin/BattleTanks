#pragma once

class Actor
{
public:
	Actor();
	Actor(unsigned x_coord, unsigned y_coord);
	virtual ~Actor() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;

protected:
	unsigned int _x_coord, _y_coord;
};

