#pragma once

#include "Sprite.h"

struct Animation {
    const Sprite* Frames;

    int FrameCount;

    float FrameDuration;

    float Timer;

    int CurrentFrame;
};

void UpdateAnimation(Animation& animation, float deltaTime);
const Sprite& GetAnimationFrame(const Animation& animation);