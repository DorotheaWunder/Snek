#include "gamemanager.h"

GameManager game;

void InitGame()
{
    InitWindow(800, 800, "Snake");
    InitializeLevelGrid();
}

void UpdateGame()
{
    //------------- needs content
}

void DrawGame()
{
    DrawLevelGrid();
}
