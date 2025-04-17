#pragma once
#include <fstream>
#include <vector>
#include "BaseState.h"
#include "../World.h"
#include "../A Star/Grid.h"

class BaseAgent;
class GameObject;
class Snake;
class Food;



class PlayState : public BaseState {
private:
    World* m_world = nullptr;


    

public:
    PlayState(StateMachine* stateMachine);
    ~PlayState() override;
    
    bool Init() override;
    void Render(SnakeGraphics* graphics) override;
    void Update() override;
    void KeyDown(int Key) override;
    void CleanUp() override;


   
};