#pragma once

#include "Actor.h"
#include "Tank.h"
#include "Player.h"

class Canvas;

class HUD {
public:
	HUD();
	HUD(Canvas &canvas, Player &player);

	void update(int elapsedTime);
	void draw(Canvas &canvas);

protected:
	Player _player1;
	Player _player2;
	
	Actor _healthBarSprite1;
	Actor _healthBarSprite2;

	Actor _currentHealthBar1;
	Actor _currentHealthBar2;


};