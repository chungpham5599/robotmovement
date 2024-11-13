#pragma once
#include "Grid.h"

class Robot
{
private:
	int x, y;
public:
	Robot() : x(0), y(0) {}

	void MoveTo(int x, int y);
	void LineTo(int x, int y);
};