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
	std::vector<SDL_Scancode> _keybinds;
	Tank _tank;	
	std::list<std::pair<SDL_Scancode, Action*>> _actionList;
	void initializeActionList();
public:
	Player();
	Player(const Player& other);
	Player(const std::vector<SDL_Scancode>&, Tank& tank);
	~Player();

	//Added by Ilko when splicing
	void toPrev();

	//Added by Ilko when splicign start
	void handleTileCollisions(std::vector<Rectangle> &others);

	const Rectangle Player::getBoundingBox() const;

	const float getX() const;
	const float getY() const;
	//Added by Ilko when splicign end

	Player& operator=(const Player &other);
	void switchTank(Tank& tank);
	void draw(Canvas &canvas);
	void update(int elapsedTime);
	void evaluateEvent(Input &input, SDL_Event event);

protected:
	//Added by Ilko when splicing
	float prevX, prevY;
};