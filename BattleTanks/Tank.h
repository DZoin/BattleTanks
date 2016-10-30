#pragma once
#include "Actor.h"
#include "Gun.h"

namespace Direction
{
	enum Value { up = 1, down = 2, left = 3, right = 4 };
}

class Tank :
	public Actor
{
public:
	Tank();
	Tank(int x, int y, int health_points);
	Tank(int x, int y, int health_points, Gun* gun, Direction::Value direction);
	virtual ~Tank();

protected:
	//SDL_Texture* _texture = nullptr;
	int _health_points;
	Direction::Value _direction = Direction::up;
	Gun* _gun;

};

