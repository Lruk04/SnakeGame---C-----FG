#include "MainMenu.h"

#include <iostream>

#include "../Game.h"
#include "../GameStates/StateMachine.h"
//int lenght, int yPos, int xPos,int color, int color2, int color3

void MainMenu::Render(SnakeGraphics *graphics, int yPos, int xPos,  int spaceInBetween)
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

void MainMenu::GoUpInMenu()
{
    // Move up in the menu
    if (selectedOption > 0)
    {
        selectedOption--;
    }
}

void MainMenu::GoDownInMenu()
{
    // Move down in the menu
    if (Mainmenu.size()- 1 > selectedOption)
    {
        selectedOption++;
    }
}

void MainMenu::SelectOption() const
{
   
    
    switch (selectedOption)
    {
    case 0:
        // Play
        break;
    case 1:
        // Options
        break;
    case 2:
        // Exit
            
            
            exit(0);
            
        break;
    }
}
