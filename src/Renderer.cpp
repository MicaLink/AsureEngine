#include "Renderer.h"
#include "Sprite.h"

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

static uint32_t FrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

static BITMAPINFO BitmapInfo;

void RendererInitialize() {
    ZeroMemory(&BitmapInfo, sizeof(BitmapInfo));

    BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;
}

void Clear(uint32_t color) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        FrameBuffer[i] = color;
    }
    
}

void DrawPixel(int x, int y, unsigned int color) {
    if (x < 0 || x >= SCREEN_WIDTH)
        return;

    if (y < 0 || y >= SCREEN_HEIGHT)
        return;
        
    FrameBuffer[y * SCREEN_WIDTH + x] = color;
}

void DrawRect(int x, int y, int width, int height, uint32_t color) {
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

            if (color != TRANSPARENT_COLOR) {
                DrawPixel(x + sx, y + sy, color);
            }
        }
        
    }
    
}

void Present(HWND window) {
    HDC dc = GetDC(window);

    RECT rect;
    GetClientRect(window, &rect);

    StretchDIBits(dc, 0, 0, rect.right, rect.bottom, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, FrameBuffer, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);
    ReleaseDC(window, dc);
}