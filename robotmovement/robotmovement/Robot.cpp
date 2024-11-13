#include "Robot.h"

void Robot::MoveTo(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Robot::LineTo(int _x, int _y)
{
	grid.DrawLine(x, y, _x, _y);
	MoveTo(_x, _y);
}
