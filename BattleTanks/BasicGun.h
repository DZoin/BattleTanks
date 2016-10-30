#pragma once
#include "Gun.h"
#include "Bullet.h"

class BasicGun :
	public Gun
{
public:
	BasicGun();
	~BasicGun();
	virtual Bullet* getBullet(int x, int y);
};

