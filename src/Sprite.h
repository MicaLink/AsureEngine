#pragma once

#include <cstdint>

struct Sprite {
    int Width;
    int Height;
    const uint32_t* Pixel;
};

constexpr uint32_t TRANSPARENT_COLOR = 0xFFFF00FF;

extern Sprite Hero;