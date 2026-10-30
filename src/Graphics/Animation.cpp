#include "Animation.h"

void UpdateAnimation(Animation& animation, float deltaTime){
    animation.Timer += deltaTime;

    if(animation.Timer >= animation.FrameDuration) {
        animation.Timer = 0.0f;
        animation.CurrentFrame++;

        if (animation.CurrentFrame >= animation.FrameCount) {
            animation.CurrentFrame = 0;
        }
    }
}

const Sprite& GetAnimationFrame(const Animation& animation) {
    return animation.Frames[animation.CurrentFrame];
}