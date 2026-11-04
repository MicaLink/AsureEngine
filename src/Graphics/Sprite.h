#pragma once

#include <cstdint>

struct Sprite {
    int Width = 0;
    int Height = 0;

    const uint32_t* Pixels;
};