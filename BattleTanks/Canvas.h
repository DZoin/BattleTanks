#pragma once
#include <string>
#include <SDL.h>
#include <map>

class Canvas
{
public:
	Canvas(const std::string &title, int width, int height);
	~Canvas();

	/* SDL_Surface* loadImage
	Loads an image into the _spriteSheets map if it doesn't already exist
	As a result each image will only ever be loaded once
	Returns image from the map regardless of wheter or not it was just loaded
	*/
	SDL_Surface* loadImage(const std::string &filePath);

	/* void blitSurface
	Draws a texture to a certain part of the screen
	*/
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	
	/* void flip
	Renders everything to the screen
	*/
	void flip();

	/* void clear
	Clears the sreen
	*/
	void clear();

	/* SDL_Renderer getRenderer
	Returns the renderer
	*/
	SDL_Renderer* getRenderer() const;
private:
	std::string _title;
	int _width;
	int _height;
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	// This map variable is going to hold in memory in our graphics object every sprite sheet we have loaded into the game
	std::map<std::string, SDL_Surface*> _spriteSheets;
};