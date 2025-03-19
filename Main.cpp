#include <fstream>
#include <iostream>

#include "stdafx.h"
#include "Game.h"
#include "crtdbg.h"
#include "GameStates/StateMachine.h"

int main()
{
	
	class Tile
	{
	public:
		Tile(int x, int y, char symbol) : x(x), y(y), symbol(symbol), occupied(false) {}

		int getX() const { return x; }
		int getY() const { return y; }
		char getSymbol() const { return symbol; }
		void setSymbol(char newSymbol) { symbol = newSymbol; }

		bool isOccupied() const { return occupied; }
		void setOccupied(bool isOccupied) {
			occupied = isOccupied;
			symbol = occupied ? 'X' : 'O';
		}

	private:
		int x, y;
		char symbol;
		bool occupied;
	};

	class Grid
	{
	public:
		Grid(int width, int height) : width(width), height(height) {
			// Initialize the grid with empty tiles
			grid.resize(height, std::vector<Tile>(width, Tile(0, 0, 'O')));
			for (int y = 0; y < height; ++y) {
				for (int x = 0; x < width; ++x) {
					grid[y][x] = Tile(x, y, 'O');
				}
			}
		}

		Tile& getTile(int x, int y) {
			return grid[y][x];
		}

		void setTile(int x, int y, bool occupied) {
			grid[y][x].setOccupied(occupied);
		}

		void printGrid() const {
			for (const auto& row : grid) {
				for (const auto& tile : row) {
					std::cout << tile.getSymbol() << ' ';
				}
				std::cout << std::endl;
			}
		}

	private:
		int width, height;
		std::vector<std::vector<Tile>> grid;
	};
	Grid* grid = new Grid(30, 15);
	
	
	// Specify the file path
	std::ifstream MyReadFile("example.txt");

	// Check if the file is open
	if (!MyReadFile.is_open()) {
		std::cerr << "Failed to open the file." << std::endl;
		return 1;
	}

	// Read the file line by line
	std::string myText;
	std:char c;
	
	int x = 0;
	int y = 0;
	while (getline(MyReadFile, myText)) {
		
		
		
		for (auto my_text : myText)
		{
			if(my_text == 'X')
			{
				grid->setTile(x, y, true);
			}
			else if (my_text == 'O')
			{
				grid->setTile(x, y, false);
			}
			
			//std::cout << my_text << std::endl;
			x++;
		}
		//std::cout << myText << std::endl;
		x = 0;
		y++;
	}

	// Close the file
	MyReadFile.close();

 	

	
	
	grid ->printGrid();



	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Game game;
	
	game.Run();

	return 0;
}
// RAYLIB