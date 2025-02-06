#ifndef VISUALS_H
#define VISUALS_H

#include "raylib.h"
#include "grid.h"
#include "SnakeArray.h"
#include "food.h"





void DrawCell(Cell *cell);
void DrawLevelGrid();
void DrawSnakeArray(Snake *snake);
void DrawFood(Cell *food);

#endif //VISUALS_H
