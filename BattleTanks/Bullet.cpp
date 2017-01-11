#include "Bullet.h"


Bullet::Bullet(Direction::Value direction, BulletType::BType type,  Canvas &canvas, int sourceX, int sourceY, int width, int height, float x, float y) 
	: Actor(canvas, "Content/Sprites/tank.png", sourceX, sourceY, width, height, x, y)
{
	_direction = direction;
	_bullet_type = type;
	switch (direction)
	{
	case Direction::up:
	{
		_dy = -bullet_constants::NORMAL_SPEED;
		break;
	}
	case Direction::left:
	{
		_dx = -bullet_constants::NORMAL_SPEED;
		break;
	}
	case Direction::down:
	{
		_dy = bullet_constants::NORMAL_SPEED;
		break;
	}
	case Direction::right:
	{
		_dx = bullet_constants::NORMAL_SPEED;
		break;
	}
	}
}
Bullet::~Bullet()
{

}
void Bullet::update(std::vector<Actor*> actors, int elapsedTime)
{
	std::vector<Actor*> collisionRects = checkCollision(actors);
	if (getBoundingBox().collidesWithMap() || collisionRects.size() > 0)
	{
		handleCollisions(collisionRects);
	}
	else
	{
		// Move by _dx
		_x += _dx * elapsedTime;
		// Move by _dy
		_y += _dy * elapsedTime;
	}
	Actor::update();
}
void Bullet::draw(Canvas &canvas)
{
	Actor::draw(canvas, _x, _y);
}
void Bullet::handleCollisions(std::vector<Actor*> &collisions)
{
	exploded = true;
	for (auto collision : collisions)
	{
		collision->onCollision(this);
	}

}
bool Bullet::hasExploded()
{
	return exploded;
}
