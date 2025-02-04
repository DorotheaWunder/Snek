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

void SetDirection(Snake *snake)
{
    int headRow = snake->snakeBody[0].row;
    int headCol = snake->snakeBody[0].col;

    switch (snake->direction)
    {
    case RIGHT:
        headCol++;
        break;
    case LEFT:
        headCol--;
        break;
    case UP:
        headRow--;
        break;
    case DOWN:
        headRow++;
        break;
    }
}

void MoveSnake(Snake *snake)
{
    int prevRow = snake->snakeBody[0].row;
    int prevCol = snake->snakeBody[0].col;

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

void ApplyFullMovement(Snake *snake, int gridWidth, int gridHeight)
{
    if (OutOfBounds(snake, gridWidth, gridHeight))
    {
        WrapMovement(snake, gridWidth, gridHeight);
    }
    else
    {
        MoveSnake(snake);
    }
}

//and now put everything into a method that goes into Update