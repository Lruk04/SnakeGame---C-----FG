#include "World.h"
#include "Agents/PlayerAgent.h"
#include "stdafx.h"
#include <iostream>
#include <string>
#include "Agents/AIAgent.h"
#include "GameObjects/Snake.h"
#include "GameObjects/Food.h"


Grid* World::grid = nullptr;

#include <iostream>
#include <fstream>
#include <string>


void World::OpenLevelFile(std::string levelFilePath)
{
   
    
    // Specify the file path
    m_levelReadFile.open(levelFilePath);
    
    // Check if the file is open
    if (!m_levelReadFile.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return;
    }
    
    // Read the file line by line
    char c;
    
    int x = 0;
    int y = 0;
    while (getline(m_levelReadFile, m_currentLevel)) {
        for (auto my_text : m_currentLevel)
        {
            if(my_text == 'X')
            {
                grid->SetTile(x, y, true);
            }
            else if (my_text == 'O')
            {
                grid->SetTile(x, y, false);
            }

            
            //std::cout << my_text << std::endl;<o
            x++;
        }
        //std::cout << myText << std::endl;
        x = 0;
        y++;
    }
    
    // Close the file
    m_levelReadFile.close();
    
    grid ->printGrid();
}
bool World::Init()
{
    grid = new Grid(SCREEN_WIDTH, SCREEN_HEIGHT);

    OpenLevelFile(m_levelFilePath);


    
    m_agents.emplace_back(new PlayerAgent(0,0));
    
    m_snake = new Snake(this, m_agents.back(),SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 255, 0);
    

    m_agents.emplace_back(new AIAgent(1, nullptr));
    std::cout << "Snake 2 created" << std::endl;
    m_snake2 = new Snake(this, m_agents.back(), SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2, 0, 255, 0);
    std::cout << "Snake 2 created" << std::endl;
    static_cast<AIAgent*>(m_agents.back())->snake = m_snake2; 
    std::cout << "Snake 2 created" << std::endl;
    

    
    
    m_food = new Food(this, SCREEN_WIDTH, SCREEN_HEIGHT, 2);

   

    return true;
}

void World::Render(SnakeGraphics* graphics)
{


    

    
    // Render the grid based on occupancy
    for (int y = 0; y < SCREEN_HEIGHT; y++)
    {
        for (int x = 0; x < SCREEN_WIDTH; x++)
        {
            if (World::grid->GetTile(x, y).IsOccupied())
            {
                graphics->PlotTile(x, y, 0, Color(255, 255, 255), Color(255, 255, 255), ' ');
            }
            if(grid->GetTile(x, y).IsFood())
            {
                graphics->PlotTile(x, y, 0, Color(155, 0, 0), Color(255, 0, 0), ' ');
            }
            if(grid->GetTile(x, y).IsSnake())
            {
                graphics->PlotTile(x, y, 0, Color(0, 155, 0), Color(255, 0, 0), ' ');
            }
        }
    }
    
    m_food->Render(graphics);
    
    for (GameObject* gameObject : m_gameObjects)
    {
        if (!gameObject->IsDestroyed())
        {
            gameObject->Render(graphics);
        }
    }
}



void World::Update()
{
    static int counter = 0;

    // Check objects for init
    for (GameObject* gameObject : m_newGameObjects)
    {
        gameObject->Init();

        m_gameObjects.push_back(gameObject);
    }

    m_newGameObjects.clear();

    // Update objects
    for (GameObject* gameObject : m_gameObjects)
    {
        if (!gameObject->IsDestroyed())
        {
            gameObject->Update();
        }
    }
    


    // // Delete objects
    // for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end();)
    // {
    //     if ((*it)->IsDestroyed())
    //     {
    //         delete (*it);
    //
    //         it = m_gameObjects.erase(it);
    //     }
    //     else
    //     {
    //         it++;
    //     }
    // }
    //
    // // Check if snake1 collides with the body of snake2
    // for (const auto& part : m_snake2->GetBody())
    // {
    //     if (m_snake->GetPosition() == part)
    //     {
    //         std::cout << "Game Over, you lost!" << std::endl;
    //         std::cout << "Little noob" << std::endl;
    //         StateMachine::changeState( "Menu");
    //         return;
    //         
    //     }
    // }
    //
    // // Check if snake2 collides with the body of snake1
    // for (const auto& part : m_snake->GetBody())
    // {
    //     if (m_snake2->GetPosition() == part)
    //     {
    //         std::cout << "Game Over, you lost!" << std::endl;
    //         std::cout << "Little noob" << std::endl;
    //         StateMachine::changeState( "Menu");
    //         return;
    //     }
    // }
    
    for (auto& foodPosition : m_food->GetPositions())
    {
        if (m_snake->GetPosition() == foodPosition) {
            m_snake->Grow();

            grid->SetTileFood(foodPosition.first, foodPosition.second, false);
            
            auto& newFoodPosition = World::grid->GetRandomUnoccupiedTile();
            foodPosition.first = newFoodPosition.GetX();
            foodPosition.second = newFoodPosition.GetY();
            
            grid->SetTileFood(newFoodPosition.GetX(), newFoodPosition.GetY(), true);


            
            // do {
            //     foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
            //     foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
            // } while (m_snake->GetPosition() == foodPosition);
    
            break;
        }

        if (m_snake2->GetPosition() == foodPosition) {
            m_snake2->Grow();

            grid->SetTileFood(foodPosition.first, foodPosition.second, false);
            
            auto& newFoodPosition = World::grid->GetRandomUnoccupiedTile();
            foodPosition.first = newFoodPosition.GetX();
            foodPosition.second = newFoodPosition.GetY();

            grid->SetTileFood(newFoodPosition.GetX(), newFoodPosition.GetY(), true);
            
            // do {
            //     
            //     foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
            //     foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
            // } while (m_snake2->GetPosition() == foodPosition);
    
            break;
        }
    }
}


void World::KeyDown(int Key)
{
    
    m_agents[0]->KeyDown(Key);
    
}

void World::CleanUp()
{
    for (GameObject* gameObject : m_newGameObjects)
    {
        delete gameObject;
        gameObject = nullptr;
    }

    for (GameObject* gameObject : m_gameObjects)
    {
        gameObject->Destroy();
    }

    for (GameObject* gameObject : m_gameObjects)
    {
        delete gameObject;
        gameObject = nullptr;
    }

    m_gameObjects.clear();
   
    delete m_food;
    
    m_food = nullptr;
}

void World::AddGameObject(GameObject* gameObject)
{
    for (GameObject* gameObject2 : m_gameObjects)
    {
        if (gameObject == gameObject2)
        {
            return;
        }
    }

    for (GameObject* gameObject2 : m_newGameObjects)
    {
        if (gameObject == gameObject2)
        {
            return;
        }
    }

    m_newGameObjects.push_back(gameObject);
}


