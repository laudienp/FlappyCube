#include "sound.h"
#include "raylib.h"

Sound scoreSound;
Sound score2Sound;
Sound failSound;
Sound jumpSound;

void InitSound(void)
{
    scoreSound = LoadSound("resources/Select 1.wav");
    score2Sound = LoadSound("resources/Fruit collect 1.wav");
    failSound = LoadSound("resources/Boss hit 1.wav");
    jumpSound = LoadSound("resources/Text 1.wav");
}

void PlayScoreSound(void)
{
    PlaySound(scoreSound);
}

void PlayScore2Sound(void)
{
    PlaySound(score2Sound);
}

void PlayFailSound(void)
{
    PlaySound(failSound);
}

void PlayJumpSound(void)
{
    PlaySound(jumpSound);
}