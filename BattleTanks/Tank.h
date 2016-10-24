#pragma once
#include "Actor.h"

namespace ShotType
{
	enum Value {normal = 1};
}

namespace Direction
{
	enum Value { up = 1, down = 2, left = 3, right = 4 };
}

class Tank :
	public Actor
{
public:
	Tank();
	Tank(unsigned x_coord, unsigned y_coord, unsigned shot_power, 
		unsigned health_points);
	Tank(unsigned x_coord, unsigned y_coord, unsigned shot_power, 
		unsigned health_points, ShotType::Value shot_type, Direction::Value direction);
	~Tank();

private:
	unsigned int _shot_power, _health_points;
	ShotType::Value _shot_type = ShotType::normal;
	Direction::Value _direction = Direction::up;

};

