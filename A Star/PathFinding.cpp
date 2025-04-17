#include "PathFinding.h"

#include "../World.h"


std::vector<Tile> PathFinding::FindPath(Tile start, Tile goal, Direction direction)
{

    std::cout << "FIND PATH FIND PATH" << std::endl;
    std::cout << "FIND PATH FIND PATH" << std::endl;
    std::cout << "FIND PATH FIND PATH" << std::endl;
    std::cout << "FIND PATH FIND PATH" << std::endl;
    
    
    for (auto& tile : World::grid-> GetTileList())
    {
        tile->parent = nullptr;
        tile->gCost = 0;
        tile->hCost = 0;
        tile->fCost = start.gCost + start.hCost;
    }
   
    
    start.parent = nullptr;
    start.gCost = 0;
    start.hCost = GetDistance(start, goal);
    start.fCost = start.gCost + start.hCost;

    std::vector<Tile*> openList;
    std::vector<Tile*> closedList;

    openList.push_back(&start);

    

    FirstPathing = true;

    while (!openList.empty())
    {
        Tile* currentTile = openList[0];

        if (*currentTile == goal)
        {
            std::cout << "Found path" << std::endl;
            RetracePath(currentTile);
            return EndPath;
        }

        openList.erase(openList.begin());
        closedList.push_back(currentTile);

        for (Tile& neighbour : FindNeighbours(direction, *currentTile))
        {
            if (std::find_if(closedList.begin(), closedList.end(),
                             [&neighbour](Tile* tile) { return *tile == neighbour; }) != closedList.end() || neighbour.
                IsOccupied() || neighbour.IsSnake())
            {
                continue;
            }

            int newCost = currentTile->gCost + GetDistance(*currentTile, neighbour);

            if (newCost < neighbour.gCost || std::find_if(openList.begin(), openList.end(), [&neighbour](Tile* tile){return *tile == neighbour;}) == openList.end())
            {
                neighbour.gCost = newCost;
                neighbour.hCost = GetDistance(neighbour, goal);
                neighbour.fCost = neighbour.gCost + neighbour.hCost;
                neighbour.parent = currentTile;

               
                Tile* neighbourPtr = new Tile(neighbour);

                if (std::find_if(openList.begin(), openList.end(),
                                 [&neighbour](Tile* tile) { return *tile == neighbour; }) == openList.end())
                {
                    openList.push_back(neighbourPtr);
                }
            }
        }
    }
   
    std::cout << "Failure: no path found" << std::endl;
    return std::vector<Tile>();
}

void PathFinding::RetracePath(Tile* current)
{
    std::vector<Tile> path;

    while (current != nullptr)
    {
        path.push_back(*current);
        current = current->parent;
    }

    std::reverse(path.begin(), path.end());
    EndPath = path;
}

std::vector<Tile> PathFinding::FindNeighbours(Direction direction, Tile currentTile)
{
    std::vector<Tile> neighbours;

    std::vector<std::pair<int, int>> directions;


    //directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    if (FirstPathing)
    {
        directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    }
    else
    {
        switch (direction)
        {
        case DOWN:
            directions = {{0, 1}, {1, 0}, {-1, 0}};
            break;
        case LEFT:
            directions = {{-1, 0}, {0, 1}, {0, -1}};
            break;
        case UP:
            directions = {{0, -1}, {1, 0}, {-1, 0},};
            break;
        case RIGHT:
            directions = {{0, 1}, {1, 0}, {0, -1}};
            break;
        case NONE:
            break;
        default: break;
        }
    }

    for (const auto& dir : directions)
    {
        // if(FirstPathing)
        // {
        //     if (!CheckTile(dir.first, dir.second, currentTile))
        //     {
        //         FirstPathing = false;
        //         neighbours.push_back(World::grid->GetTile(currentTile.GetX() + dir.first, currentTile.GetY() + dir.second));
        //     }
        // }
        // else

        neighbours.push_back(World::grid->GetTile(currentTile.GetX() + dir.first, currentTile.GetY() + dir.second));
    }
    return neighbours;
}


bool PathFinding::CheckTile(int x, int y, Tile currentTile)
{
    if (World::grid->GetTile(currentTile.GetX() + x, currentTile.GetY() + y).IsOccupied() || World::grid->
        GetTile(currentTile.GetX() + x, currentTile.GetY() + y).IsSnake() || World::grid->GetTile(
            currentTile.GetX() + x, currentTile.GetY() + y).IsFood())
    {
        return true;
    }
    return false;
}

int PathFinding::GetDistance(Tile a, Tile b)
{
    return abs(a.GetX() - b.GetX()) + abs(a.GetY() - b.GetY());
}
