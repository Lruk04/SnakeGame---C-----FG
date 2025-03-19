#pragma once
#include "../Tools/SnakeGraphics.h"

class Food 
{
private:
    int width, height;
    std::vector<std::pair<int, int>> positions;
public:
    Food(int width, int height, int count);
    void Generate();
    void Render(SnakeGraphics* graphics);
    std::vector<std::pair<int, int>>& GetPositions();
};
