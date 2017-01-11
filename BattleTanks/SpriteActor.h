#pragma once
#include "Action.h"
class SpriteActor : public Actor
{
public:
	SpriteActor() {}
	SpriteActor(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	void handleCollisions(std::vector<Actor*> &collisionRects) {}
	void onCollision(Actor* collidingActor) {}
	void draw(Canvas &canvas);
};