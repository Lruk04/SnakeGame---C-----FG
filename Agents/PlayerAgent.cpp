#include "PlayerAgent.h"

PlayerAgent::PlayerAgent(int keyboardLayoutId) :
    m_keyboardLayoutId(keyboardLayoutId)
{

}

BaseAgent::Direction PlayerAgent::GetNextDirection()
{
    if (m_nextDirections.empty())
    {
        return Direction::None;
    }

    Direction nextDirection = m_nextDirections.front();

    m_nextDirections.pop();

    return nextDirection;
}

void PlayerAgent::KeyDown(int key)
{
    Direction nextDirection = Direction::None;

    switch (m_keyboardLayoutId)
    {
    case 0:
        if (key == 'W')
        {
            nextDirection = Direction::Up;
        }
        else if (key == 'S')
        {
            nextDirection = Direction::Down;
        }
        // Control snake with keyboard layout 1
        break;
    case 1:
        // Control snake with keyboard layout 2
            break;
    }

    if (nextDirection != Direction::None && m_nextDirections.size() < 10)
    {
        if (!m_nextDirections.empty())
        {
            Direction direction = m_nextDirections.back();

            // Next direction can't be in the same or the opposite direction as the privious direction
            if ((int)nextDirection % 2 == (int)direction % 2)
            {
                return;
            }
        }

        m_nextDirections.push(nextDirection);
    }
}