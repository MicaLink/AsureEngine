#pragma once

#include "Sprite.h"

struct Animation {
    const Sprite* Frames;

    int FrameCount;

    float FrameDuration;

    float Timer;

    int CurrentFrame;
};

void UpdateAnimation(Animation& animationn, float deltaTime);
const Sprite& GetAnimationFrame(const Animation& animation);