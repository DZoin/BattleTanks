#ifndef LEVEL_H
#define LEVEL_H
#include <string>
#include "Globals.h"
#include "Tile.h"
#include "Rectangle.h"
#include <vector>
#include <string>

class Canvas;
struct SDL_Texture;
struct SDL_Rect;
struct Tileset;

class Level
{
public:
	Level();
	Level(std::string mapName, Vector2 spawnPoint, Canvas &grphics);
	~Level();
	void update(int elapsedTime);
	void draw(Canvas &canvas);
	std::vector<Actor*>& getTileList() { return _tileList; }
	// Loads a map
	void loadMap(std::string mapName, Canvas &canvas);

private:
	std::string _mapName;
	Vector2 _spawnPoint;

	// The width and the hight of the entire map
	Vector2 _size;
	Vector2 _tileSize;

	SDL_Texture* _backgroundTexture;

	std::vector<Actor*> _tileList;
	std::vector<Tileset> _tilesets;

	// Returns a list of every collision rectangle we are colliding with(there might be more than 1 if we stand between two for example)
	std::vector<Rectangle> _collisionRects;
};

// Tileset structure
struct Tileset
{
	SDL_Texture* _texture;  // Tilest image
	std::string _filePath;  // Tilest image path
	int _firstGid;  // The first gid on the tileset

	Tileset()
	{
		_firstGid = -1;
	}

	Tileset(SDL_Texture* texture, std::string filePath, int firstGid)
	{
		_texture = texture;
		_filePath = filePath;
		_firstGid = firstGid;
	}
};

#endif