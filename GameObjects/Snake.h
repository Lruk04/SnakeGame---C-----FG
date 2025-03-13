#pragma once
#include <deque>
#include "../Tools/SnakeGraphics.h"
#include "GameObject.h"

enum Direction { UP, DOWN, LEFT, RIGHT };

class Snake
{
private:
    std::deque<std::pair<int, int>> body;
    bool grow;
    Direction direction;
    bool directionChanged;
    
    
public:
    Snake(int startX, int startY);
    void Move();
    void Grow();
    bool CheckCollision(int width , int height);
    bool CheckSelfCollision();
    void ChangeDirection(Direction newDirection);
    void Render(SnakeGraphics* graphics, int color, int color2, int color3);
    std::pair<int, int> GetPosition() const;
    const std::deque<std::pair<int, int>>& GetBody() const;
};
