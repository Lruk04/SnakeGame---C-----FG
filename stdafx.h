#pragma once
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#endif



class SnakeGraphics;

constexpr int SCREEN_WIDTH = 30;
constexpr int SCREEN_HEIGHT = 15;

enum Direction
{
    NONE = 0, UP = 1, DOWN = -1, LEFT = -2, RIGHT = 2
};


#include <iostream>
#include <vector>




