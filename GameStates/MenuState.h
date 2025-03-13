#pragma once
#include <string>

#include "BaseState.h"
#include "StateMachine.h"


class MenuState : public BaseState
{

private:
	int selectedOption = 0;
	int xPos = 7;
	int yPos = 5;
	int spaceInBetween = 0;
	
	
	std::vector<std::pair<std::string, int>> Mainmenu = { {"Play", 1}, {"Options", 2}, {"Exit", 3} };
public:
    bool Init() override;

    void Render(SnakeGraphics* graphics) override;

    void Update() override;

    void KeyDown(int Key) override;

    void CleanUp() override;
	
};
