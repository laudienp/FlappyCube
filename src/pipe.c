#include "pipe.h"
#include "raylib.h"
#include "const.h"

const float pipeHeight = (SCREEN_HEIGHT/2.0f - SPACING/2.0f);

void InitPipe(Pipe *pipe, float x)
{
    pipe->positionX = SCREEN_WIDTH + x;
    //pipe->positionY = SCREEN_HEIGHT - pipe->height + GetRandomValue(-20, 20);
    pipe->positionY = GetRandomValue(-50, 50);

    pipe->passed = false;
}

void UpdatePipe(Pipe *pipe, float speed)
{
    pipe->positionX -= speed * GetFrameTime();

    if(pipe->positionX < -100)
        InitPipe(pipe, 0);
}

void DrawPipe(Pipe *pipe, Color color)
{
    DrawRectangle(pipe->positionX, 0, PIPE_WIDTH, pipeHeight - pipe->positionY, color);
    DrawRectangle(pipe->positionX, -pipe->positionY + SCREEN_HEIGHT - pipeHeight, PIPE_WIDTH, pipeHeight + pipe->positionY, color);

    // DrawRectangle(pipe->positionX, pipe->positionY - pipe->height*2, pipe->width, pipe->height, BLACK);
    // DrawRectangle(pipe->positionX, pipe->positionY, pipe->width, pipe->height, BLACK);
}

bool CheckCollisionPipe(Pipe *pipe, Rectangle player)
{
    Rectangle pipeTop = {pipe->positionX, 0, PIPE_WIDTH, pipeHeight - pipe->positionY};
    Rectangle pipeBottom = {pipe->positionX, -pipe->positionY + SCREEN_HEIGHT - pipeHeight, PIPE_WIDTH, pipeHeight + pipe->positionY};

    return CheckCollisionRecs(player, pipeTop) || CheckCollisionRecs(player, pipeBottom);
}

bool CheckPass(Pipe *pipe)
{
    return !pipe->passed && (pipe->passed = pipe->positionX < SCREEN_WIDTH/2.0f);
}