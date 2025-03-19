#include "StateMachine.h"
#include <iostream>

StateMachine* StateMachine::instance = nullptr;

StateMachine::StateMachine()
{
    m_menuState = new MenuState();
    m_playState = new PlayState();
    
    m_states["Menu"] = m_menuState;
    m_states["Play"] = m_playState;
    
    instance = this; 
}



void StateMachine::changeState(const std::string& name)
{
    if (instance->m_currentState != nullptr)
    {
        instance->m_currentState->CleanUp();
    }

    auto it = instance->m_states.find(name);
    if (it != instance->m_states.end())
    {
        instance->m_currentState = it->second;
        instance->m_currentStateName = name;
        if (instance->m_currentState != nullptr)
        {
            instance->m_currentState->Init();
        }
    }
    else
    {
        std::cerr << "State " << name << " not found! \n" << std::endl;
    
    }
}


void StateMachine::update() const
{
    if (m_currentState != nullptr)
    {
        m_currentState->Update();
    }
}

void StateMachine::render(SnakeGraphics* graphics) const
{
    if (m_currentState != nullptr)
    {
        m_currentState->Render(graphics);
    }
}

void StateMachine::keyDown(int key) const
{
    if (m_currentState != nullptr)
    {
        m_currentState->KeyDown(key);
    }
}

std::string StateMachine::GetCurrentState()
{
    return m_currentStateName;
}