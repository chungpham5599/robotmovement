#include <iostream>
#include "Grid.h"

void Grid::FillCell(int x, int y)
{
    if (x >= 0 && x < size && y >= 0 && y < size) 
        grid[x][y] = '+';
}

void Grid::DrawLine(int x1, int y1, int x2, int y2)
{
    // Bresenham's Line Algorithm
    int dx = std::abs(x2 - x1), dy = std::abs(y2 - y1); // differences between x and y of the 2 endpoints
    int sx = (x1 < x2) ? 1 : -1, sy = (y1 < y2) ? 1 : -1; // direction of movement, 1 for up right, -1 for down left
    int err = dx - dy; // Initialize error term 

    while (true) { // loop and increment x1, y1 'til they reach x2, y2
        FillCell(x1, y1); // Mark the current point in the grid
        if (x1 == x2 && y1 == y2) break; // Break if we've reached the destination point
        int e2 = err * 2; // Calculate error term doubled
        if (e2 > -dy) { err -= dy; x1 += sx; } // Move in the x direction if necessary
        if (e2 < dx) { err += dx; y1 += sy; } // Move in the y direction if necessary
    }
}

void Grid::Display() const
{
    for (const auto& row : grid) {
        for (char cell : row) {
            std::cout << cell << ' ';
        }
        std::cout << '\n';
    }
}
