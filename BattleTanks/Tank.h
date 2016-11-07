#pragma once
#include "AnimatedActor.h"
#include "Gun.h"

namespace tank_constants
{
	const float NORMAL_SPEED = 0.1f;
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
	string* _idleAnimations = new string[] { "IdleUp", "IdleDown", "IdleLeft", "IdleRight" };
	string* _moveAnimations = new string[] { "DriveUp", "DriveDown", "DriveLeft", "DriveRight" };
	Direction::Value _direction;
	Gun* _gun;
	Bullet* _firedBullet = nullptr;
	void playAnimation();
	void playAnimation(const string& animation);
};

