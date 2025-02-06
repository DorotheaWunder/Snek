#include "raylib.h"
#include "food.h"
#include "grid.h"

// Food InitializeFoodValues(int posCol, int posRow)
// {
//     Food food;
//
//     food.color = RED;
//     food.posCol = posCol;
//     food.posRow = posRow;
//
//     return food;
// }

Cell SpawnFood()
{
    int randRow = GetRandomValue(0, ROW - 1);
    int randCol = GetRandomValue(0, COL - 1);

    return InitializeCellValues(randRow, randCol, CELLSIZE, FOOD);
}