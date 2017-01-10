#include "BasicGun.h"

Bullet* BasicGun::shoot(Direction::Value direction, Canvas &canvas, float x, float y)
{
	switch (direction)
	{
		case Direction::up: 
		{
			return new Bullet(direction, BulletType::Basic, canvas, 0, 0, 4, 4, x+10, y-8);
		}
		case Direction::left:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 8, 0, 4, 4, x-8, y+11);
		}
		case Direction::down:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 16, 0, 4, 4, x+10, y+32);
		}
		case Direction::right:
		{
			return new Bullet(direction, BulletType::Basic, canvas, 24, 0, 4, 4, x+32, y+11);
		}
	}
}