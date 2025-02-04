#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include "grid.h"

#define MAXLENGTH 100

typedef enum {
    UP,
    DOWN,
    LEFT,
    RIGHT
} Direction;

typedef struct
{
    int bodySegments;
    Cell snakeBody[MAXLENGTH];
    Direction direction;
    Color snakeColor;
} Snake;


Snake InitializeSnakeValues();
void GetInput(Snake *snake);
void SetDirection(Snake *snake);
void MoveSnake(Snake *snake);
bool OutOfBounds(Snake *snake, int gridWidth, int gridHeight);
void WrapMovement(Snake *snake, int gridWidth, int gridHeight);
void ApplyFullMovement(Snake *snake, int gridWidth, int gridHeight);
#endif //SNAKE_H
