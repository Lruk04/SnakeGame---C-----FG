#pragma once
#include "BaseAgent.h"
class AIAgent : public BaseAgent
{

public:
    Direction GetNextDirection() override;
};

