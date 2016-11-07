#pragma once
#include "Bullet.h"

class Gun
{
public:
	Gun();
	virtual ~Gun();
	virtual Bullet* shoot(float x, float y, Direction::Value direction) = 0;
};