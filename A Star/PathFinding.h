#pragma once
#include "Grid.h"
#include "../GameObjects/Snake.h"

// Functions that are needed
// Find Neightbours up, down, left, right, with the oppsite direction being locked

class PathFinding
{
private:
    
    
public:
    void FindNeighbours(Direction direction, Grid::Tile currentTile);
};
