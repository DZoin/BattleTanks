#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include "GlobalActors.h"
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
	//Added by Ilko while splicing
	gameLoop();
}
Game::~Game()
{

}
int Game::gameLoop()
{
	Canvas canvas("Battle Tanks", 800, 600);
	Input input;
	SDL_Event event;
	

	auto tank = Tank(canvas, "Content/Sprites/tank.png", 50, 50, Direction::down);
	auto tank2 = Tank(canvas, "Content/Sprites/tank.png", 700, 500, Direction::up);
	_player = Player(globals::keybinds, tank);
	_player2 = Player(globals::player_2_keybinds, tank2);
	//globals::gameObjects = new vector<Actor*>();
	
	//globals::gameObjects->push_back(&tank);
	//globals::gameObjects->push_back(&tank2);

	_level = Level("Map1", Vector2(100, 100), canvas);
	_level.loadMap("Map1", canvas);
	
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
	//delete globals::gameObjects;
}
void Game::draw(Canvas &canvas)
{
	canvas.clear();
	_level.draw(canvas);

	_player.draw(canvas);
	_player2.draw(canvas);

	canvas.flip();
}
void Game::update(int elapsedTime)
{
	this->_player.update(_level, elapsedTime);
	this->_player2.update(_level, elapsedTime);
	_level.update(elapsedTime);
}