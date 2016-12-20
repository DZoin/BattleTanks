#pragma once
#include "Canvas.h"
#include "Player.h"
#include "Level.h"
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
	void playMusic();

	Player _player;
	Player _player2;

	Level _level;
};