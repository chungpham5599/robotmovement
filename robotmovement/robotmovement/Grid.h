#pragma once
#include <vector>

class Grid
{
private:
	int size;
	std::vector<std::vector<char>> grid;
public:
	Grid(int size) : size(size), grid(size, std::vector<char>(size, ' ')) {}
	
	void FillCell(int x, int y);
	void Display();

};