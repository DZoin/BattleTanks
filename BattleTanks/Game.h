#pragma once
#include "Tank.h"
#include "Canvas.h"
#define EXIT -1
class Game
{
public:
	Game();
	~Game();
	int gameLoop();
private:
	void draw(Canvas &graphics);
	void update(float elapsedTime);

	Tank _tank;
	Tank _tank2;
};