#pragma once

#include <list>
#include <utility>
#include "Actor.h"
#include "Tank.h"
#include "Input.h"
#include "Action.h"
#include "MoveUpAction.h"
#include "MoveDownAction.h"
#include "MoveRightAction.h"
#include "MoveLeftAction.h"
#include "StopAction.h"
#include "ShootAction.h"
#include "Level.h"


class Player
{
private:
	std::vector<SDL_Scancode> _keybinds;
	Tank* _tank;	
	std::list<std::pair<SDL_Scancode, Action*>> _actionList;
	void initializeActionList();
	int _maxHealthPlayer1;
	int _currentHealthPlayer1;

	int _maxHealthPlayer2;
	int _currentHealthPlayer2;
public:
	Player();
	Player(const Player& other);
	Player(const std::vector<SDL_Scancode>&, Tank& tank);
	~Player();
	
	void switchTank(Tank& tank);
	Tank& getTank() { return *_tank; }
	void draw(Canvas &canvas);
	void update(std::vector<Actor*> actors, int elapsedTime);
	void evaluateEvent(Input &input, SDL_Event event);
	const inline int getMaxHealthPlayer1() const { return _maxHealthPlayer1; }
	const inline int getCurrentHealthPlayer1() const { return _currentHealthPlayer1; }

	const inline int getMaxHealthPlayer2() const { return _maxHealthPlayer2; }
	const inline int getCurrentHealthPlayer2() const { return _currentHealthPlayer2; }
};