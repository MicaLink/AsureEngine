#pragma once

#include <Windows.h>
#include <cstdint>

struct Sprite;

void RendererInitialize();

void Clear(uint32_t color);
void DrawPixel(int x, int y, uint32_t color);
void DrawRect(int x, int y, int width, int height, uint32_t color);
void DrawSprite(int x, int y, const Sprite& sprite);

void Present(HWND window);


