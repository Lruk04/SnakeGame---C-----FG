#pragma once

// THINGS TO ASK OUR TEACHER, SHOULD WE CREATE A GRID CLASS THAT CONTAINS THE TILE CLASS? OR DO WE USE THE ONE WE HAVE BEEN PROVEDED


class Grid
{
private:
int width;
    int height;
    
public:
    class Tile
    {
    private:
        int gCost = 0;
        int hCost = 0;
    
    public:
        int x,y = 0;
        bool isOccupied = false;
        Tile* parent = nullptr;
        
        int getFCost() const {
            return gCost + hCost;
        }
    };
};
