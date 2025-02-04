#ifndef GRID_H
#define GRID_H

#include "raylib.h"

#define ROW 10
#define COL 10

typedef enum
{
    EMPTY,
    FOOD,
    SNAKE
}CellContent;

typedef struct
{
    int row;
    int col;

    // int screenPosX;
    // int screenPosY;

    int size;
    CellContent content;

    Color cell_color;
    Color outline_color;
    float outline_thickness;
} Cell;

extern Cell levelGrid[ROW][COL];


Cell InitializeCellValues(int row, int col, int size, CellContent content);
void InitializeLevelGrid();

#endif //GRID_H
