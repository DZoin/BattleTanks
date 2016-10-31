#pragma once
#include "Bullet.h"

class Gun
{
public:
	Gun();
	Gun(int bullet_damage);
	virtual ~Gun();
	virtual Bullet* getBullet(int x, int y) = 0;
protected:
	int _bullet_damage;
};

