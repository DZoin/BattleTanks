#include "BasicGun.h"


BasicGun::BasicGun()
{
}

BasicGun::~BasicGun()
{
}

Bullet* BasicGun::getBullet(int x, int y)
{
	return new Bullet(x, y, _bullet_damage, BulletType::Basic);
}