#pragma once
#include "Action.h"

class MoveUpAction : public Action
{
public:
	virtual void execute(Tank& tank);
};