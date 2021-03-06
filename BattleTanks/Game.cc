#include <SDL.h>
#include "Game.h"
#include "Input.h"
#include "GlobalActors.h"
#include <algorithm>
#include <string>
#include <SDL_mixer.h>
using namespace std;
/*	Game class
 *	Holds all information about the main game loop
 */
namespace
{
	const int FPS = 50;
	const int MAX_FRAME_TIME = 1000 / FPS;
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

	_level = Level("Map1", Vector2(100, 100), canvas);
	_level.loadMap("Map1", canvas);

	auto tank = Tank(canvas, "Content/Sprites/tankYellow.png", 700, 500, Direction::left);
	auto tank2 = Tank(canvas, "Content/Sprites/tankGreen.png", 50, 70, Direction::right);
	_player = Player(globals::keybinds, tank);
	_player2 = Player(globals::player_2_keybinds, tank2);
	
	globals::gameObjects = new vector<Actor*>();
	
	globals::gameObjects->push_back(&tank);
	globals::gameObjects->push_back(&tank2);
	for (auto tile : _level.getTileList())
	{
		globals::gameObjects->push_back(tile);
	}


	int LAST_UPDATE_TIME = SDL_GetTicks();  //SDL_GetTick -> gets the number of milliseconds since the SDL libraly was initialized

	
	playMusic();

	while (true)
	{
		input.beginNewFrame();  //resets pressed keys and released keys at the beginning of every frame

		if (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				return EXIT;
			}



			if (_player.getTank().isDestoryed() || _player2.getTank().isDestoryed())
			{
				if (event.key.keysym.scancode == SDL_SCANCODE_R)
				{
					retry = true;
					break;
				}
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
	
	delete globals::gameObjects;
}

int Game::startGame()
{
	int result = 0;
	while (retry)
	{
		retry = false;
		result = gameLoop();
	}
	return result;
}


void Game::draw(Canvas &canvas)
{
	canvas.clear();
	_level.draw(canvas);

	_player.draw(canvas);
	_player2.draw(canvas);

//	_hud.draw(canvas);

	canvas.flip();
}
void Game::update(int elapsedTime)
{
	this->_player.update(*globals::gameObjects, elapsedTime);
	this->_player2.update(*globals::gameObjects, elapsedTime);
	_level.update(elapsedTime);

//	_hud.update(elapsedTime);

}

void Game::playMusic()
{
	//open 44.1KHz, signed 16bit, system byte order,

	//stereo audio, using 1024 byte chunks

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {

		printf("Mix_OpenAudio: %s\n", Mix_GetError());
	}


		//Declaring and loading of background music OGG type, note mp3 does not work

		// load the MP3 file "music.mp3" to play as music

		Mix_Music *music;

		music = Mix_LoadMUS("Content/BackgroundMusic/backgroundMusic.ogg");

		if (!music)
		{
			printf("Mix_LoadMUS(\"backgroundMusic.mp3\"): %s\n", Mix_GetError());

		}

		//End of OGG loading

		//Setting the background music volume - MAX is 128

		// set the music volume to 1/2 maximum, and then check it

		printf("volume was    : %d\n", Mix_VolumeMusic(MIX_MAX_VOLUME / 8));

		printf("volume is now : %d\n", Mix_VolumeMusic(-1));

		//End of setting background music volume

		//Playing music forever

		// play music forever

		// Mix_Music *music; // I assume this has been loaded already

		if (Mix_PlayMusic(music, 1) == -1) {

			printf("Mix_PlayMusic: %s\n", Mix_GetError());

			// well, there's no music, but most games don't break without music...
		}
		//End of playing music


	}

