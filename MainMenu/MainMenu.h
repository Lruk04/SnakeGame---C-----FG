#pragma once
#include <string>

#include "../Tools/SnakeGraphics.h"

class MainMenu
{
private:
    std::vector<std::pair<std::string, int>> Mainmenu = { {"Play", 1}, {"Options", 2}, {"Exit", 3} };
    int selectedOption;
    
public:
    void Render(SnakeGraphics *graphics, int yPos, int xPos, int spaceInBetween);

    void GoUpInMenu();

    void GoDownInMenu();

    void SelectOption() const;
    
};
