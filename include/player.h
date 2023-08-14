#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 10

void InitPlayer(void);

void UpdatePlayer(void);

void DrawPlayer(Color color);

bool CheckGround();

Rectangle GetPlayerRectangle();

#endif // PLAYER_H