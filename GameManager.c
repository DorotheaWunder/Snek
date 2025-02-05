﻿#include "gamemanager.h"

GameManager game;

void InitGame()
{
    game.deltaTime = 0.0f;
    game.moveTimer = 0.0f;
    game.moveDelay = 0.5f;

    InitWindow(800, 800, "Snake");
    InitializeLevelGrid();
    game.gridWidth = COL;
    game.gridHeight = ROW;

    game.snake = InitializeSnakeValues();

}

void UpdateGame()
{
    game.deltaTime = GetFrameTime();

    game.moveTimer += game.deltaTime;

    if (game.moveTimer >= game.moveDelay)
    {
        game.moveTimer = 0.0f;
        UpdateSnakePosition(&game.snake, ROW, COL);
    }

    GetInput(&game.snake);
}

void DrawGame()
{
    DrawLevelGrid();
    DrawSnake(&game.snake);
}
