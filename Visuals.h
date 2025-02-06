#ifndef VISUALS_H
#define VISUALS_H

#include "raylib.h"
#include "grid.h"
#include "SnakeArray.h"





void DrawCell(Cell *cell);
void DrawLevelGrid();
void DrawSnakeArray(Snake *snake);

#endif //VISUALS_H
