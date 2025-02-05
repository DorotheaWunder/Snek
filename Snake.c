#include "raylib.h"
#include "grid.h"
#include "snake.h"

Snake InitializeSnakeValues()
{
    Snake snake;

    snake.bodySegments = 10;
    snake.snakeColor = GREEN;
    snake.direction = RIGHT;

    snake.snakeBody[0] = InitializeCellValues(1, 5, CELLSIZE, SNAKE);
    for (int i = 1; i < snake.bodySegments; i++)
    {
        snake.snakeBody[i] = InitializeCellValues(1, 5 - i, CELLSIZE, SNAKE);
    }

    return snake;
}

void GetInput(Snake *snake)
{
    if (IsKeyPressed(KEY_RIGHT) && snake->direction != LEFT)
    {
        snake->direction = RIGHT;
    }
    if (IsKeyPressed(KEY_LEFT) && snake->direction != RIGHT)
    {
        snake->direction = LEFT;
    }
    if (IsKeyPressed(KEY_UP) && snake->direction != DOWN)
    {
        snake->direction = UP;
    }
    if (IsKeyPressed(KEY_DOWN) && snake->direction != UP)
    {
        snake->direction = DOWN;
    }
}

void MoveHead(Snake *snake)
{
    switch (snake->direction)
    {
    case RIGHT:
        snake->snakeBody[0].col++;
        break;
    case LEFT:
        snake->snakeBody[0].col--;
        break;
    case UP:
        snake->snakeBody[0].row--;
        break;
    case DOWN:
        snake->snakeBody[0].row++;
        break;
    }
}

void MoveBody(Snake *snake)
{
    for (int i = snake->bodySegments - 1; i > 0; i--)
    {
        snake->snakeBody[i].row = snake->snakeBody[i - 1].row;
        snake->snakeBody[i].col = snake->snakeBody[i - 1].col;
    }
}

bool OutOfBounds(Snake *snake, int gridWidth, int gridHeight)
{
    if (snake->snakeBody[0].row >= gridHeight || snake->snakeBody[0].row < 0 ||
        snake->snakeBody[0].col >= gridWidth || snake->snakeBody[0].col < 0)
    {
        return true;
    }
    return false;
}

void WrapMovement(Snake *snake, int gridWidth, int gridHeight)
{
    if (snake->snakeBody[0].col >= gridWidth)
    {
        snake->snakeBody[0].col = 0;
    }
    else if (snake->snakeBody[0].col < 0)
    {
        snake->snakeBody[0].col = gridWidth - 1;
    }

    if (snake->snakeBody[0].row >= gridHeight)
    {
        snake->snakeBody[0].row = 0;
    }
    else if (snake->snakeBody[0].row < 0)
    {
        snake->snakeBody[0].row = gridHeight - 1;
    }
}

void UpdateSnakePosition(Snake *snake, int gridWidth, int gridHeight)
{
    GetInput(snake);
    MoveBody(snake);
    MoveHead(snake);

    if (OutOfBounds(snake, gridWidth, gridHeight))
    {
        WrapMovement(snake, gridWidth, gridHeight);
    }
}

