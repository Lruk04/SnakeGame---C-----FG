#pragma once
#include "BaseAgent.h"
#include "../A Star/PathFinding.h"
#include "../GameObjects/GameObject.h"

class AIAgent : public BaseAgent
{
private:
    std::vector<Tile> path;

    bool doonce = false;

    int count = 0;

    Direction direction = Direction::NONE;
    
public:
    Snake* snake;

    AIAgent(int id, Snake* snake);
    
    Direction GetNextDirection() override;
    void KeyDown(int Key) override;

    void CalculatePath();
    
    PathFinding* pathFinding;
 
};

