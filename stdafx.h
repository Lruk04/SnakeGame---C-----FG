#pragma once
#ifdef _DEBUG
#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )

#endif
#include "GameStates/StateMachine.h"


class SnakeGraphics;

constexpr int SCREEN_WIDTH = 30;
constexpr int SCREEN_HEIGHT = 15;

