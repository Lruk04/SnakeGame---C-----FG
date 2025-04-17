#include "PlayState.h"
#include "../Agents/PlayerAgent.h"
#include "../stdafx.h"
#include <iostream>
#include <string>

#include "../GameObjects/Snake.h"
#include "../GameObjects/Food.h"


PlayState::PlayState( StateMachine* stateMachine) : BaseState(stateMachine)
{
    m_world = new World();
}

PlayState::~PlayState()
{
    delete m_world;
    m_world = nullptr;
}

bool PlayState::Init()
{
    
    m_world->Init();
    
    return true;
}

void PlayState::Render(SnakeGraphics* graphics)
{
    m_world->Render(graphics);
    
}


void PlayState::Update()
{
 
    
    m_world->Update();

    // // Check objects for init
    // for (GameObject* gameObject : m_newGameObjects)
    // {
    //     gameObject->Init();
    //
    //     m_gameObjects.push_back(gameObject);
    // }
    //
    // m_newGameObjects.clear();
    //
    // // Update objects
    // for (GameObject* gameObject : m_gameObjects)
    // {
    //     if (!gameObject->IsDestroyed())
    //     {
    //         gameObject->Update();
    //     }
    // }
    //
    //
    //
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
    // // // Check if snake1 collides with the body of snake2
    // // for (const auto& part : m_snake2->GetBody())
    // // {
    // //     if (m_snake->GetPosition() == part)
    // //     {
    // //         std::cout << "Game Over, you lost!" << std::endl;
    // //         std::cout << "Little noob" << std::endl;
    // //         StateMachine::changeState( "Menu");
    // //         return;
    // //         
    // //     }
    // // }
    // //
    // // // Check if snake2 collides with the body of snake1
    // // for (const auto& part : m_snake->GetBody())
    // // {
    // //     if (m_snake2->GetPosition() == part)
    // //     {
    // //         std::cout << "Game Over, you lost!" << std::endl;
    // //         std::cout << "Little noob" << std::endl;
    // //         StateMachine::changeState( "Menu");
    // //         return;
    // //     }
    // // }
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
    // }

}

void PlayState::KeyDown(int Key)
{
    m_world->KeyDown(Key);
    //m_agents[0]->KeyDown(Key);
    
}

void PlayState::CleanUp()
{
    m_world->CleanUp();
  
}
