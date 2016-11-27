#include "StopAction.h"

void StopAction::execute(Tank& tank)
{
	tank.stopMoving();
}
