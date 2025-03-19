#pragma once
class BaseAgent
{
public:
    enum class Direction
    {
        None = -1,
        Up = 0,
        Right = 1,
        Down = 2,
        Left = 3
    };

    virtual Direction GetNextDirection() = 0;

    virtual void KeyDown(int Key) {};
};