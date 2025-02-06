#include <stdio.h>
#include "raylib.h"
#include "gamemanager.h"

int main(void)
{
    InitGame();

    while (!WindowShouldClose())
    {
        BeginDrawing();


        GameManager game;

        ClearBackground(RAYWHITE);


        UpdateGame();
        DrawGame();

        //GameManager game;
        //GameFlow(&game);



        EndDrawing();
    }

    CloseWindow();
    return 0;
}

