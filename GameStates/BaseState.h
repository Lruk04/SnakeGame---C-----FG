#pragma once
#include "../Tools/SnakeGraphics.h"


class Snake;
class Food;

class BaseState
{
private:
   
public:
    virtual ~BaseState() = default;
    virtual bool Init() = 0;
    virtual void Render(SnakeGraphics* graphics) = 0;
    virtual void Update() = 0;
    virtual void KeyDown(int Key) = 0;
    virtual void CleanUp() = 0;

    static void StaticInit();
    static void StaticCleanUp();
};
