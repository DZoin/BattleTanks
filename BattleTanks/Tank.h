#pragma once
#include "AnimatedActor.h"
#include "Gun.h"
#include "Globals.h"

namespace Direction
{
	enum Value { up = 1, down = 2, left = 3, right = 4 };
}

class Tank: public AnimatedActor
{
public:
	Tank();
	Tank(Canvas &canvas, float x, float y, int health_points, Gun* gun, Direction::Value direction);
	Tank(Canvas &canvas, float x, float y, int health_points);
	void draw(Canvas &canvas);
	void update(float elapsedTime);

	virtual void animationDone(std::string currentAnimation);
	virtual void setUpAnimations();

protected:

	float _dx, _dy;
	int _health_points;
	Direction::Value _direction = Direction::down;
	Gun* _gun;

};

