#pragma once
#include <map>
#include <string>

#include "BaseState.h"
#include "MenuState.h"
#include "PlayState.h"
#include "../GameObjects/Snake.h"

class MenuState; 
class PlayState;

class StateMachine
{
private:
    static StateMachine* instance;
    
    MenuState* m_menuState = nullptr;
    PlayState* m_playState = nullptr;
    
    std::map<std::string, BaseState*> m_states;
    BaseState* m_currentState = nullptr;
    std::string m_currentStateName;
public:
    StateMachine();
    
    
    static void changeState( const std::string& name);

    std::string GetCurrentState();
    
    void update() const;

    void render(SnakeGraphics* graphics) const;

    void keyDown(int key) const;
    
};
