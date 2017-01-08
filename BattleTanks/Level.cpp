#include "Level.h"
#include "Canvas.h"
#include <SDL.h>
#include "Globals.h"
#include "tinyxml2.h"
#include <sstream>
#include <algorithm>
#include <cmath>

using namespace tinyxml2;

Level::Level() {}

Level::Level(std::string mapName, Vector2 spawnPoint, Canvas &canvas) : _mapName(mapName), _spawnPoint(spawnPoint), _size(Vector2(0,0))
{
}

Level::~Level() {}

void Level::loadMap(std::string mapName, Canvas &canvas)
{
	// Parse the .tmx file
	XMLDocument doc;
	std::stringstream ss;
	ss << "Content/Maps/" << mapName << ".tmx";  // Pass in Map1, we get Content/Maps/Map1.tmx
	doc.LoadFile(ss.str().c_str());

	XMLElement* mapNode = doc.FirstChildElement("map");  // doc is the root of our xml document

	// Get th width and the height of the whole map and sotre it in _size
	int width, height;
	mapNode->QueryIntAttribute("width", &width);
	mapNode->QueryIntAttribute("height", &height);
	_size = Vector2(width, height);  // We now have the size of our map

	// Get the width and height of the tiles and store it in _tileset
	int tileWidth, tileHeight;
	mapNode->QueryIntAttribute("tilewidth", &tileWidth);
	mapNode->QueryIntAttribute("tileheight", &tileHeight);
	_tileSize = Vector2(tileWidth, tileHeight);  // We now have the size of our tiles

	// Loading the tileset
	XMLElement* pTileset = mapNode->FirstChildElement("tileset");
	if (pTileset != NULL)
	{
		while (pTileset)
		{
			int firstGid = 0;
			const char* source = pTileset->FirstChildElement("image")->Attribute("source");
			char* path;
			std::stringstream ss;
			ss << source;
			pTileset->QueryIntAttribute("firstgid", &firstGid);
			SDL_Texture* tex = SDL_CreateTextureFromSurface(canvas.getRenderer(), canvas.loadImage(ss.str()));
			_tilesets.push_back(Tileset(tex, ss.str(), firstGid));
			pTileset = pTileset->NextSiblingElement("tileset");
		}
	}

	// Loading the layers
	XMLElement* pLayer = mapNode->FirstChildElement("layer");
	if (pLayer != NULL)
	{
		while (pLayer)
		{
			// Loading the data element
			XMLElement* pData = pLayer->FirstChildElement("data");
			if (pData != NULL)
			{
				//Loading the tile element
				XMLElement* pTile = pData->FirstChildElement("tile");
				if (pTile != NULL)
				{
					int tileCounter = 0;
					while (pTile)
					{
						// Build each individual tile here
						// If gid is 0, no tile should be drawn. Continue loop
						if (pTile->IntAttribute("gid") == 0)
						{
							tileCounter++;
							if (pTile->NextSiblingElement("tile"))
							{
								pTile = pTile->NextSiblingElement("tile");
								continue;
							}
							else
							{
								break;
							}
						}

						// Get the tielset for this specific gid
						int gid = pTile->IntAttribute("gid");
						Tileset tls;
						for (int i = 0; i < _tilesets.size(); i++)
						{
							if (_tilesets[i]._firstGid <= gid)
							{
								// This is the tileset we want
								tls = _tilesets.at(i);
								break;
							}
						}

						if (tls._firstGid == -1)
						{
							// No tileset was found for this gid
							tileCounter++;
							if (pTile->NextSiblingElement("tile"))
							{
								pTile = pTile->NextSiblingElement("tile");
								continue;
							}
							else
							{
								break;
							}
						}

						// Get the position of the tile in the level
						int xx = 0;
						int yy = 0;
						xx = tileCounter % width;
						xx *= tileWidth * globals::ACTOR_SCALE;

						yy += tileHeight * (tileCounter / width) * globals::ACTOR_SCALE;

						//Calculate the position of the tile in the tileset
						int tilesetWidth, tilesetHegiht;
						SDL_QueryTexture(tls._texture, NULL, NULL, &tilesetWidth, &tilesetHegiht);
						int amnt = (gid / (tilesetWidth / tileWidth));

						int tsxx = gid % (tilesetWidth / tileWidth) - 1;
						tsxx *= tileWidth;
						int tsyy = 0;
						tsyy = tileHeight * amnt;

						// Build the actual tile and add it to the evel's tile list
						Tile *tile = new Tile(canvas, tls._filePath, tsxx, tsyy, tileWidth, tileHeight, xx, yy);
						_tileList.push_back(tile);
						tileCounter++;

						pTile = pTile->NextSiblingElement("tile");
					}
				}

				pData = pData->NextSiblingElement("data");
			}

			pLayer = pLayer->NextSiblingElement("layer");
		}
	}

	//// Parse out the collisions
	//XMLElement* pObjectGroup = mapNode->FirstChildElement("objectgroup");
	//if (pObjectGroup != NULL)
	//{
	//	while (pObjectGroup)
	//	{
	//		const char* name = pObjectGroup->Attribute("name");
	//		std::stringstream ss;
	//		ss << name;
	//		if (ss.str() == "Collisions")
	//		{
	//			XMLElement* pObject = pObjectGroup->FirstChildElement("object");
	//			if (pObject != NULL)
	//			{
	//				while (pObject)
	//				{
	//					float x, y, width, height;
	//					x = pObject->FloatAttribute("x");
	//					y = pObject->FloatAttribute("y");
	//					width = pObject->FloatAttribute("width");
	//					height = pObject->FloatAttribute("height");
	//					_collisionRects.push_back(Rectangle(
	//						std::ceil(x) * globals::ACTOR_SCALE,
	//						std::ceil(y) * globals::ACTOR_SCALE,
	//						std::ceil(width) * globals::ACTOR_SCALE,
	//						std::ceil(height) * globals::ACTOR_SCALE
	//						));

	//					pObject = pObject->NextSiblingElement("object");
	//				}
	//			}
	//		}
	//		// Other objectgroups go here with an else if(ss.str() == "whatever")


	//		pObjectGroup = pObjectGroup->NextSiblingElement("objectgroup");
	//	}
	//}
}

void Level::update(int elapsedTime)
{

}

void Level::draw(Canvas &canvas)
{
	for (int i = 0; i < _tileList.size(); i++)
	{
		_tileList.at(i)->draw(canvas);
	}
}



