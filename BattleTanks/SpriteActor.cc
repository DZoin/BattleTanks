#include "SpriteActor.h"

SpriteActor::SpriteActor(Canvas &canvas, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY) :
	Actor(canvas, filePath, sourceX, sourceY, width, height, posX, posY) 
{}

void SpriteActor::draw(Canvas &canvas) 
{
	Actor::draw(canvas);
}