#pragma once
#include "Action.h"

class ShootAction : public Action
{
public:
	virtual void execute(Tank& tank);
};
