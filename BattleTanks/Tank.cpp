#include "Tank.h"
#include "Canvas.h"
#include "BasicGun.h"
#include "AnimatedActor.h"

namespace tank_contants
{
	const float MOVE_SPEED = 0.1f;
}

Tank::Tank(){}

Tank::Tank(Canvas &canvas, float x, float y, int health_points) : Tank(canvas, x, y, health_points, new BasicGun(), Direction::down) {}

Tank::Tank(Canvas &canvas, float x, float y, int health_points, Gun* gun, Direction::Value direction) : AnimatedActor(canvas, "Content/Sprites/tank.png", 0, 0, 16, 16, x, y, 100)
{
	canvas.loadImage("Content/Sprites/tank.png");

	this->_direction = direction;
	this->_health_points = health_points;
	this->_gun = gun;

	setUpAnimations();
	playAnimation("DriveDown");
}

void Tank::setUpAnimations()
{
	addAnimation(1, 0, 0, "IdleUP", 16, 16, Vector2(0, 0));
	addAnimation(1, 2, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	addAnimation(1, 4, 0, "IdleDown", 16, 16, Vector2(0, 0));
	addAnimation(1, 6, 0, "IdleRight", 16, 16, Vector2(0, 0));


	addAnimation(2, 0, 0, "DriveUP", 16, 16, Vector2(0, 0));
	addAnimation(2, 2, 0, "DriveLeft", 16, 16, Vector2(0, 0));
	addAnimation(2, 4, 0, "DriveDown", 16, 16, Vector2(0, 0));
	addAnimation(2, 6, 0, "DriveRight", 16, 16, Vector2(0, 0));

}

void Tank::animationDone(std::string currentAnimation) {}

void Tank::update(float elapsedTime)
{
	// Move by _dx
	_x += _dx * elapsedTime;

	// Move by _dy
	_y += _dy * elapsedTime;

	AnimatedActor::update(elapsedTime);
}

void Tank::draw(Canvas &canvas)
{
	AnimatedActor::draw(canvas, _x, _y);
}