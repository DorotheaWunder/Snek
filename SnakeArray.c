#include "raylib.h"
#include "grid.h"
#include "SnakeArray.h"

Snake InitializeSnakeValues()
{
    Snake snake;

    snake.bodySegments = 20;
    snake.headIndex = 19;
    snake.tailIndex = 0;

    snake.bodyColor = DARKGREEN;
    snake.headColor = GREEN;
    snake.direction = RIGHT;

    for (int i = 0; i < snake.bodySegments; i++)
    {
        snake.snakeBody[i] = InitializeCellValues(5, 5 - i, CELLSIZE, SNAKE);
        if (i == 0)
        {
            snake.snakeBody[i].cell_color = snake.headColor;
        }
        else
        {
            snake.snakeBody[i].cell_color = snake.bodyColor;
        }
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

    Die(snake);

    if (OutOfBounds(snake, gridWidth, gridHeight))
    {
        WrapMovement(snake, gridWidth, gridHeight);
    }
}

bool CollidedWithSelf(Snake *snake)
{
    int headRow = snake->snakeBody[0].row;
    int headCol = snake->snakeBody[0].col;

    if (levelGrid[headRow][headCol].content == SNAKE)
    {
        return true;
    }

    return false;
}

void Die(Snake *snake)
{
    if (CollidedWithSelf(snake))
    {
        snake->headColor = WHITE;
        DrawText("GAME OVER!", 350, 400, 20, RED);
    }
}