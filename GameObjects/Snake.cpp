// #include "Snake.h"
//
// Snake::Snake(int startX, int startY) : direction(RIGHT), grow(false)
// {
//     // Initialize the snake with a single body part
//     body.push_back({startX, startY});
// }
//
// void Snake::Move()
// {
//     // Move the snake in the current direction
//     auto head = body.front();
//     switch (direction)
//     {
//         case UP:
//             head.second--;
//             break;
//         case DOWN:
//             head.second++;
//             break;
//         case LEFT:
//             head.first--;
//             break;
//         case RIGHT:
//             head.first++;
//             break;
//     }
//     // Add the new head to the front of the body
//     body.push_front(head);
//
//     if (!grow)
//     {
//         // If the snake is not growing, remove the tail
//         body.pop_back();
//     }
//     else
//     {
//         grow = false;
//     }
//
//     directionChanged = false;
// }
//
// void Snake::Grow()
// {
//     grow = true;
// }
//
// bool Snake::CheckCollision(int WIDTH, int HEIGHT)
// {
//     // Check if the snake has collided with the walls
//     auto head = body.front();
//     // if (head.first < 0 || head.first == WIDTH || head.second < 0 || head.second == HEIGHT)
//     if (head.first < 1 || head.first >= WIDTH - 1 || head.second < 1 || head.second >= HEIGHT - 1)
//     {
//         return true;
//     }
//     
//     return false;
// }
//
//
// bool Snake::CheckSelfCollision()
// {
//     // Check if the snake has collided with itself
//     const auto& head = body.front();
//     
//     for (auto it = std::next(body.begin()); it != body.end(); ++it)
//     {
//         if (head == *it)
//         {
//             return true;
//         }
//     }
//     return false;
// }
//
// void Snake::ChangeDirection(Direction newDirection)
// {
//     // Check if the new direction is valid, if it is, change the direction
//     if (!directionChanged &&
//         ((direction == UP && newDirection != DOWN) ||
//         (direction == DOWN && newDirection != UP) ||
//         (direction == LEFT && newDirection != RIGHT) ||
//         (direction == RIGHT && newDirection != LEFT)))
//     {
//         direction = newDirection;
//         directionChanged = true;
//     }
//     
// }
//
// void Snake::Render(SnakeGraphics* graphics, int color, int color2, int color3)
// {
//     //Render the snake, each body part
//     for (const auto& part : body)
//     {
//         graphics->PlotTile(part.first, part.second, 0, Color(color, color2, color3), Color(0, 255, 0),' ');
//     }
// }
//
// std::pair<int, int> Snake::GetPosition() const
// {
//     //Return the position of the head of the snake
//     return body.front();
// }
//
// const std::deque<std::pair<int, int>>& Snake::GetBody() const
// {
//     // Returns the deque of body parts
//     return body;
// }




#include "Snake.h"

#include <iostream>
#include <ostream>

Snake::Snake(PlayState* game, int startX, int startY, int color, int color2, int color3) : GameObject(game), grow(false), direction(RIGHT), directionChanged(false)
{
    // Initialize the snake with a single body part
    body.push_back({startX, startY});

    this->color = color;
    this->color2 = color2;
    this->color3 = color3;
}

void Snake::Move()
{
    // Move the snake in the current direction
    auto head = body.front();
    switch (direction)
    {
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

    if (!grow)
    {
        // If the snake is not growing, remove the tail
        body.pop_back();
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

bool Snake::CheckCollision(int WIDTH, int HEIGHT)
{
    // Check if the snake has collided with the walls
    auto head = body.front();
    // if (head.first < 0 || head.first == WIDTH || head.second < 0 || head.second == HEIGHT)
    if (head.first < 1 || head.first >= WIDTH - 1 || head.second < 1 || head.second >= HEIGHT - 1)
    {
        return true;
    }
    
    return false;
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

void Snake::ChangeDirection(Direction newDirection)
{
    // Check if the new direction is valid, if it is, change the direction
    // if (!directionChanged &&
    //     ((direction == UP && newDirection != DOWN) ||
    //     (direction == DOWN && newDirection != UP) ||
    //     (direction == LEFT && newDirection != RIGHT) ||
    //     (direction == RIGHT && newDirection != LEFT)))


    if (!directionChanged &&
        (direction + newDirection) != 0)
    {
        direction = newDirection;
        directionChanged = true;
    }
    
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
    CheckSelfCollision();
    Move();
}

void Snake::DestroyDerived()
{
    
}

