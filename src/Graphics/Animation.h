#pragma once

#include "Sprite.h"

struct Animation {
    const Sprite* Frames = nullptr;

    int FrameCount = 0;

    float FrameDuration = 0.0f;

    float Timer = 0.0f;

    int CurrentFrame = 0;
};

void UpdateAnimation(Animation& animation, float deltaTime);
const Sprite& GetAnimationFrame(const Animation& animation);