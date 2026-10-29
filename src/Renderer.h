#pragma once

#include <Windows.h>

void RendererInitialize();

void RendererBeginFrame();
void RendererEndFrame(HWND window);

void Clear(unsigned int color);
void DrawPixel(int x, int y, unsigned int color);
void DrawRect(int x, int y, int width, int height, unsigned int color);
