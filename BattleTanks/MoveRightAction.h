#pragma once
#include "Action.h"

class MoveRightAction : public Action
{
public:
	virtual void execute(Tank& tank);
};
