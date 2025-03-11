#pragma once
#include "Snake/Snake.h"
#include "Snake/Food.h"

class Game
{
private:
	const int FPS = 60;

	bool isPaused;
	
	SnakeGraphics* m_snakeGraphics = nullptr;

	Snake* m_snake = nullptr;
	
	Snake* m_snake2 = nullptr;
	
	Food* m_food = nullptr;

	float m_deltaTime = 0.0f;

	bool Init();

	void Update();

	void Render();

	void CleanUp();

	void KeyDownCallback(int Key);

public:
	void Run();
};

