#pragma once
#include "Command.h"

class MoveToCommand : public Command
{
private:
	int x, y;
public:
	MoveToCommand(int x, int y) : x(x), y(y) {}
	void Execute(Robot& robot) override;
};