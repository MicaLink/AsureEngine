#pragma once

#include <Windows.h>

#include "Sprite.h"

void RendererInitialize();

void Clear(unsigned int color);
void DrawPixel(int x, int y, unsigned int color);
void DrawRect(int x, int y, int width, int height, unsigned int color);
void DrawSprite(int x, int y, const Sprite& sprite);

void RendererPresent(HWND window);


