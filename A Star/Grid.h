#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>


class Tile
{
private:
    int x, y;
    char symbol;
    bool occupied;
    bool snake = false;
    bool food = false;
    

public:
    Tile(int x, int y, char symbol);

    int hCost, gCost, fCost;

    Tile* parent = nullptr;

    Tile* GetCameFrom() const;
    void SetCameFrom(Tile* previousTile);


    int GetFCost() const;
    int GetX() const;
    int GetY() const;


    char GetSymbol() const;
    void SetSymbol(char newSymbol);

    bool IsOccupied() const;
    void SetOccupied(bool isOccupied);

    bool IsSnake() const;
    void SetSnake(bool isSnake);

    bool IsFood() const;
    void SetFood(bool isFood);

    bool operator==(const Tile& other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator==(const Tile* other) const
    {
        return x == other->x && y == other->y;
    }
   
    // bool operator==(const Tile& other) const
    // {
    //     return x == other.x && y == other.y && symbol == other.symbol &&
    //         occupied == other.occupied && snake == other.snake && food == other.food;
    // }
};



class Grid
{
private:
    int width, height;
    std::vector<std::vector<Tile>> grid;

public:
    Grid(int width, int height);

    Tile& GetTile(int x, int y);
    Grid* GetGrid();
    std::vector<Tile*> GetTileList();
    Tile& GetRandomUnoccupiedTile();
    Tile& GetRandomAppleTile();

    void SetTile(int x, int y, bool occupied);
    void SetTileFood(int x, int y, bool food);
    void SetTileSnake(int x, int y, bool snake);


    void printGrid() const;
};

#endif
