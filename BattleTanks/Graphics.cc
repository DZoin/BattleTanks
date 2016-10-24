#include "Graphics.h"

using namespace std;
//Holds all information dealing with graphics for the game

Graphics::Graphics(const string &title, int width, int height) : _title(title), _width(width), _height(height) 
{
	SDL_CreateWindowAndRenderer(_width, _height, 0, &_window, &_renderer);
	SDL_SetWindowTitle(_window, _title.c_str());
}
Graphics::~Graphics()
{
	SDL_DestroyWindow(_window);
}