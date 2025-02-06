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
    int headIndex;
    int tailIndex;

    Direction direction;
    Color bodyColor;
    Color headColor;
} Snake;


Snake InitializeSnakeValues();
void GetInput(Snake *snake);
void SetDirection(Snake *snake);
void MoveHead(Snake *snake);
bool OutOfBounds(Snake *snake, int gridWidth, int gridHeight);
void WrapMovement(Snake *snake, int gridWidth, int gridHeight);
void UpdateSnakePosition(Snake *snake, int gridWidth, int gridHeight);
bool CollidedWithSelf(Snake *snake);
#endif //SNAKE_H
