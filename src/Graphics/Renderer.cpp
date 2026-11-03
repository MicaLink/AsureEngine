#include "Renderer.h"
#include "../Core/Colors.h"
#include "Camera.h"

constexpr int PIXEL_COUNT = SCREEN_WIDTH * SCREEN_HEIGHT;

namespace {
    uint32_t g_FrameBuffer[PIXEL_COUNT];

    BITMAPINFO g_BitmapInfo = {};
}

//-----------------------------------------------------
// Initialisation
//-----------------------------------------------------

void RendererInitialize() {
    ZeroMemory(&g_BitmapInfo, sizeof(g_BitmapInfo));

    g_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    g_BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    g_BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    g_BitmapInfo.bmiHeader.biPlanes = 1;
    g_BitmapInfo.bmiHeader.biBitCount = 32;
    g_BitmapInfo.bmiHeader.biCompression = BI_RGB;
}

//-----------------------------------------------------
// Effacement framebuffer
//-----------------------------------------------------

void Clear(uint32_t color) {
    for (int i = 0; i < PIXEL_COUNT; i++) {
        g_FrameBuffer[i] = color;
    }
}

//-----------------------------------------------------
// Pixel
//-----------------------------------------------------

void DrawPixel(int x, int y, uint32_t color) {
    if (x < 0 || x >= SCREEN_WIDTH)
        return;

    if (y < 0 || y >= SCREEN_HEIGHT)
        return;
        
    g_FrameBuffer[y * SCREEN_WIDTH + x] = color;
}

//-----------------------------------------------------
// Rectangle écran
//-----------------------------------------------------

void DrawRect(int x, int y, int width, int height, uint32_t color) {
    for (int py = 0; py < height; py++) {
        for (int px = 0; px < width; px++) {
            DrawPixel(x + px, y + py, color);
        }
    }
}

//-----------------------------------------------------
// Rectangle monde
//-----------------------------------------------------

void DrawWorldRect(int x, int y, int width, int height, uint32_t color) {
    DrawRect(x - CameraX, y - CameraY, width, height, color);
}

//-----------------------------------------------------
// Sprite
//-----------------------------------------------------

void DrawSprite(int x, int y, const Sprite& sprite) {
    x -= CameraX;
    y -= CameraY;

    for (int sy = 0; sy < sprite.Height; sy++) {
        for (int sx = 0; sx < sprite.Width; sx++) {
            const uint32_t color = sprite.Pixels[sy * sprite.Width + sx];

            if (color == COLOR_TRANSPARENT)
                continue;

            DrawPixel(x + sx, y + sy, color);
        }
    }
}

//-----------------------------------------------------
// Présentation framebuffer
//-----------------------------------------------------

void RendererPresent(HWND window) {
    HDC dc = GetDC(window);

    RECT rect;
    GetClientRect(window, &rect);

    StretchDIBits(dc, 0, 0, rect.right, rect.bottom, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, g_FrameBuffer, &g_BitmapInfo, DIB_RGB_COLORS, SRCCOPY);
    ReleaseDC(window, dc);
}