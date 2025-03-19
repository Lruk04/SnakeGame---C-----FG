#pragma once
#include "BaseAgent.h"
#include <queue>

class PlayerAgent : public BaseAgent
{
    std::queue<Direction> m_nextDirections;

    int m_keyboardLayoutId;

public:
    PlayerAgent(int keyboardLayoutId);

    Direction GetNextDirection() override;

    void KeyDown(int Key) override;
};

