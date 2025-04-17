#pragma once
#include <deque>
#include "GameObject.h"
#include "../Agents/BaseAgent.h"
#include "../Tools/SnakeGraphics.h"

class PlayState;

class Snake : public GameObject {
private:
    BaseAgent* m_baseAgent = nullptr;
    std::deque<std::pair<int, int>> body;

    //Direction direction;
    
    bool grow;
    bool directionChanged;
    int color, color2, color3;

public:
    Snake(World* game, BaseAgent* baseAgent, int startX, int startY, int color, int color2, int color3);

    void Init() override;
    void Update() override;
    void Render(SnakeGraphics* graphics) override;
    void DestroyDerived() override;

    void Move();
    void Grow();
    bool CheckCollision(int width, int height);
    bool CheckSelfCollision();
    //void ChangeDirection(Direction newDirection);
    std::pair<int, int> GetPosition() const;
    const std::deque<std::pair<int, int>>& GetBody() const;
};