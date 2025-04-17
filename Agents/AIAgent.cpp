#include "AIAgent.h"
#include "../World.h"
#include "../GameObjects/Snake.h"


AIAgent::AIAgent(int id, Snake* snake) : BaseAgent(id), snake(snake), pathFinding(nullptr)
{
    pathFinding = new PathFinding();
}

Direction AIAgent::GetNextDirection()
{
    if (doonce == false)
    {

        std::cout << "Calculate Path" << std::endl;
        CalculatePath();
        doonce = true;
    }
    

    if(count < path.size() - 1 )
    {

        std::cout << "Paththing "<< std::endl;
        // doonce = false;
        // count = 0;
        if (path[count].GetX() > path[count + 1].GetX() && path[count].GetY() == path[count + 1].GetY())
        {
            std::cout << "LEFT" << count << std::endl;
            ++count;
            direction = LEFT;
            if(count == path.size() - 1)
            {
                doonce = false;
                count = 0;
            }
           
        }
        else if (path[count].GetX() < path[count + 1].GetX() && path[count].GetY() == path[count + 1].GetY())
        {
            std::cout << "RIGHT" << count << std::endl;
            ++count;
            direction = RIGHT;
            if(count == path.size() - 1)
            {
                doonce = false;
                count = 0;
            }
           
        }
        else if (path[count].GetY() > path[count + 1].GetY() && path[count].GetX() == path[count + 1].GetX())
        {
            std::cout << "UP" << count << std::endl;
            ++count;
            direction = UP;
            if(count == path.size() - 1)
            {
                doonce = false;
                count = 0;
            }
           
        }
        else if (path[count].GetY() < path[count + 1].GetY() && path[count].GetX() == path[count + 1].GetX())
        {
            std::cout << "DOWN" << count << std::endl;
            ++count;
            direction = DOWN;
            if(count == path.size() - 1)
            {
                doonce = false;
                count = 0;
            }
           
        }
    }
    

    return direction;
}

void AIAgent::KeyDown(int Key)
{
}

void AIAgent::CalculatePath()
{
    Tile test = World::grid->GetRandomAppleTile();


    Tile test2 = World::grid->GetRandomAppleTile();
    std::cout << "APPLY X " << test2.GetX() << "APPLE Y " << test2.GetY() << std::endl;

    Tile test3 = World::grid->GetRandomAppleTile();
    std::cout << "APPLY X " << test3.GetX() << "APPLE Y " << test3.GetY() << std::endl;

    Tile test4 = World::grid->GetRandomAppleTile();
    std::cout << "APPLY X " << test4.GetX() << "APPLE Y " << test4.GetY() << std::endl;
    
    path = pathFinding->FindPath(World::grid->GetTile(snake->GetPosition().first, snake->GetPosition().second), test,
                                 direction);

    std::cout << "SNake X" << World::grid->GetTile(snake->GetPosition().first, snake->GetPosition().second).GetX() <<
        " SNAKE Y" << World::grid->GetTile(snake->GetPosition().first, snake->GetPosition().second).GetY() << std::endl;

    std::cout << "apple x" << test.GetX() << "apply y" << test.GetY() << std::endl;

    std::cout << "Path size" << path.size() << std::endl;


    // while (count < path.size() - 1)
    // {
    //     std::cout << "Paththing " << std::endl;
    //     // doonce = false;
    //     // count = 0;
    //     if (path[count].GetX() > path[count + 1].GetX() && path[count].GetY() == path[count + 1].GetY())
    //     {
    //         std::cout << "LEFT" << count << std::endl;
    //         ++count;
    //     }
    //     else if (path[count].GetX() < path[count + 1].GetX() && path[count].GetY() == path[count + 1].GetY())
    //     {
    //         std::cout << "RIGHT" << count << std::endl;
    //         ++count;
    //     }
    //     else if (path[count].GetY() > path[count + 1].GetY() && path[count].GetX() == path[count + 1].GetX())
    //     {
    //         std::cout << "UP" << count << std::endl;
    //         ++count;
    //     }
    //     else if (path[count].GetY() < path[count + 1].GetY() && path[count].GetX() == path[count + 1].GetX())
    //     {
    //         std::cout << "DOWN" << count << std::endl;
    //         ++count;
    //     }
    // }
}
