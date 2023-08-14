#include<stdbool.h>
#include<stdio.h>
#include "raylib.h"
#include "player.h"
#include "pipe.h"
#include "sound.h"
#include "const.h"


#define PIPE_SPACING 100
#define GAME_SPEED 100
#define PIPE_COUNT (SCREEN_WIDTH + 100) / PIPE_SPACING

Pipe pipes[PIPE_COUNT];

bool gameOver;
bool started;

int score;

Color backgroundColor;
Color blockColor;


void InitGame(void);
void UpdateLoop(void);
void RenderLoop(void);

int main(void)
{
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Floppa bird");
    InitAudioDevice();

    SetTargetFPS(60);

    InitSound();

    InitGame();

    while(!WindowShouldClose())
    {
        UpdateLoop();

        RenderLoop();
    }

    CloseWindow();
    CloseAudioDevice();

    return 0;
}

void InitGame(void)
{
    gameOver = false;
    started = false;
    score = 0;

    for(int i = 0; i < PIPE_COUNT; i++)
        InitPipe(&pipes[i], i * PIPE_SPACING); 

    InitPlayer();

    backgroundColor = RAYWHITE;
    blockColor = PBLACK;
}

void UpdateLoop(void)
{
    if(!started && IsKeyPressed(KEY_SPACE))
        started = true;

    if(!gameOver && started)
    {
        UpdatePlayer();

        for(int i = 0; i < PIPE_COUNT; i++)
        {
            UpdatePipe(&pipes[i], GAME_SPEED);
            if(CheckPass(&pipes[i]))
            {
                score += 1;
                if(score % 50 == 0)
                {
                    Color temp = backgroundColor;
                    backgroundColor = blockColor;
                    blockColor = temp;
                    PlayScore2Sound();
                }
                else if(score % 10 == 0)
                    PlayScore2Sound();
                else
                    PlayScoreSound();
            }
        }

        // collision with pipes
        for(int i = 0; i < PIPE_COUNT; i++)
            if(CheckCollisionPipe(&pipes[i], GetPlayerRectangle()))
            {
                PlayFailSound();
                gameOver = true;
            }
                

        // collision with ground
        if(CheckGround())
        {
            PlayFailSound();
            gameOver = true;
        } 
    }

    //restart game
    if(gameOver && IsKeyPressed(KEY_ENTER))
        InitGame();
}

void RenderLoop(void)
{
    BeginDrawing();

    ClearBackground(backgroundColor);
    
    //DrawText("Floppa bird Floppa bird Floppa bird", 190, 200, 20, LIGHTGRAY);

    //player position
    DrawPlayer(blockColor);
    
    for(int i = 0; i < PIPE_COUNT; i++)
        DrawPipe(&pipes[i], blockColor);

    if(gameOver)
    {
        DrawText("GAME OVER", SCREEN_WIDTH/2 - 180, SCREEN_HEIGHT/2 - 30, 60, RED);
        DrawText("Press ENTER to RESTART", SCREEN_WIDTH/2 - 130, SCREEN_HEIGHT/2 + 40, 20, RED);
    }

    if(!started)
        DrawText("Press SPACE to JUMP", SCREEN_WIDTH/2 - 120, 100, 20, LIGHTGRAY);
        
    char snum[100];
    sprintf(snum, "SCORE:%d", score);
    //draw score
    DrawText(snum, 10, 10, 30, RED);

    EndDrawing();
}