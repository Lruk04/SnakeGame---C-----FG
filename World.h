#pragma once
#include <fstream>
#include <vector>

#include "A Star/Grid.h"
#include "Tools/SnakeGraphics.h"


class BaseAgent;
class GameObject;
class Snake;
class Food;

class World
{
private:
    std::ifstream m_levelReadFile;
    std::string m_currentLevel;
    std::string m_levelFilePath = "Levels/exampleLevel.txt";
    
    Food* m_food = nullptr;
    Snake* m_snake = nullptr;
    Snake* m_snake2 = nullptr;
    
    std::vector<BaseAgent*> m_agents;
    std::vector<GameObject*> m_gameObjects;
    std::vector<GameObject*> m_newGameObjects;

public:
 

    bool Init() ;
    void Render(SnakeGraphics* graphics);
    void Update();
    void KeyDown(int Key);
    void CleanUp();
    void AddGameObject(GameObject* gameObject);
    void RemoveGameObject(GameObject* gameObject);
    
    void CreateGrid();
    void OpenLevelFile(std::string levelFilePath);
    
    static Grid* grid;
};
