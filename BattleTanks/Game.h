#pragma once
#include "Canvas.h"
#include "Player.h"
#define EXIT -1
class Game
{
public:
	Game();
	~Game();
	int gameLoop();
private:
	void draw(Canvas &graphics);
	void update(int elapsedTime);

	Player _player;
	Player _player2;
};