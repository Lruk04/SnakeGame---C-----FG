#pragma once
#include <string>

#include "MainMenu/MainMenu.h"
#include "GameObjects/Snake.h"
#include "GameObjects/Food.h"
#include "GameStates/StateMachine.h"

class Game
{
private:
	const int FPS = 60;

	bool isPaused;
	
	MainMenu* m_mainMenu = nullptr;
	
	SnakeGraphics* m_snakeGraphics = nullptr;

	Snake* m_snake = nullptr;
	
	Snake* m_snake2 = nullptr;
	
	Food* m_food = nullptr;

	StateMachine* m_stateMachine = nullptr;
	
	float m_deltaTime = 0.0f;

	bool Init();

	void Update();

	void Render();

	//void CleanUp();

	void KeyDownCallback(int Key);

public:

	void CleanUp();
	void Run();
};

