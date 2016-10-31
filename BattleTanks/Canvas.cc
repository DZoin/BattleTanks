#include "Canvas.h"
#include <SDL_image.h>

using namespace std;
//Holds all information dealing with graphics for the game

Canvas::Canvas(const string &title, int width, int height) : _title(title), _width(width), _height(height) 
{
	SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, _title.c_str());
}
Canvas::~Canvas()
{
	SDL_DestroyWindow(_window);
}

SDL_Surface* Canvas::loadImage(const std::string &filePath)
{
	if (_spriteSheets.count(filePath) == 0)  // File has not yet been loaded, cannot be found
	{
		_spriteSheets[filePath] = IMG_Load(filePath.c_str());
	}
	return _spriteSheets[filePath];
}

void Canvas::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle)
{
	SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);  //Copies whatever you pass it to the renderer
}

void Canvas::flip()
{
	SDL_RenderPresent(_renderer);
}

void Canvas::clear()
{
	SDL_RenderClear(_renderer);
}

SDL_Renderer* Canvas::getRenderer() const
{
	return _renderer;
}