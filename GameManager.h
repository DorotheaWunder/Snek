#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "raylib.h"

#include "grid.h"
#include "visuals.h"
#include "snake.h"


typedef struct
{
    Cell levelGrid[ROW][COL];
    Snake snake;
    //other game elements
} GameManager;

void InitGame();
void UpdateGame();
void DrawGame();

#endif //GAMEMANAGER_H
