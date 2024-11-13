#pragma once
#include "Robot.h"

class Command
{
public:
	virtual void Execute(Robot& robot) = 0;
};

