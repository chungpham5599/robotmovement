#pragma once
#include <vector>

class Grid
{
private:
	int size;
	std::vector<std::vector<char>> grid;
public:
	Grid(int size) : size(size), grid(size, std::vector<char>(size, ' ')) {}
	
	void FillCell(int _x, int _y);
	void DrawLine(int x1, int y1, int x2, int y2);
	void Display() const;

};