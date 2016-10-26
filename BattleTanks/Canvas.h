#pragma once
#include <string>
#include <SDL.h>

class Canvas
{
public:
	Canvas(const std::string &title, int width, int height);
	~Canvas();
private:
	std::string _title;
	int _width;
	int _height;
	SDL_Window* _window;
	SDL_Renderer* _renderer;
};