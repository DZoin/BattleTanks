#pragma once
#include "Actor.h"

namespace BulletType
{
	enum BType {Basic};
}

class Bullet :
	public Actor
{
public:
	Bullet();
	//Bullet(int x, int y, int damage, BulletType::BType);
	~Bullet();
	void update();
	void draw() const;
protected:
	int _damage;
	BulletType::BType _bullet_type;
};

