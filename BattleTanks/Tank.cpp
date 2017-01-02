#include "Tank.h"
#include "Canvas.h"
#include "BasicGun.h"
#include "AnimatedActor.h"

Tank::Tank(){}

Tank::Tank(Canvas &canvas, const std::string &filePath, float x, float y, Direction::Value direction) : Tank(canvas, filePath, x, y, new BasicGun(), direction) {}

Tank::Tank(Canvas &canvas, const std::string &filePath, float x, float y, Gun* gun, Direction::Value direction) : AnimatedActor(canvas, filePath, 0, 0, 16, 16, x, y, 100)
{
	canvas.loadImage(filePath);
	_prevX = x;
	_prevY = y;

	this->_direction = direction;
	this->_gun = gun;

	setUpAnimations();
	stopMoving();
}

void Tank::playAnimation(const string& animation)
{
	AnimatedActor::playAnimation(animation);
}

void Tank::setUpAnimations()
{
	addAnimation(1, 0, 0, "IdleUp", 16, 16, Vector2(0, 0));
	addAnimation(1, 2, 0, "IdleLeft", 16, 16, Vector2(0, 0));
	addAnimation(1, 4, 0, "IdleDown", 16, 16, Vector2(0, 0));
	addAnimation(1, 6, 0, "IdleRight", 16, 16, Vector2(0, 0));


	addAnimation(2, 0, 0, "DriveUp", 16, 16, Vector2(0, 0));
	addAnimation(2, 2, 0, "DriveLeft", 16, 16, Vector2(0, 0));
	addAnimation(2, 4, 0, "DriveDown", 16, 16, Vector2(0, 0));
	addAnimation(2, 6, 0, "DriveRight", 16, 16, Vector2(0, 0));

}

void Tank::animationDone(std::string currentAnimation) {}


void Tank::moveUp()
{
	this->_dy = -tank_constants::NORMAL_SPEED;
	this->_dx = 0.0f;
	this->_direction = Direction::up;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
}

void Tank::moveDown() 
{
	this->_dy = tank_constants::NORMAL_SPEED;
	this->_dx = 0.0f;
	this->_direction = Direction::down;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
}

void Tank::moveRight()
{
	this->_dx = tank_constants::NORMAL_SPEED;
	this->_dy = 0.0f;
	this->_direction = Direction::right;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
	
}

void Tank::moveLeft()
{
	this->_dx = -tank_constants::NORMAL_SPEED;
	this->_dy = 0.0f;
	this->_direction = Direction::left;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
}

void Tank::stopMoving()
{
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	this->playAnimation(tank_constants::_idleAnimations[_direction]);
}

void Tank::shoot() 
{
	if (_firedBullet == nullptr) 
	{
		shouldShootBullet = true;
	}
}

void Tank::update(Level &level, int elapsedTime)
{
	std::vector<Actor*> collisionRects = level.checkTileCollision(getBoundingBox());
	if (collisionRects.size() > 0)
	{
		handleTileCollisions(collisionRects);
	}
	else
	{
		_prevX = _x;
		_prevY = _y;
		// Move by _dx
		_x += _dx * elapsedTime;
		// Move by _dy
		_y += _dy * elapsedTime;
	}


	if (_firedBullet != nullptr)
	{
		_firedBullet->update(level, elapsedTime);
		if (_firedBullet->hasExploded())
		{
			delete _firedBullet;
			_firedBullet = nullptr;
		}
	}
	AnimatedActor::update(elapsedTime);
}

void Tank::handleTileCollisions(std::vector<Actor*> &collisionRects)
{
	_x = _prevX;
	_y = _prevY;
}

void Tank::draw(Canvas &canvas)
{
	if (shouldShootBullet)
	{
		_firedBullet = _gun->shoot(_direction, canvas, _x, _y);
		shouldShootBullet = false;
	}
	if (_firedBullet != nullptr)
	{
		_firedBullet->draw(canvas);
	}
	AnimatedActor::draw(canvas, _x, _y);
}