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

#endif //SNAKE_H
