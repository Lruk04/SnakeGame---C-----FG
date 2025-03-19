#pragma once
#include <string>


#include "GameObjects/Snake.h"
#include "GameObjects/Food.h"
#include "GameStates/StateMachine.h"

class StateMachine;
class Snake;
class GameObject;

class Game
{
    static Game* instance;

    
    const int FPS = 60;

    float m_deltaTime = 0.0f;
    
    bool isPaused;

    std::vector<GameObject*> m_gameObjects;

    std::vector<GameObject*> m_newGameObjects;


    SnakeGraphics* m_snakeGraphics = nullptr;
    
    StateMachine* m_stateMachine = nullptr;
    

    bool Init();

    void Update();

    void Render();

    void CleanUp();

    void KeyDownCallback(int Key);

public:
    static Game* getInstance();
    
    void Run();

    void AddGameObject(GameObject* gameObject);
};
