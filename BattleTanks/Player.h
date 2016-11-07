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


class Player : public Actor
{
private:
	SDL_Scancode* _keybinds = new SDL_Scancode[5];
	Tank _tank;	
	std::list<std::pair<SDL_Scancode, Action*>> _actionList;

	void initializeActionList();
	Action* isMoving(Input input);
public:
	Player();
	Player(const Player& other);
	Player(SDL_Scancode* keybinds, Tank& tank);
	~Player();

	Player& operator=(const Player &other);
	void switchTank(Tank& tank);
	void draw(Canvas &canvas);
	void evaluateEvent(Input input, SDL_Event event);
};