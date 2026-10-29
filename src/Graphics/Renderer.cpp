#include "Renderer.h"
#include "Sprite.h"

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

static uint32_t g_FrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

static BITMAPINFO g_BitmapInfo;

void RendererInitialize() {
    ZeroMemory(&g_BitmapInfo, sizeof(g_BitmapInfo));

    g_BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    g_BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    g_BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    g_BitmapInfo.bmiHeader.biPlanes = 1;
    g_BitmapInfo.bmiHeader.biBitCount = 32;
    g_BitmapInfo.bmiHeader.biCompression = BI_RGB;
}

void Clear(unsigned int color) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        g_FrameBuffer[i] = color;
    }
    
}

void DrawPixel(int x, int y, unsigned int color) {
    if (x < 0 || x >= SCREEN_WIDTH)
        return;

    if (y < 0 || y >= SCREEN_HEIGHT)
        return;
        
    g_FrameBuffer[y * SCREEN_WIDTH + x] = color;
}

void DrawRect(int x, int y, int width, int height, unsigned int color) {
    for (int py = 0; py < height; py++) {
        for (int px = 0; px < width; px++) {
            DrawPixel(x + px, y + py, color);
        }
    }
}

void DrawSprite(int x, int y, const Sprite& sprite) {
    for (int sy = 0; sy < sprite.Height; sy++) {
        for (int sx = 0; sx < sprite.Width; sx++) {
            uint32_t color = sprite.Pixel[sy * sprite.Width + sx];

            if (color != 0x00000000) {
                DrawPixel(x + sx, y + sy, color);
            }     
        }
    }
}

void RendererPresent(HWND window) {
    HDC dc = GetDC(window);

    RECT rect;
    GetClientRect(window, &rect);

    StretchDIBits(dc, 0, 0, rect.right, rect.bottom, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, g_FrameBuffer, &g_BitmapInfo, DIB_RGB_COLORS, SRCCOPY);
    ReleaseDC(window, dc);
}