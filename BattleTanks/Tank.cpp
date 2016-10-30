#include "Tank.h"
#include "BasicGun.h"

Tank::Tank(){}

Tank::Tank(int x, int y, int health_points, Gun* gun, Direction::Value direction) :
		Actor(x, y), _health_points(health_points), _gun(gun), _direction(direction){}

Tank::Tank(int x, int y, int health_points) :
		Tank(x, y, health_points, new BasicGun(), Direction::up) {}

Tank::~Tank() { delete _gun; }