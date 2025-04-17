
#include "Snake.h" 
#include "../stdafx.h"
#include <iostream>
#include <ostream>
#include "../World.h"

Snake::Snake(World* game, BaseAgent* baseAgent, int startX, int startY, int color, int color2, int color3) : GameObject(game), m_baseAgent(baseAgent) , grow(false), directionChanged(false)
{
    // Initialize the snake with a single body part
    body.push_back({startX, startY});

    this->color = color;
    this->color2 = color2;
    this->color3 = color3;
}

void Snake::Move()
{
    
    Direction nextDirection = m_baseAgent->GetNextDirection();

    
    
    
    // Move the snake in the current direction
    auto head = body.front();
    switch (nextDirection)
    {
        case NONE:
        break;
        case UP:
            head.second--;
            break;
        case DOWN:
            head.second++;
            break;
        case LEFT:
            head.first--;
            break;
        case RIGHT:
            head.first++;
            break;
    }
    
    // Add the new head to the front of the body
    body.push_front(head);
    if(!World::grid->GetTile(head.first, head.second).IsOccupied())
    {
        World::grid->SetTileSnake(head.first, head.second, true);
    }
    else
    {
        std::cout << "Game Over, you lost!" << std::endl;
        Destroy();
        return;
    }
    
    if (!grow)
    {
        // If the snake is not growing, remove the tail
        body.pop_back();
        World::grid->SetTileSnake(body.back().first, body.back().second, false);
    }
    else
    {
        grow = false;
    }

    directionChanged = false;
}

void Snake::Grow()
{
    grow = true;
}

bool Snake::CheckSelfCollision()
{
    // Check if the snake has collided with itself
    const auto& head = body.front();
    
    for (auto it = std::next(body.begin()); it != body.end(); ++it)
    {
        if (head == *it)
        {
            return true;
        }
    }
    return false;
}

std::pair<int, int> Snake::GetPosition() const
{
    //Return the position of the head of the snake
    return body.front();
}

const std::deque<std::pair<int, int>>& Snake::GetBody() const
{
    // Returns the deque of body parts
    return body;
}

void Snake::Render(SnakeGraphics* graphics)
{
    //Render the snake, each body part
    for (const auto& part : body)
    {
        graphics->PlotTile(part.first, part.second, 0, Color(color, color2, color3), Color(0, 255, 0),' ');
    }
}


void Snake::Init()
{
    
}

void Snake::Update()
{

    Move();
    
    if (CheckSelfCollision())
    {
        std::cout << "Game Over, you lost!" << std::endl;
        std::cout << "Back to menu" << std::endl;
        return;
    }
    
    // if(World::grid->GetTile(body.front().first, body.front().second).IsOccupied())
    // {
    //     std::cout << "Game Over, you lost!" << std::endl;
    //     std::cout << "Back to menu" << std::endl;
    //     Destroy();
    //     return;
    // }
    
}

void Snake::DestroyDerived()
{
        
}

