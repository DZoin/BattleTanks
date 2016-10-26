#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include <algorithm>
#include <string>
using namespace std;
/*	Game class
 *	Holds all information about the main game loop
 */
namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 5 * 1000 / FPS;
}

Game::Game()
{
	SDL_Init(SDL_INIT_EVERYTHING);
}
Game::~Game()
{

}
int Game::gameLoop()
{
	Canvas graphics("Battle Tanks", 800, 600);
	Input input;
	SDL_Event event;

	int LAST_UPDATE_TIME = SDL_GetTicks();

	while (true)
	{
		input.beginNewFrame();
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{
					input.keyDownEvent(event);
				}
			} 
			else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}
			else if (event.type == SDL_QUIT)
			{
				return EXIT;
			} 
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)
		{
			return EXIT;
		}
		const int CURRENT_TIME_MS = SDL_GetTicks();
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));

		LAST_UPDATE_TIME = CURRENT_TIME_MS;
	}
}
void Game::draw(Canvas &graphics)
{

}
void Game::update(float elapsedTime)
{

}