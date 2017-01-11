#pragma once
#include "Actor.h"
#include "Globals.h"
struct SDL_Texture;
class Canvas;

class Tile : public Actor
{
public:
	Tile();
	Tile(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY);
	virtual void update();
	virtual void draw(Canvas &canvas);
	virtual void Tile::handleCollisions(std::vector<Actor*> &collisionRects);
	virtual void handleCollision(Actor* collidingActor) {}
	virtual void onCollision(Actor* collidingActor);
};

