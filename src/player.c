#include "player.h"
#include "const.h"
#include "math.h"
#include "sound.h"

float playerPositionX;
float playerPositionY;

float playerVelocity;

void InitPlayer(void)
{
    playerPositionX = SCREEN_WIDTH/2 - PLAYER_WIDTH;
    playerPositionY = SCREEN_HEIGHT/2 - PLAYER_HEIGHT;

    playerVelocity = 0.0f;
}

void UpdatePlayer(void)
{
    if(IsKeyPressed(KEY_SPACE))
    {
        playerVelocity = sqrtf(-2 * GRAVITY * 0.5f);
        PlayJumpSound();
    }
        
    else
        playerVelocity += GRAVITY * GetFrameTime();

    playerPositionY -= playerVelocity;
}

void DrawPlayer(Color color)
{
    DrawRectangle(playerPositionX, playerPositionY, PLAYER_WIDTH, PLAYER_HEIGHT, color);
}

bool CheckGround()
{
    return playerPositionY > SCREEN_HEIGHT - PLAYER_HEIGHT;
}

Rectangle GetPlayerRectangle(void)
{
    Rectangle rect = {playerPositionX, playerPositionY, PLAYER_WIDTH, PLAYER_HEIGHT};
    return rect;
}