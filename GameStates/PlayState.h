#pragma once



// class PlayState : public BaseState
// {
// private:
//     Snake* m_snake = nullptr;
//     Snake* m_snake2 = nullptr;
//     Food* m_food = nullptr;
//
//     std::vector<GameObject*> m_gameObjects;
//
//     std::vector<GameObject*> m_newGameObjects;
//     
// public:
//     bool Init() override;
//
//     void Render(SnakeGraphics* graphics) override;
//
//     void Update() override;
//
//     void KeyDown(int Key) override;
//
//     void CleanUp() override;
//
//     void AddGameObject(GameObject* gameObject);
// };
//

#pragma once
//#include "../GameObjects/GameObject.h"
#include <vector>
#include "BaseState.h"

class GameObject;
class Snake;
class Food;


class PlayState : public BaseState {
private:
    Snake* m_snake = nullptr;
    Snake* m_snake2 = nullptr;
    Food* m_food = nullptr;

    std::vector<GameObject*> m_gameObjects;
    std::vector<GameObject*> m_newGameObjects;

public:
    bool Init() override;
    void Render(SnakeGraphics* graphics) override;
    void Update() override;
    void KeyDown(int Key) override;
    void CleanUp() override;
    void AddGameObject(GameObject* gameObject);
};