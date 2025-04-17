#pragma once
#include "../stdafx.h"
#include "BaseState.h"


class OptionState : public BaseState
{
private:
    int selectedOption = 0;
    int xPos = 10;
    int yPos = 5;
    int spaceInBetween = 0;


    std::vector<std::pair<std::string, int>> Mainmenu = { {"Multiplayer", 1}, {"Battlemode", 2}, {"VersusAI", 3}, {"AIAmount", 4}, {"Exit", 5} };
public:
    OptionState(StateMachine* stateMachine);
    ~OptionState() override = default;
     
    bool Init() override;

    void Render(SnakeGraphics* graphics) override;

    void Update() override;

    void KeyDown(int Key) override;

    void CleanUp() override;
};
