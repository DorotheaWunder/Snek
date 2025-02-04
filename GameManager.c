#include "gamemanager.h"

GameManager game;

void InitGame()
{
    InitWindow(800, 800, "Snake");
    InitializeLevelGrid();
    InitializeSnakeValues();

}

void UpdateGame()
{
    //------------- needs content
}

void DrawGame()
{
    DrawLevelGrid();
    DrawSnake(&game.snake);
}
