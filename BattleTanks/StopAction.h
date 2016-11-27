#pragma once
#include "Action.h"

class StopAction : public Action
{
public:
	virtual void execute(Tank& tank);
};
