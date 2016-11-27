#pragma once
#include "Actor.h"
//#include <SDL.h>
#include "Globals.h"
struct SDL_Texture;
class Canvas;

class Tile
{
public:
	Tile();
	Tile(SDL_Texture* tileSet, Vector2 size, Vector2 tilesetPosition, Vector2 position);
	void update(int elapsedTime);
	void draw(Canvas &canvas);
	//~Tile();

private:
	SDL_Texture* _tileset;
	Vector2 _size;  // The size of the tile
	Vector2 _tilesetPosition;  // Where on the tileset the tile is
	Vector2 _position;  // Where on the map the tile is
};

