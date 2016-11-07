#pragma once
#include "Actor.h"

namespace BulletType
{
	enum BType {Basic};
}

class Bullet : public Actor
{
public:
	Bullet();
	Bullet(float x, float y, Direction::Value direction, BulletType::BType);
	~Bullet();
	bool checkForCollisions();
	void update(int elapsedTime);
	void draw(Canvas &canvas);
protected:
	BulletType::BType _bullet_type;
};

