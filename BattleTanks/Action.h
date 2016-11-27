#pragma once;
#include "Tank.h"
class Action
{
public:
	virtual ~Action() {}
	virtual void execute(Tank& tank) = 0;
};