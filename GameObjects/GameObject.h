#pragma once
#include "../Tools/SnakeGraphics.h"


class GameObject
{
private:
    
public:
    virtual ~GameObject() = default;
    virtual void Render(SnakeGraphics* graphics);
    virtual void Update();
    virtual void Destroy();
    
};
