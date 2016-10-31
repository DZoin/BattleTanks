#include "Bullet.h"


Bullet::Bullet()
{
}

Bullet::Bullet(int x, int y, int damage, BulletType::BType bullet_type) :
Actor(x, y), _damage(damage), _bullet_type(bullet_type)
{}

Bullet::~Bullet()
{
}

void Bullet::update()
{
	//TO DO
}

void Bullet::draw() const
{
	//TO DO
}
