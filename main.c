#include <stdio.h>
#include "raylib.h"
#include "gamemanager.h"

int main(void)
{
    InitGame();

    while (!WindowShouldClose())
    {
        BeginDrawing();



        ClearBackground(RAYWHITE);
        UpdateGame();
        DrawGame();


        EndDrawing();
    }

    CloseWindow();
    return 0;
}

