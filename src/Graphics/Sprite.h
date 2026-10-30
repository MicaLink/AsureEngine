#pragma once

#include <cstdint>

struct Sprite {
    int Width;
    int Height;
    const uint32_t* Pixels;
};