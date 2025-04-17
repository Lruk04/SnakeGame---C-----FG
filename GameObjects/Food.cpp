#include "Food.h"
#include <ctime>

Food::Food(World* game,int width, int height, int count) : GameObject(game), width(width), height(height)
{
    std::srand(std::time(nullptr));
    positions.resize(count);
    Generate();
}

void Food::Generate()
{
    for (auto& position : positions)
    {
        Tile& randomTile = World::grid->GetRandomUnoccupiedTile();

        World::grid->SetTileFood(randomTile.GetX(), randomTile.GetY(),true);
        
        position.first = randomTile.GetX();
        position.second = randomTile.GetY();
        
        // position.first = 1 + rand() % (width - 2); 
        // position.second = 1 + rand() % (height - 2); 
    }
}

void Food::Render(SnakeGraphics* graphics)
{
    // Render each food
    for (const auto& position : positions)
    {
        graphics->PlotTile(position.first, position.second, 0, Color(255, 0, 0), Color(255, 0, 0), ' ');
    }
}

std::vector<std::pair<int, int>>& Food::GetPositions()
{
    return positions;
}