#pragma once
#include "Action.h"

class MoveDownAction : public Action
{
public:
	virtual void execute(Tank& tank);
};

