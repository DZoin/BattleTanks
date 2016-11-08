#include "MoveUpAction.h"

void MoveUpAction::execute(Tank& tank)
{
	tank.stopMoving();
	tank.moveUp();
}
