#pragma once
#include "../stdafx.h"
#include "BaseState.h"


class MenuState : public BaseState
{

private:
	int selectedOption = 0;
	int xPos = 15;
	int yPos = 5;
	int spaceInBetween = 0;
	
	std::vector<std::pair<std::string, int>> Mainmenu = { {"Play", 1}, {"Options", 2}, {"Exit", 3} };
public:

	MenuState(StateMachine* stateMachine);

	
	~MenuState() override = default;
	
    bool Init() override;

    void Render(SnakeGraphics* graphics) override;

    void Update() override;

    void KeyDown(int Key) override;

    void CleanUp() override;
	
};
