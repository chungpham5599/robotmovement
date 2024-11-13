#pragma once
#include "Command.h"

class LineToCommand : public Command
{
private:
	int x, y;
public:
	LineToCommand(int x, int y) : x(x), y(y) {}
	void Execute(Robot& robot) override;
};