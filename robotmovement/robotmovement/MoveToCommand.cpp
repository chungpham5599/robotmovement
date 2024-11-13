#include "MoveToCommand.h"

void MoveToCommand::Execute(Robot& robot)
{
	robot.MoveTo(x, y);
}
