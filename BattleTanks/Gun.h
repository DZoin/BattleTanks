#pragma once
#include "Bullet.h"

class Gun
{
public:
	virtual Bullet* shoot(Direction::Value direction, Canvas &canvas, float x, float y) = 0;
};