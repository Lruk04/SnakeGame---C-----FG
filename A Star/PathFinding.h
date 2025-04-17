#pragma once
#include <vector>
#include <iostream>
#include "Grid.h"
#include "../stdafx.h"

class PathFinding
{
private:
    std::vector<Tile> EndPath;
    bool FirstPathing = true;
    
public:
   
    
    std::vector<Tile> FindPath(Tile start, Tile goal, Direction direction);

    void RetracePath(Tile* current);
    
    int GetDistance(Tile a, Tile b);

    std::vector<Tile> FindNeighbours(Direction direction, Tile currentTile);

    bool CheckTile(int x, int y, Tile currentTile);
   
};
