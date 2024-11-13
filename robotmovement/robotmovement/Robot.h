#pragma once
#include "Grid.h"

class Robot
{
private:
	Grid& grid;
	int x, y;
public:
	Robot(Grid& grid) : grid(grid), x(0), y(0) {}

	void MoveTo(int x, int y);
	void LineTo(int x, int y);
};