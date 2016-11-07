#pragma once

namespace globals
{
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	const float ACTOR_SCALE = 2.0f;	
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