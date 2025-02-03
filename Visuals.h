#ifndef VISUALS_H
#define VISUALS_H

#include "raylib.h"
#include "grid.h"
#include "snake.h"





void DrawCell(Cell *cell);
void DrawLevelGrid();
void DrawSnake(Snake *snake);

#endif //VISUALS_H
