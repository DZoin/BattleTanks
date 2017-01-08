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
	Tank _tank;	
	std::list<std::pair<SDL_Scancode, Action*>> _actionList;
	void initializeActionList();
public:
	Player();
	Player(const Player& other);
	Player(const std::vector<SDL_Scancode>&, Tank& tank);
	~Player();
	
	void switchTank(Tank& tank);
	Tank getTank();
	void draw(Canvas &canvas);
	void update(Level &level, int elapsedTime);
	void evaluateEvent(Input &input, SDL_Event event);
};