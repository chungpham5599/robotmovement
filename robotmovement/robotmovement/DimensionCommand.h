#pragma once
#include "Command.h"

class DimensionCommand : public Command
{
private:
	int dimension;
public:
	DimensionCommand(int _dimension) : dimension(_dimension) {}
	void Execute(Robot& robot) override;
};