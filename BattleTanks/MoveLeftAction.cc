#include "MoveLeftAction.h"

void MoveLeftAction::execute(Tank& tank)
{
	tank.stopMoving();
	tank.moveLeft();
}
