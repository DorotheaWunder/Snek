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

        DrawGame();



        EndDrawing();
    }

    CloseWindow();
    return 0;
}

