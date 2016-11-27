#include "Tile.h"
#include "Canvas.h"
#include <SDL.h>

Tile::Tile() {}

Tile::Tile(SDL_Texture* tileset, Vector2 size, Vector2 tilesetPosition, Vector2 position) : _tileset(tileset), _size(size), _tilesetPosition(tilesetPosition), _position(Vector2(position.x * globals::ACTOR_SCALE, position.y * globals::ACTOR_SCALE))
{

}

void Tile::update(int elapsedTime)
{

}

void Tile::draw(Canvas &canvas)
{
	// Where on the window should each tile be drawn
	SDL_Rect destRect = { _position.x, _position.y, _size.x * globals::ACTOR_SCALE, _size.y * globals::ACTOR_SCALE };

	SDL_Rect sourceRect = { _tilesetPosition.x, _tilesetPosition.y, _size.x, _size.y };

	canvas.blitSurface(_tileset, &sourceRect, &destRect);
}