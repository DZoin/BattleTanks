#include "MoveRightAction.h"

void MoveRightAction::execute(Tank& tank)
{
	tank.stopMoving();
	tank.moveRight();
}
