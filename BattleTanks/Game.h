#pragma once
#include "Canvas.h"
#include "Player.h"
#include "Level.h"
#include "HUD.h"
#define EXIT -1
class Game
{
public:
	Game();
	~Game();
	int startGame();
private:
	void draw(Canvas &graphics);
	void update(int elapsedTime);
	void playMusic();
	void playDeathSFX();
	int gameLoop();

	Player _player;
	Player _player2;
	bool retry = true;

	Level _level;

	HUD _hud;
};