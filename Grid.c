#include "raylib.h"
#include "grid.h"

Cell levelGrid[ROW][COL];

Cell InitializeCellValues(int row, int col, int size, CellContent content)
{
    return (Cell)
    {
        .row = row,
        .col = col,

        // .screenPosX = col * size,
        // .screenPosY = row * size,

        .size = size,
        .content = content,

        .cell_color = BLACK,
        .outline_color = (Color){ 35, 35, 35, 255 },
        .outline_thickness = 2
    };
}

void InitializeLevelGrid()
{
    int cellSize = 40;

    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++ )
        {
            levelGrid[row][col] = InitializeCellValues(row, col, cellSize,EMPTY);
        }
    }
}