#include "raylib.h"
#include "grid.h"
#include "snake.h"

Snake InitializeSnakeValues()
{
    Snake snake;

    snake.bodySegments = 1;
    snake.snakeBody[0] = InitializeCellValues(1, 5, 80, SNAKE);
    snake.snakeColor = GREEN;
    snake.direction = RIGHT;

    return snake;
}