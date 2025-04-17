#include "stdafx.h"
#include "Game.h"
#include "Tools/SnakeGraphics.h"
#include "Tools/SnakeInput.h"
#include <iostream>
#include <chrono>
#include <thread>


Game* Game::instance = nullptr;

bool Game::Init()
{
	m_stateMachine = new StateMachine();

	StateMachine::changeState( "Menu");
	
	m_snakeGraphics = new SnakeGraphics(1024, 720, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (!m_snakeGraphics->Init())
	{
		std::cerr << "Failed to initilize snake graphics!" << std::endl;

		return false;
	}
	
	SnakeInput::Init(m_snakeGraphics);

	SnakeInput::AddKeyDownCallback(std::bind(&Game::KeyDownCallback, this, std::placeholders::_1));
	
	return true;
}

void Game::KeyDownCallback(int Key)
{
	m_stateMachine->keyDown(Key);
	
	std::cout << Key << std::endl;

	if (Key == 'P')
	{
		isPaused = !isPaused;
	}
	if (Key == 'O')
    {
		StateMachine::changeState( "Menu");
    }
}

void Game::Update()
{
	m_stateMachine->update();
	

}

void Game::Render()
{
	m_stateMachine->render(m_snakeGraphics);

	
	
	
	// // Render the borders, top borders
	// for (int x = 0; x < SCREEN_WIDTH; x++)
	// {
	// 	m_snakeGraphics->PlotTile(x, 0, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
	// 	m_snakeGraphics->PlotTile(x, SCREEN_HEIGHT - 1, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
	// }
	//
	// // Render the borders, side borders<
	// for (int y = 0; y < SCREEN_HEIGHT; y++)
	// {
	// 	m_snakeGraphics->PlotTile(0, y, 0, Color( 255, 255,  255), Color(255, 255,  255), ' ');
	// 	m_snakeGraphics->PlotTile(SCREEN_WIDTH - 1, y, 0, Color(255, 255,  255), Color(255, 255,  255), ' ');
	// }


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

