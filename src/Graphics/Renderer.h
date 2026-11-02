#pragma once

#include <Windows.h>
#include <cstdint>

#include "Sprite.h"

constexpr int SCREEN_WIDTH  = 320;
constexpr int SCREEN_HEIGHT = 200;

void RendererInitialize();

void Clear(uint32_t color);
void DrawPixel(int x, int y, uint32_t color);
void DrawRect(int x, int y, int width, int height, uint32_t color);
void DrawSprite(int x, int y, const Sprite& sprite);

void RendererPresent(HWND window);