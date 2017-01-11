#pragma once
#include "AnimatedActor.h"
#include "Level.h"
#include "Gun.h"

namespace tank_constants
{
	const float NORMAL_SPEED = 0.1f;
	const std::vector <std::string> _idleAnimations = { "IdleUp", "IdleDown", "IdleLeft", "IdleRight" };
	const std::vector <std::string> _moveAnimations = { "DriveUp", "DriveDown", "DriveLeft", "DriveRight" };
}


class Tank : public AnimatedActor
{
private:
	bool shouldShootBullet = false;
	bool destroyed = false;
public:
	Tank();
	Tank(Canvas &canvas, const std::string &filePath, float x, float y, Gun* gun, int health_points, Direction::Value direction);
	Tank(Canvas &canvas, const std::string &filePath, float x, float y, Direction::Value direction);
	void draw(Canvas &canvas);
	void update(std::vector<Actor*> actors, int elapsedTime);

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopMoving();
	void shoot();
	void playMovementSFX();
	void playShootingSFX();

	virtual void animationDone(std::string currentAnimation);
	virtual void setUpAnimations();
	virtual void handleCollisions(std::vector<Actor*> &collisionRects);
	virtual void onCollision(Actor* collidingActor);
	bool isDestoryed() { return destroyed; }

	/*const inline int getMaxHealth() const { return _maxHealth; }
	const inline int getCurrentHealth() const { return _currentHealth; }*/
protected:

	float _dx, _dy;
	float _prevX, _prevY;
	int _health_points;
	/*int _maxHealth;
	int _currentHealth;*/
	Direction::Value _direction;
	Gun* _gun;
	Bullet* _firedBullet = nullptr;
	void playAnimation(const string& animation);
};

