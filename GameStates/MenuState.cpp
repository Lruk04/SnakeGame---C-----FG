#include "MenuState.h"

#include <iostream>

#include "../Game.h"

bool MenuState::Init()
{
    
    return true;
}

void MenuState::Render(SnakeGraphics* graphics)
{
    // Render the main menu
    // Play
    for (int x = xPos; x < xPos + 4 ; x++)
    {
        if (selectedOption == 0)
            graphics->PlotTile(x, yPos + spaceInBetween, 0, Color(255, 255,  255), Color(50, 255,  50), Mainmenu[0].first[x - xPos]);
        else
            graphics->PlotTile(x, yPos + spaceInBetween, 0, Color(255, 255,  255), Color(0, 0,  0), Mainmenu[0].first[x - xPos]);
        
    }
    // Options
    for (int x = xPos; x < xPos + 7; x++)
    {
        if (selectedOption == 1)
            graphics->PlotTile(x,  yPos + 1 + spaceInBetween, 0, Color(255, 255,  255), Color(50, 255,  50), Mainmenu[1].first[x - xPos]);
        else
            graphics->PlotTile(x,  yPos + 1 + spaceInBetween, 0, Color(255, 255,  255), Color(0, 0,  0), Mainmenu[1].first[x - xPos]);
    }
    // Exit
    for (int x = xPos; x < xPos + 4; x++)
    {
        if (selectedOption == 2)
            graphics->PlotTile(x, yPos + 2 + spaceInBetween, 0, Color(255, 255,  255), Color(50, 255,  50), Mainmenu[2].first[x - xPos]);
        else
            graphics->PlotTile(x, yPos + 2 + spaceInBetween, 0, Color(255, 255,  255), Color(0, 0,  0), Mainmenu[2].first[x - xPos]);
        
    }
}

void MenuState::Update()
{
    
}

void MenuState::KeyDown(int Key)
{
    std::cout << "Menustate key down: " << Key << std::endl;

    if (Key == 38 && selectedOption > 0)
    {
        selectedOption--;
    }
    if (Key == 40 && Mainmenu.size()- 1 > selectedOption)
    {
        selectedOption++;
    }
    if (Key == 13)
    {
        switch (selectedOption)
        {
        case 0: 
            StateMachine::changeState( "Play");
            break;
        case 1:
            StateMachine::changeState( "Options");
            break;
        case 2:
           exit(0);
            break;
        default: break;
        }
    }
}

void MenuState::CleanUp()
{
    
}



