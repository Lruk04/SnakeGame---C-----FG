#include "OptionState.h"
#include "../GameStates/StateMachine.h"

#define GET_COLOR(i) { i == selectedOption ? Color(50, 255,  50) : Color(0, 0,  0) }
#define GET_MULTIPLAYERTEXT(i) { i == selectedOption ? (std::wstring(L"Co-op ") + (m_stateMachine->settings.multiplayer ? L"ON" : L"OFF")).c_str() :(std::wstring(L"Co-op ") + (m_stateMachine->settings.multiplayer ? L"ON" : L"OFF")).c_str()  }
#define GET_BATTLEMODETEXT(i) { i == selectedOption ? (std::wstring(L"Battle Mode ") + (m_stateMachine->settings.battleMode ? L"ON" : L"OFF")).c_str() : (std::wstring(L"Battle Mode ") + (m_stateMachine->settings.battleMode ? L"ON" : L"OFF")).c_str() }
#define GET_AIAMOUNTTEXT(i) { i == selectedOption ? (std::wstring(L"AI Amount ") + std::to_wstring(m_stateMachine->settings.AIAmount)).c_str() : (std::wstring(L"AI Amount ") + std::to_wstring(m_stateMachine->settings.AIAmount)).c_str() }
#define GET_EXIT(i) { i == selectedOption ? L"EXIT" : L"EXIT"}



OptionState::OptionState(StateMachine* stateMachine) : BaseState(stateMachine)
{
    
}

bool OptionState::Init()
{
    
    return true;
}


void OptionState::Render(SnakeGraphics* graphics)
{
    graphics->PlotText(xPos, yPos + 0 + spaceInBetween, 0, Color(255, 255, 255), L"Multiplayer",
                      Color(0, 0,  0) , graphics->Left);
    graphics->PlotText(xPos, yPos + 1 + spaceInBetween, 0, Color(255, 255, 255), GET_MULTIPLAYERTEXT(0),
                      GET_COLOR(0), graphics->Left);
    graphics->PlotText(xPos, yPos + 2 + spaceInBetween, 0, Color(255, 255, 255), GET_BATTLEMODETEXT(1),
                       GET_COLOR(1), graphics->Left);
    graphics->PlotText(xPos, yPos + 3 + spaceInBetween, 0, Color(255, 255, 255), GET_AIAMOUNTTEXT(2),
                       GET_COLOR(3), graphics->Left);
    graphics->PlotText(xPos, yPos + 4 + spaceInBetween, 0, Color(255, 255, 255), GET_EXIT(3),
                       GET_COLOR(4), graphics->Left);
    
}

void OptionState::Update()
{
    
}


void OptionState::KeyDown(int Key)
{
    if (Key == 38 && selectedOption > 0)
    {
        selectedOption--;
    }
    if (Key == 40 && Mainmenu.size() - 1 > selectedOption)
    {
        selectedOption++;
    }
    
    if (Key == 13)
    {
        switch (selectedOption)
        {
        case 0:
            m_stateMachine->settings.multiplayer = !m_stateMachine->settings.multiplayer;
            if(m_stateMachine->settings.multiplayer)
            {
                m_stateMachine->settings.battleMode = false;
            }
            break;
        case 1:
            m_stateMachine->settings.battleMode = !m_stateMachine->settings.battleMode;
            if(m_stateMachine->settings.battleMode)
            {
                m_stateMachine->settings.multiplayer = false;
            }
            break;
        case 2:
            m_stateMachine->settings.versusAI = !m_stateMachine->settings.versusAI;
            if(m_stateMachine->settings.versusAI && m_stateMachine->settings.AIAmount == 0)
            {
                m_stateMachine->settings.AIAmount = 1;
            }
            break;
        case 3:
            m_stateMachine->settings.AIAmount++;

            if(m_stateMachine->settings.AIAmount > 0)
            {
                m_stateMachine->settings.versusAI = true;
            }
          

            
            if (m_stateMachine->settings.AIAmount > 4)
            {
                m_stateMachine->settings.AIAmount = 0;
                m_stateMachine->settings.versusAI = false;
            }
            break;
        case 4:
            StateMachine::changeState("Menu");
            break;
            
        default: break;
        }
    }
}


void OptionState::CleanUp()
{
    
}


