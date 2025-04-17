#pragma once
#include "../stdafx.h"

class BaseAgent
{
private:

    
public:
    int ID;

    BaseAgent(int id) : ID(id) {}
    
    virtual ~BaseAgent() = default;
    virtual Direction GetNextDirection() = 0;

    virtual void KeyDown(int Key) = 0;
};