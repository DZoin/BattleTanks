#pragma once
#include "Gun.h"
#include "Bullet.h"

class BasicGun : public Gun
{
public:
	virtual Bullet* shoot(Direction::Value direction, Canvas &canvas, float x, float y);
};