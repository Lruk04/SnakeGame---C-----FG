#pragma once
#include <map>
#include <string>

#include "BaseState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "OptionState.h"
#include "../GameObjects/Snake.h"

class MenuState; 
class PlayState;
class OptionState;

class StateMachine
{
private:
    static StateMachine* instance;
    
    MenuState* m_menuState = nullptr;
    PlayState* m_playState = nullptr;
    OptionState* m_optionState = nullptr;
    
    std::map<std::string, BaseState*> m_states;
    BaseState* m_currentState = nullptr;
    std::string m_currentStateName;


    struct SettingsStruct
    {
        SettingsStruct (){ multiplayer = false; battleMode = false; versusAI = false; AIAmount = 0; }

        bool multiplayer;
        bool battleMode;
        bool versusAI ;
        int AIAmount;
        
        
    };
public:
    int score = 0;
    SettingsStruct settings;
        

    
    StateMachine();
    
    static void changeState( const std::string& name);

    std::string GetCurrentState();
    
    void update() const;

    void render(SnakeGraphics* graphics) const;

    void keyDown(int key) const;
    
};
