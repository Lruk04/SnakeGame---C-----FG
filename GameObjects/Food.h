#pragma once
#include "../Tools/SnakeGraphics.h"
#include "GameObject.h"

class World;


class Food : public GameObject
{
private:
    int width, height;
    std::vector<std::pair<int, int>> positions;

    
public:
    void Init() override {};
    void Update() override {};
    void DestroyDerived() override {};
    void Render(SnakeGraphics* graphics) override;
    
    
    Food(World* game, int width, int height, int count);
    void Generate();
    std::vector<std::pair<int, int>>& GetPositions();
};
