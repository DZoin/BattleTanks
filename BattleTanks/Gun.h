#pragma once
#include "Bullet.h"

class Gun
{
public:
	virtual Bullet* shoot(float x, float y, Direction::Value direction) = 0;
};