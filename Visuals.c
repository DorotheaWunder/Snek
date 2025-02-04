#include "raylib.h"
#include "grid.h"
#include "snake.h"


void DrawCell(Cell *cell)
{
    int screenPosX = cell->col * cell->size;
    int screenPosY = cell->row * cell->size;

    DrawRectangle(
        screenPosX,
        screenPosY,
        cell->size,
        cell->size,
        cell->cell_color
    );

    Rectangle rectCell = { screenPosX, screenPosY, cell->size, cell->size };

    DrawRectangleLinesEx(
        (rectCell),
        cell->outline_thickness,
        cell->outline_color
    );
}

void DrawLevelGrid()
{
    for (int row = 0; row < ROW; row++)
    {
        for (int col = 0; col < COL; col++)
        {
            DrawCell(&levelGrid[row][col]);
        }
    }
}

void DrawSnake(Snake *snake)
{
    //InitializeSnakeValues();
    //DrawRectangle(6,6,10,10,GREEN);
    snake->snakeBody[0].cell_color = snake->snakeColor;
    DrawCell(&snake->snakeBody[0]);

    // for (int i = 0; i < snake->bodySegments; i++)
    // {
    //     snake->snakeBody[i].cell_color = snake->snakeColor;
    //     DrawCell(&snake->snakeBody[i]);
    // }
}