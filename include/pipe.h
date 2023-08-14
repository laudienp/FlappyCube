#ifndef PIPE_H
#define PIPE_H

#include "raylib.h"

#define PIPE_WIDTH 20

#define SPACING 100

typedef struct Pipe
{
    float positionX;
    float positionY;
    bool passed;
} Pipe;

void InitPipe(Pipe *pipe, float x);
void UpdatePipe(Pipe *pipe, float speed);
void DrawPipe(Pipe *pipe, Color color);
bool CheckCollisionPipe(Pipe *pipe, Rectangle player);
bool CheckPass(Pipe *pipe);

#endif // PIPE_H