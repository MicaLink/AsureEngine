#include "Input.h"

#include <Windows.h>

namespace {
    bool g_Keys[256] = {};
}

void InputInitialize() {
    for (int i = 0; i < 256; i++) {
        g_Keys[i] = false;
    }
}

void InputUpdate() {
    for (int i = 0; i < 256; i++)
    {
        g_Keys[i] = (GetAsyncKeyState(i) & 0x8000) != 0;
    }
}

bool IsKeyDown(int key)
{
    if (key < 0 || key > 255) {
        return false;
    }

    return g_Keys[key];
}