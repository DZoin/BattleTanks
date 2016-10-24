#include "Tank.h"


Tank::Tank()
{
}

Tank::Tank(unsigned x_coord, unsigned y_coord, unsigned shot_power,
	unsigned health_points, ShotType::Value shot_type, Direction::Value direction) :
		Actor(x_coord, y_coord), _shot_power(shot_power), _health_points(health_points), _shot_type(shot_type), _direction(direction){}

Tank::Tank(unsigned x_coord, unsigned y_coord, unsigned shot_power,
	unsigned health_points) :
		Tank(x_coord, y_coord, shot_power, health_points, ShotType::normal, Direction::up) {}



Tank::~Tank(){}
