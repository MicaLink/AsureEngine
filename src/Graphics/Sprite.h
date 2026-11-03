#pragma once

#include <cstdint>

#include "../Core/Colors.h"

struct Sprite {
    int Width;
    int Height;

    const uint32_t* Pixels;
};