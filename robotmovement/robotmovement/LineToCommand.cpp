#include "LineToCommand.h"

void LineToCommand::Execute(Robot& robot)
{
	robot.LineTo(x, y);
}
