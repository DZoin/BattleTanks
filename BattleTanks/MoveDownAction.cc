#include "MoveDownAction.h"


void MoveDownAction::execute(Tank& tank)
{
	tank.stopMoving();
	tank.moveDown();
}
