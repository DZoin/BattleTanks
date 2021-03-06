#include "Tank.h"
#include "Canvas.h"
#include "BasicGun.h"
#include "AnimatedActor.h"
#include <SDL_mixer.h>

Tank::Tank(){}

Tank::Tank(Canvas &canvas, const std::string &filePath, float x, float y, Direction::Value direction) : Tank(canvas, filePath, x, y, new BasicGun(), 4, direction) {}

Tank::Tank(Canvas &canvas, const std::string &filePath, float x, float y, Gun* gun, int health_points, Direction::Value direction) : AnimatedActor(canvas, filePath, 0, 0, 16, 16, x, y, 100)
{
	canvas.loadImage(filePath);
	_prevX = x;
	_prevY = y;

	this->_direction = direction;
	this->_gun = gun;
	this->_health_points = health_points;

	setUpAnimations();
	stopMoving();
}

void Tank::playDeathSFX()
{
	// open 44.1KHz, signed 16bit, system byte order,

	// stereo audio, using 1024 byte chunks

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}


	//End of initialization

	//Declaring and loading a wav file, used for movements and actions

	// load sample.wav in to sample
	Mix_Chunk *sample;
	sample = Mix_LoadWAV("Content/SondFX(WAVs)/deathSound.wav");
	if (!sample) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		// handle error

	}

	//End of WAV loading

	// set channel 2 to half volume

	Mix_Volume(4, MIX_MAX_VOLUME / 6);

	// print the average volume

	printf("1st channel volume is %d\n", Mix_Volume(2, -1));

	// play sample on first free unreserved channel

	// play it exactly once through

	// Mix_Chunk *sample; //previously loaded

	if (Mix_PlayChannel(4, sample, 0) == -1) {

		printf("Mix_PlayChannel: %s\n", Mix_GetError());

		// may be critical error, or maybe just no channels were free.

		// you could allocated another channel in that case...S

	}
}

void Tank::playShootingSFX()
{
	// open 44.1KHz, signed 16bit, system byte order,

	//stereo audio, using 1024 byte chunks

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {

		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}

	//End of initialization

	//Declaring and loading a wav file, used for movements and actions


	// load sample.wav in to sample

	// load sample.wav in to sample
	Mix_Chunk *sample;
	sample = Mix_LoadWAV("Content/SondFX(WAVs)/shootingFX.wav");
	if (!sample) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		// handle error
	}

	//End of WAV loading

	// set channel 2 to half volume

	Mix_Volume(3, MIX_MAX_VOLUME / 6);

	// print the average volume

	printf("1st channel volume is %d\n", Mix_Volume(2, -1));

	// play sample on first free unreserved channel

	// play it exactly once through

	// Mix_Chunk *sample; //previously loaded

	if (Mix_PlayChannel(3, sample, 0) == -1) {

		printf("Mix_PlayChannel: %s\n", Mix_GetError());

		// may be critical error, or maybe just no channels were free.
	}
}

void Tank::playMovementSFX()
	{
		// open 44.1KHz, signed 16bit, system byte order,

		// stereo audio, using 1024 byte chunks

		if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {

			printf("Mix_OpenAudio: %s\n", Mix_GetError());
		}


		//End of initialization

		//Declaring and loading a wav file, used for movements and actions

		// load sample.wav in to sample
		Mix_Chunk *sample;
		sample = Mix_LoadWAV("Content/SondFX(WAVs)/movementFX.wav");
		if (!sample) {
			printf("Mix_LoadWAV: %s\n", Mix_GetError());
			// handle error

		}

		//End of WAV loading

		// set channel 2 to half volume

		Mix_Volume(2, MIX_MAX_VOLUME / 6);

		// print the average volume

		printf("1st channel volume is %d\n", Mix_Volume(2, -1));

		// play sample on first free unreserved channel

		// play it exactly once through

		// Mix_Chunk *sample; //previously loaded

		if (Mix_PlayChannelTimed(2, sample, -1, -1) == -1) {

			printf("Mix_PlayChannel: %s\n", Mix_GetError());

			// may be critical error, or maybe just no channels were free.

			// you could allocated another channel in that case...S

		}
	}

