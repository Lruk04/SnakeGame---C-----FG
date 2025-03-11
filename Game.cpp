#include "stdafx.h"
#include "Game.h"
#include "Tools/SnakeGraphics.h"
#include "Tools/SnakeInput.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "Snake/Snake.h"
#include "Snake/Food.h"

bool Game::Init()
{
	// Init snake graphics
	m_snakeGraphics = new SnakeGraphics(1024, 720, SCREEN_WIDTH, SCREEN_HEIGHT);

	
	if (!m_snakeGraphics->Init())
	{
	
		std::cerr << "Failed to initilize snake graphics!" << std::endl;
		
		return false;
	}
	
	// Init snake input
	SnakeInput::Init(m_snakeGraphics);

	SnakeInput::AddKeyDownCallback(std::bind(&Game::KeyDownCallback, this, std::placeholders::_1));

	m_snake = new Snake(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

	m_snake2 = new Snake(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3);
	
	m_food = new Food(SCREEN_WIDTH, SCREEN_HEIGHT, 5);

	
	return true;
}

void Game::KeyDownCallback(int Key)
{
	std::cout << Key << std::endl;

	if (Key == 'P')
	{
		std::cout << "Pause" << std::endl;
		std::cout << isPaused << std::endl;
		isPaused = !isPaused;
	}
	
	switch (Key)
	{
		case 'W': m_snake->ChangeDirection(UP); break;
		case 'S': m_snake->ChangeDirection(DOWN); break;
		case 'A': m_snake->ChangeDirection(LEFT); break;
		case 'D': m_snake->ChangeDirection(RIGHT); break;
	}
	switch (Key)
	{
		case 38: m_snake2->ChangeDirection(UP); break;
		case 40: m_snake2->ChangeDirection(DOWN); break;
		case 37: m_snake2->ChangeDirection(LEFT); break;
		case 39: m_snake2->ChangeDirection(RIGHT); break;
	}
}

void Game::Update()
{
	m_snake->Move();
	m_snake2->Move();
	

	// Check if snake1 collides with the body of snake2
	for (const auto& part : m_snake2->GetBody())
	{
		if (m_snake->GetPosition() == part)
		{
			std::cout << "Game Over, you lost!" << std::endl;
			std::cout << "Little noob" << std::endl;
			CleanUp();
			exit(0);
		}
	}

	// Check if snake2 collides with the body of snake1
	for (const auto& part : m_snake->GetBody())
	{
		if (m_snake2->GetPosition() == part)
		{
			std::cout << "Game Over, you lost!" << std::endl;
			std::cout << "Little noob" << std::endl;
			CleanUp();
			exit(0);
		}
	}
	
	// Existing collision checks for walls and self-collision for snake1
	// if (m_snake->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) || m_snake2->CheckCollision(SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1) ||
	//    m_snake->CheckCollision(0, 0) || m_snake2->CheckCollision(0, 0))
	if (m_snake->CheckCollision(SCREEN_WIDTH, SCREEN_HEIGHT ) || m_snake2->CheckCollision(SCREEN_WIDTH , SCREEN_HEIGHT))
	{
		std::cout << "Game Over, you lost!" << std::endl;
		std::cout << "Little noob" << std::endl;
		CleanUp();
		exit(0);
	}
	
	if (m_snake->CheckSelfCollision() || m_snake2->CheckSelfCollision())
	{
		std::cout << "Game Over, you lost!" << std::endl;
		std::cout << "Little noob" << std::endl;
		CleanUp();
		exit(0);
	}
	
	for (auto& foodPosition : m_food->GetPositions())
	{
		if (m_snake->GetPosition() == foodPosition) {
			m_snake->Grow();

		do {
				foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
				foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
			} while (m_snake->GetPosition() == foodPosition);

			break;
		}

		if (m_snake2->GetPosition() == foodPosition) {
			m_snake2->Grow();

			do {
				foodPosition.first = 1 + rand() % (SCREEN_WIDTH - 2);
				foodPosition.second = 1 + rand() % (SCREEN_HEIGHT - 2);
			} while (m_snake2->GetPosition() == foodPosition);

			break;
		}
	}
}

void Game::Render()
{
	// Render the food and snake
	m_food->Render(m_snakeGraphics);
	m_snake ->Render(m_snakeGraphics, 0, 255, 0);
	m_snake2->Render(m_snakeGraphics, 0, 0, 255);
 
	// Render the borders, side borders<
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		m_snakeGraphics->PlotTile(x, 0, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
		m_snakeGraphics->PlotTile(x, SCREEN_HEIGHT - 1, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
	}
	
	// Render the borders, top borders
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		m_snakeGraphics->PlotTile(0, y, 0, Color( 255, 255,  255), Color(255, 255,  255), ' ');
		m_snakeGraphics->PlotTile(SCREEN_WIDTH - 1, y, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
	}


	// Clear the screen to black, makes sure snake path gets cleared
	for (int x = 0; x < SCREEN_WIDTH; x++)
	{
		for (int y = 0; y < SCREEN_HEIGHT; y++)
		{
			m_snakeGraphics->PlotTile(x, y, 0, Color(0, 0, 0), Color(0, 0, 0), ' ');
		}
	}
	
	m_snakeGraphics->Render();
}

void Game::CleanUp()
{
	SnakeInput::CleanUp();
	delete m_snakeGraphics;
	delete m_snake;
	delete m_snake2;
	delete m_food;
}

void Game::Run()
{
	if (Init())
	{
		// Set the frames per second (FPS) and calculate the duration of each frame in milliseconds
		const double FPS = 5.0;
		const double frameDuration = 1000.0 / FPS;

		// Initialize the last time point and accumulated time
		std::chrono::system_clock::time_point lastTime = std::chrono::system_clock::now();
		
		double accumulatedTime = 0.0;

		double highestAccumulatedTime = 0.0;


		// BUG, accumulatedTime seems to continue to increase when game paused
		// Main game loop, continues as long as the window messages are being updated
		while (m_snakeGraphics->UpdateWindowMessages())
		{
		
			if (isPaused)
			{
				lastTime = std::chrono::system_clock::now();
				continue;	
			}
			
			// Get the current time and calculate the elapsed time since the last frame
			std::chrono::system_clock::time_point currentTime = std::chrono::system_clock::now();

			
			std::chrono::duration<double, std::milli> elapsedTime = currentTime - lastTime;
			lastTime = currentTime;
			accumulatedTime += elapsedTime.count();

			// Update the game state for each frame duration that has passed
			while (accumulatedTime >= frameDuration)
			{
				if (accumulatedTime > highestAccumulatedTime)
				{
					std::cout << "Highest accumulated time: " << accumulatedTime << std::endl;
					highestAccumulatedTime = accumulatedTime;
				}
				Update();
				accumulatedTime -= frameDuration;
			}
			// Render the game
			Render();
		}
		CleanUp();

	
	}
}
