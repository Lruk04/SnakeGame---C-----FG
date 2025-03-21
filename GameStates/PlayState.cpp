// #include "PlayState.h"
// #include "../stdafx.h"
// #include <iostream>
//
//
// bool PlayState::Init()
// {
//    
//     //new Snake(Game::getInstance(), SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//     m_snake = new Snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//     m_snake2 = new Snake(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3);
//
//     m_food = new Food(SCREEN_WIDTH, SCREEN_HEIGHT, 5);
//     
//     return true;
// }
//
// void PlayState::Render(SnakeGraphics* graphics)
// {
//     m_food->Render(graphics);
//     m_snake ->Render(graphics, 0, 255, 0);
//     m_snake2->Render(graphics, 0, 0, 255);
// }
//
//
// void PlayState::Update()
// {
//     m_snake->Move();
//     m_snake2->Move();
//     
//     
//     // Check if snake1 collides with the body of snake2
//     for (const auto& part : m_snake2->GetBody())
//     {
//         if (m_snake->GetPosition() == part)
//         {
//             std::cout << "Game Over, you lost!" << std::endl;
//             std::cout << "Little noob" << std::endl;
//             StateMachine::changeState( "Menu");
//             return;
//             
//         }
//     }
//     
//     // Check if snake2 collides with the body of snake1
//     for (const auto& part : m_snake->GetBody())
//     {
//         if (m_snake2->GetPosition() == part)
//         {
//             std::cout << "Game Over, you lost!" << std::endl;
//             std::cout << "Little noob" << std::endl;
//             StateMachine::changeState( "Menu");
//             return;
//         }
//     }
// 	   
//     // Existing collision checks for walls and self-collision for snake1
//     // if (m_snake->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) || m_snake2->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) ||m_snake->CheckCollision(0, 0) || m_snake2->CheckCollision(0, 0))
//     if (m_snake->CheckCollision(SCREEN_WIDTH, SCREEN_HEIGHT ) || m_snake2->CheckCollision(SCREEN_WIDTH , SCREEN_HEIGHT))
//     {
//         std::cout << "Game Over, you lost!" << std::endl;
//         std::cout << "Back to menu" << std::endl;
//         StateMachine::changeState( "Menu");
//         return;
//     }
// 	   
//     if (m_snake->CheckSelfCollision() || m_snake2->CheckSelfCollision())
//     {
//         std::cout << "Game Over, you lost!" << std::endl;
//         std::cout << "Little noob" << std::endl;
//         StateMachine::changeState( "Menu");
//         return;
//     }
// 	   
//     for (auto& foodPosition : m_food->GetPositions())
//     {
//         if (m_snake->GetPosition() == foodPosition) {
//             m_snake->Grow();
//     
//             do {
//                 foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
//                 foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
//             } while (m_snake->GetPosition() == foodPosition);
//     
//             break;
//         }
//     
//         if (m_snake2->GetPosition() == foodPosition) {
//             m_snake2->Grow();
//     
//             do {
//                 foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
//                 foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
//             } while (m_snake2->GetPosition() == foodPosition);
//     
//             break;
//         }
//     }
//
// }
//
// void PlayState::KeyDown(int Key)
// {
//     switch (Key)
//     {
//     case 'W': m_snake->ChangeDirection(UP); break;
//     case 'S': m_snake->ChangeDirection(DOWN); break;
//     case 'A': m_snake->ChangeDirection(LEFT); break;
//     case 'D': m_snake->ChangeDirection(RIGHT); break;
//     }
//     switch (Key)
//     {
//     case 38: m_snake2->ChangeDirection(UP); break;
//     case 40: m_snake2->ChangeDirection(DOWN); break;
//     case 37: m_snake2->ChangeDirection(LEFT); break;
//     case 39: m_snake2->ChangeDirection(RIGHT); break;
//     }
// }
//
// void PlayState::CleanUp()
// {
//     delete m_snake;
//     delete m_snake2;
//     delete m_food;
// }

#include "PlayState.h"

#include "../stdafx.h"
#include <iostream>
#include "../GameObjects/Snake.h"
#include "../GameObjects/Food.h"

bool PlayState::Init()
{
   
    new Snake(this, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 255, 0);

    m_food = new Food(SCREEN_WIDTH, SCREEN_HEIGHT, 5);


    return true;
}

void PlayState::Render(SnakeGraphics* graphics)
{
    m_food->Render(graphics);

   
    for (GameObject* gameObject : m_gameObjects)
    {
        if (!gameObject->IsDestroyed())
        {
            gameObject->Render(graphics);
        }
    }
}


void PlayState::Update()
{
    //m_snake->Move();
    
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



    // Delete objects
    for (std::vector<GameObject*>::iterator it = m_gameObjects.begin(); it != m_gameObjects.end();)
    {
        if ((*it)->IsDestroyed())
        {
            delete (*it);

            it = m_gameObjects.erase(it);
        }
        else
        {
            it++;
        }
    }
    
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
	   
    // Existing collision checks for walls and self-collision for snake1
    // if (m_snake->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) || m_snake2->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) ||m_snake->CheckCollision(0, 0) || m_snake2->CheckCollision(0, 0))

    // if (m_snake->CheckCollision(SCREEN_WIDTH, SCREEN_HEIGHT ) || m_snake2->CheckCollision(SCREEN_WIDTH , SCREEN_HEIGHT))
    // {
    //     std::cout << "Game Over, you lost!" << std::endl;
    //     std::cout << "Back to menu" << std::endl;
    //     StateMachine::changeState( "Menu");
    //     return;
    // }
	   //
    // if (m_snake->CheckSelfCollision() || m_snake2->CheckSelfCollision())
    // {
    //     std::cout << "Game Over, you lost!" << std::endl;
    //     std::cout << "Little noob" << std::endl;
    //     StateMachine::changeState( "Menu");
    //     return;
    // }
	   //
    // for (auto& foodPosition : m_food->GetPositions())
    // {
    //     if (m_snake->GetPosition() == foodPosition) {
    //         m_snake->Grow();
    //
    //         do {
    //             foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
    //             foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
    //         } while (m_snake->GetPosition() == foodPosition);
    //
    //         break;
    //     }
    //
    //     if (m_snake2->GetPosition() == foodPosition) {
    //         m_snake2->Grow();
    //
    //         do {
    //             foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
    //             foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
    //         } while (m_snake2->GetPosition() == foodPosition);
    //
    //         break;
    //     }
    // }

}

void PlayState::KeyDown(int Key)
{
    
    switch (Key)
    {
    case 'W': m_snake->ChangeDirection(UP); break;
    case 'S': m_snake->ChangeDirection(DOWN); break;
    case 'A': m_snake->ChangeDirection(LEFT); break;
    case 'D': m_snake->ChangeDirection(RIGHT); break;
    }
    
}

void PlayState::CleanUp()
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
    
    delete m_snake;
    delete m_snake2;
    delete m_food;

    m_snake = nullptr;
    m_snake2 = nullptr;
    m_food = nullptr;
}

void PlayState::AddGameObject(GameObject* gameObject)
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


