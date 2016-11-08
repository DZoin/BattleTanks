#pragma once
#include "AnimatedActor.h"
#include "Gun.h"

namespace tank_constants
{
	const float NORMAL_SPEED = 0.1f;
	const std::vector <std::string> _idleAnimations = { "IdleUp", "IdleDown", "IdleLeft", "IdleRight" };
	const std::vector <std::string> _moveAnimations = { "DriveUp", "DriveDown", "DriveLeft", "DriveRight" };
}


class Tank : public AnimatedActor
{
public:
	Tank();
	Tank(Canvas &canvas, const std::string &filePath, float x, float y, Gun* gun, Direction::Value direction);
	Tank(Canvas &canvas, const std::string &filePath, float x, float y, Direction::Value direction);
	void draw(Canvas &canvas);
	void update(int elapsedTime);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopMoving();
	void shoot();

	virtual void animationDone(std::string currentAnimation);
	virtual void setUpAnimations();

protected:

	float _dx, _dy;
	int _health_points;
	Direction::Value _direction;
	Gun* _gun;
	Bullet* _firedBullet = nullptr;
	void playAnimation(const string& animation);
};

