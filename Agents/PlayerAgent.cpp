#include "PlayerAgent.h"

PlayerAgent::PlayerAgent(int keyboardLayoutId, int id) :
    BaseAgent(id), m_keyboardLayoutId(keyboardLayoutId)
{
}

Direction PlayerAgent::GetNextDirection()
{
    // if (m_nextDirections.empty())
    // {
    //     return Direction::NONE;
    // }
    //
    // Direction nextDirection = m_nextDirections.front();
    // m_nextDirections.pop();
    
    directionChanged = false;
    return direction;
    //return  nextDirection;
}

void PlayerAgent::KeyDown(int key)
{
    

    //Direction nextDirection = Direction::NONE;

    switch (m_keyboardLayoutId)
    {
        case 0:
            // Control snake with keyboard layout 1
            switch (key)
            {
                
                case 'W':
                    nextDirection = UP;
                    break;
                case 'S':
                    nextDirection = DOWN;
                    break;
                case 'A':
                    nextDirection = LEFT;
                    break;
                case 'D':
                    nextDirection = RIGHT;
                    break;
                default: 
                    break;
            }
            break;
        
        case 1:
            // Control snake with keyboard layout 2
            switch (key)
            {
                case 38:
                    nextDirection = UP;
                    break;
                case 40:
                    nextDirection = DOWN;
                    break;
                case 37:
                    nextDirection = LEFT;
                    break;
                case 39:
                    nextDirection = RIGHT;
                    break;
                default: 
                    break;
            }
            break;
        
        default:
            break;
    }
    
    if (!directionChanged &&
     (direction + nextDirection) != 0)
    {
        direction = nextDirection;
        directionChanged = true;
    }
    
    
    // if (nextDirection != Direction::NONE && m_nextDirections.size() < 10)
    // {
    //     if (!m_nextDirections.empty())
    //     {
    //         Direction direction = m_nextDirections.back();
    //
    //         // Next direction can't be in the same or the opposite direction as the previous direction
    //         if (direction + nextDirection != 0)
    //         {
    //             std::cout << "Invalid direction" << std::endl;
    //             return;
    //         }
    //     }
    //     m_nextDirections.push(nextDirection);
    // }
}

int PlayerAgent::GetKeyboardLayoutId() const { return m_keyboardLayoutId; }