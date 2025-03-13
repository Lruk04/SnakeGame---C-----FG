#pragma once
#include "BaseState.h"
#include "../GameObjects/Snake.h"
#include "../GameObjects/Food.h"

class PlayState : public BaseState
{
private:
    Snake* m_snake = nullptr;
    Snake* m_snake2 = nullptr;
    Food* m_food = nullptr;

    
public:
    bool Init() override;

    void Render(SnakeGraphics* graphics) override;

    void Update() override;

    void KeyDown(int Key) override;

    void CleanUp() override;

};

