#pragma once
#include "Actor.h"
#include "Level.h"

namespace BulletType
{
	enum BType {Basic};
}

namespace bullet_constants
{
	const float NORMAL_SPEED = 0.25f;
}

class Bullet : public Actor
{
private:
	bool exploded = false;
	Direction::Value _direction;
	BulletType::BType _bullet_type;
	float _dx = 0, _dy = 0;
public:
	Bullet();
	Bullet(Direction::Value direction, BulletType::BType type, Canvas &canvas, int sourceX, int sourceY, int width, int height, float x, float y);
	~Bullet();
	void update(Level &level, int elapsedTime);
	void draw(Canvas &canvas);
	void handleTileCollisions(std::vector<Rectangle> &collisionRects);
	bool hasExploded();	
};

