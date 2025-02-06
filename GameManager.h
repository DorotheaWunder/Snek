#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "raylib.h"

#include "grid.h"
#include "visuals.h"
#include "SnakeArray.h"


typedef struct
{
    float deltaTime;
    float moveTimer;
    float moveDelay;

    Cell levelGrid[ROW][COL];
    int gridWidth;
    int gridHeight;

    Snake snake;
    //other game elements
} GameManager;

void InitGame();
void UpdateGame();
void DrawGame();
void ResetGame(GameManager *game);
void GameFlow(GameManager *game);

#endif //GAMEMANAGER_H
