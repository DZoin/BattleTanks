#pragma once
#include "Action.h"

class MoveLeftAction : public Action
{
public:
	virtual void execute(Tank& tank);
};
