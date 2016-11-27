#pragma once
#include <vector>

namespace globals
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	const float ACTOR_SCALE = 2.5f;	
	const std::vector<SDL_Scancode> keybinds = { SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE };
	const std::vector<SDL_Scancode> player_2_keybinds = { SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D, SDL_SCANCODE_F };
}

namespace Direction
{
	enum Value { up, down, left, right };
}

struct Vector2
{
	int x, y;
	Vector2() : x(0), y(0) {}  //Default constructor
	Vector2(int x, int y) : x(x), y(y) {}

	//Helper function, makes more sense to call the function rather than the empty constructor
	Vector2 zero()
	{
		return Vector2(0, 0);
	}
};