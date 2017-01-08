#include "BasicGun.h"

Bullet* BasicGun::shoot(Direction::Value direction, Canvas &canvas, float x, float y)
{
	switch (direction)
	{
		case Direction::up: 
		{
			return new Bullet(direction, BulletType::Basic, canvas, 0, 0, 16, 16, x, y-32);
		}
		case Direction::left:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 32, 0, 16, 16, x-32, y);
		}
		case Direction::down:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 64, 0, 16, 16, x, y+32);
		}
		case Direction::right:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 96, 0, 16, 16, x+32, y);
		}
	}
}