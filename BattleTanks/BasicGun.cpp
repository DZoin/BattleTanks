#include "BasicGun.h"

Bullet* BasicGun::shoot(float x, float y, Direction::Value direction)
{
	return new Bullet(x, y, direction, BulletType::Basic);
}