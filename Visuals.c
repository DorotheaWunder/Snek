﻿#include "raylib.h"
#include "gamemanager.h"
#include "grid.h"
#include "SnakeArray.h"
#include "food.h"

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

void DrawSnakeArray(Snake *snake)
{
    snake->snakeBody[0].cell_color = snake->headColor;
    DrawCell(&snake->snakeBody[0]);

    for (int i = 1; i < snake->bodySegments; i++)
    {
        snake->snakeBody[i].cell_color = snake->bodyColor;
        DrawCell(&snake->snakeBody[i]);
    }
}

void DrawFood(Cell *food)
{
    food->cell_color = RED;
    DrawCell(&game.food);
}