void Tank::playIddleSFX()
{
	// open 44.1KHz, signed 16bit, system byte order,

	// stereo audio, using 1024 byte chunks

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {

		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}


	//End of initialization

	//Declaring and loading a wav file, used for movements and actions

	// load sample.wav in to sample
	Mix_Chunk *sample;
	sample = Mix_LoadWAV("Content/SondFX(WAVs)/iddleSound.wav");
	if (!sample) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		// handle error

	}

	//End of WAV loading

	// set channel 2 to half volume

	Mix_Volume(5, MIX_MAX_VOLUME / 6);

	// print the average volume

	printf("1st channel volume is %d\n", Mix_Volume(2, -1));

	// play sample on first free unreserved channel

	// play it exactly once through

	// Mix_Chunk *sample; //previously loaded

	if (Mix_PlayChannelTimed(5, sample, -1, -1) == -1) {

		printf("Mix_PlayChannel: %s\n", Mix_GetError());

		// may be critical error, or maybe just no channels were free.

		// you could allocated another channel in that case...S

	}
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

	addAnimation(3, 0, 128, "Explosion1", 16, 16, Vector2(0, 0));
	//addAnimation(2, 0, 144, "Explosion2", 32, 32, Vector2(0, 0));
}

void Tank::animationDone(std::string currentAnimation) {
	if (tank_constants::_deathAnimation.compare(currentAnimation) == 0)
	{
		destroyed = true;
	}

}


void Tank::moveUp()
{
	this->_dy = -tank_constants::NORMAL_SPEED;
	this->_dx = 0.0f;
	this->_direction = Direction::up;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
	this->playMovementSFX();

	Mix_Pause(5);

	if (Mix_Paused(2) == 1)
	{
		Mix_Resume(2);
	}
}

void Tank::moveDown() 
{
	this->_dy = tank_constants::NORMAL_SPEED;
	this->_dx = 0.0f;
	this->_direction = Direction::down;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
	this->playMovementSFX();

	Mix_Pause(5);


	if (Mix_Paused(2) == 1)
	{
		Mix_Resume(2);
	}

}

void Tank::moveRight()
{
	this->_dx = tank_constants::NORMAL_SPEED;
	this->_dy = 0.0f;
	this->_direction = Direction::right;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
	this->playMovementSFX();

	Mix_Pause(5);


	if (Mix_Paused(2) == 1)
	{
		Mix_Resume(2);
	}
}

void Tank::moveLeft()
{
	this->_dx = -tank_constants::NORMAL_SPEED;
	this->_dy = 0.0f;
	this->_direction = Direction::left;
	this->playAnimation(tank_constants::_moveAnimations[_direction]);
	this->playMovementSFX();

	Mix_Pause(5);


	if (Mix_Paused(2) == 1)
	{
		Mix_Resume(2);
	}
}

void Tank::stopMoving()
{
	this->_dx = 0.0f;
	this->_dy = 0.0f;
	this->playAnimation(tank_constants::_idleAnimations[_direction]);
	// pause all sample playback
	Mix_Pause(2);
	this->playIddleSFX();

	if (Mix_Paused(5) == 1)
	{
		Mix_Resume(5);
	}
}

void Tank::shoot() 
{
	if (_firedBullet == nullptr) 
	{
		shouldShootBullet = true;
	}
	this->playShootingSFX();
}


void Tank::update(std::vector<Actor*> actors, int elapsedTime)
{
	Rectangle boundingBox = getBoundingBox();
	std::vector<Actor*> collisionRects = checkCollision(actors);

	if (boundingBox.collidesWithMap() || collisionRects.size() > 0)
	{
		handleCollisions(collisionRects);
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
		_firedBullet->update(actors, elapsedTime);
		if (_firedBullet->hasExploded())
		{
			delete _firedBullet;
			_firedBullet = nullptr;
		}
	}
	AnimatedActor::update(elapsedTime);
}

void Tank::handleCollisions(std::vector<Actor*> &collisions)
{
	_x = _prevX;
	_y = _prevY;
}

void Tank::onCollision(Actor* collidingActor)
{
	if (Bullet* bullet = dynamic_cast<Bullet*>(collidingActor))
	{
		_health_points--;
		if (_health_points <= 0)
		{
			playAnimation(tank_constants::_deathAnimation);
			playDeathSFX();
		}
	}
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