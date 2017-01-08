#pragma once

#include "SpriteActor.h"
#include "Tank.h"
#include "Player.h"

class Canvas;

class HUD {
public:
	HUD();
	HUD(Canvas &canvas, Player &player, Player &player2);

	void update(int elapsedTime);
	void draw(Canvas &canvas);

protected:
	Player _player1;
	Player _player2;
	
	SpriteActor _healthBarSprite1;
	SpriteActor _healthBarSprite2;

	SpriteActor _currentHealthBar1;
	SpriteActor _currentHealthBar2;


};