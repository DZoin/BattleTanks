#include "Player.h"
#include "Utils.h"

Player::Player()
{
	initializeActionList();
}

Player::Player(const Player& other) : _keybinds(other._keybinds), _tank(other._tank), _actionList(other._actionList)
{

}

Player::Player(const std::vector<SDL_Scancode> &keybinds, Tank& tank) : _keybinds(keybinds), _tank(&tank), _maxHealthPlayer1(100), _currentHealthPlayer1(50), _maxHealthPlayer2(100), _currentHealthPlayer2(20)
{	
	initializeActionList();
}

Player::~Player()
{
	
}

void Player::initializeActionList()
{
	for (int i = 0; i < _keybinds.size(); ++i)
	{
		switch (i)
		{
		case 0:
			{
				_actionList.emplace_back(_keybinds[i], new MoveUpAction());
				break;
			}
		case 1:
			{
				_actionList.emplace_back(_keybinds[i], new MoveDownAction());
				break;
			}
		case 2:
		{
				_actionList.emplace_back(_keybinds[i], new MoveLeftAction());
				break;
		}
		case 3:
			{
				_actionList.emplace_back(_keybinds[i], new MoveRightAction());
				break;
			}
		case 4:
			{
				_actionList.emplace_back(_keybinds[i], new ShootAction());
				break;
			}
		}
	}
}
void Player::switchTank(Tank& tank) {
	delete &(this->_tank);
	this->_tank = &tank;
}

void Player::evaluateEvent(Input &input, SDL_Event event)
{
	SDL_Scancode scancode = event.key.keysym.scancode;
	for (int i = 0; i < _keybinds.size(); ++i)
	{
		if (_keybinds[i] == scancode)
		{
			Action* action;
			if (event.type == SDL_KEYDOWN)
			{
				if (event.key.repeat == 0)
				{ //key.repeat == 0 -> makes sure that you are not holding down a key
					input.keyDownEvent(event);
				}
			
			} else if (event.type == SDL_KEYUP)
			{
				input.keyUpEvent(event);
			}

			if (input.isKeyHeld(scancode))
			{
				auto it = utils::find(_actionList.begin(), _actionList.end(), scancode);
				action = it->second;
				action->execute(*_tank);
			}
			else if (!input.hasPressedKeys(_keybinds))
			{
				action = new StopAction();
				action->execute(*_tank);
			}
			
			break;
		}
	}
 }

void Player::update(std::vector<Actor*> actors, int elapsedTime)
{
	_tank->update(actors, elapsedTime);
}

void Player::draw(Canvas &canvas)
{
 	_tank->draw(canvas);
}
