#pragma once
#include "Gun.h"
#include "Bullet.h"

class BasicGun : public Gun
{
public:
	virtual Bullet* shoot(float x, float y, Direction::Value direction);
};