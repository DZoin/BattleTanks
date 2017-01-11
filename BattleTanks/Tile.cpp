#include "Tile.h"
#include "Canvas.h"
#include <SDL.h>

Tile::Tile():Actor() {}


Tile::Tile(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) : 
	Actor(canvas, filePath, sourceX, sourceY, width, height, posX, posY)
{}

void Tile::update()
{

}
void Tile::draw(Canvas &canvas)
{
	Actor::draw(canvas);
}
void Tile::handleCollisions(std::vector<Actor*> &collisionRects)
{

}

void Tile::onCollision(Actor* collidingActor)
{

}