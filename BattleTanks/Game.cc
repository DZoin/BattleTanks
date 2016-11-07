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
	Canvas canvas("Battle Tanks", 800, 600);
	Input input;
	SDL_Event event;
	SDL_Scancode* keybinds =
		new SDL_Scancode[] { SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT, SDL_SCANCODE_SPACE };

	_player = Player(keybinds, Tank(canvas, "Content/Sprites/tank.png", 100, 100, Direction::down));

	int LAST_UPDATE_TIME = SDL_GetTicks();  //SDL_GetTick -> gets the number of milliseconds since the SDL libraly was initialized

	while (true)
	{
		input.beginNewFrame();  //resets pressed keys and released keys at the beginning of every frame

		if (SDL_PollEvent(&event))
		{
			
			if (event.type == SDL_QUIT)
			{
				return EXIT;
			}
			else 
			{
				_player.evaluateEvent(input, event);
				_player2.evaluateEvent(input, event);
			}
		}
		if (input.wasKeyPressed(SDL_SCANCODE_ESCAPE) == true)  //if ESC button is pressed, quit the game
		{
			return EXIT;
		}
		const int CURRENT_TIME_MS = SDL_GetTicks();  //Holds the millisecond value that took for the gameloop to complete
		int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;  //How long this current frame took
		update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));  //If this frame took less than our maximum time, we are going to use that time. If it took more than that, use our maximum time.
															//It can't go higher than 50 FPS

		LAST_UPDATE_TIME = CURRENT_TIME_MS;  //Start the initialization again, before the loop begins a new cicle
		draw(canvas);
	}
}
void Game::draw(Canvas &canvas)
{
	canvas.clear();

	_player.draw(canvas);

	canvas.flip();
}
void Game::update(int elapsedTime)
{

}