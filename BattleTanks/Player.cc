#include "Player.h"
#include "Utils.h"

Player::Player()
{
	initializeActionList();
}

Player::Player(const Player& other) : _keybinds(other._keybinds), _tank(other._tank), _actionList(other._actionList)
{

}

Player& Player::operator=(const Player &other)
{
	this->_actionList = other._actionList;
	this->_keybinds = other._keybinds;
	this->_sourceRect = other._sourceRect;
	this->_spriteSheet = other._spriteSheet;
	this->_tank = other._tank;
	this->_x = other._x;
	this->_y = other._y;
	return *this;
}

Player::Player(SDL_Scancode* keybinds, Tank& tank) : _keybinds(keybinds), _tank(tank) 
{	
	initializeActionList();
}

Player::~Player()
{
	delete _keybinds;
}

void Player::initializeActionList()
{
	for (int i = 0; i < sizeof(_keybinds) / sizeof(*_keybinds); ++i)
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
	this->_tank = tank;
}

void Player::evaluateEvent(Input input, SDL_Event event)
{
	Action *action = this->isMoving(input);
	
	if (action != nullptr) {
		SDL_Scancode scancode = event.key.keysym.scancode;
		for (int i = 0; i < sizeof(_keybinds) / sizeof(*_keybinds); ++i)
		{
			if (_keybinds[i] == scancode)
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.repeat == 0)  //key.repeat == 0 -> makes sure that you are not holding down a key
					{
						input.keyDownEvent(event);
					}
				}
				else if (event.type == SDL_KEYUP)
				{
					input.keyUpEvent(event);
				}
				auto it = std::find(_actionList.begin(), _actionList.end(), scancode);
				action = it->second;
			}
			action = new StopAction();
		}
	}
	action->execute(_tank);
}
Action* Player::isMoving(Input input)
{
	for (int i = 0; i < 4; ++i)
	{
		if (input.isKeyHeld(_keybinds[i]))
		{
			auto it = utils::find(_actionList.begin(), _actionList.end(), _keybinds[i]);
			return it->second;
		}
	}
	return nullptr;
}