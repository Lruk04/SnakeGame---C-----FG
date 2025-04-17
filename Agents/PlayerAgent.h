#pragma once
#include "BaseAgent.h"
#include <queue>

class PlayerAgent : public BaseAgent
{
    std::queue<Direction> m_nextDirections;

    int m_keyboardLayoutId;

    Direction nextDirection = Direction::NONE;

    Direction direction = Direction::RIGHT;

    bool directionChanged = false;

public:
    PlayerAgent(int keyboardLayoutId, int id);

    Direction GetNextDirection() override;

    void KeyDown(int Key) override;

    int GetKeyboardLayoutId() const;
};

