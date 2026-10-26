#include <windows.h>
#include <cstdint>

//====================================================
// Configuration
//====================================================

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

//====================================================
// Variables globales
//====================================================
bool Running = true;

bool Keys[256] = {};

int PlayerX = 100;
int PlayerY = 100;

uint32_t FrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];
uint32_t PlayerSpritePixels[16 * 16];

BITMAPINFO BitmapInfo = {};

//====================================================
// Dessin
//====================================================

void DrawPixel(int x, int y, uint32_t color) {
    if (x < 0 || x >= SCREEN_WIDTH)
        return;
    
    if (y < 0 || y >= SCREEN_HEIGHT )
        return;
    
    FrameBuffer[y * SCREEN_WIDTH + x] = color;
}

void Clear(uint32_t color) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        FrameBuffer[i] = color;
    }
}

void DrawRect(int x, int y, int width, int height, uint32_t color) {
    for (int py = 0; py < height; py++) {
        for (int px = 0; px < width; px++) {
            DrawPixel(x + px, y + py, color);
        }   
    }
}


void DrawSprite(int x, int y, const uint32_t* pixels, int width, int height) {
    for (int py = 0; py < height; py++) {
        for (int px = 0; px < width; px++) {
            uint32_t color = pixels[py * width + px];
            if (color != 0xFFFF00FF) {
                DrawPixel(x + px, y + py, color);
            }   
        }
    }
}

//====================================================
// Jeu
//====================================================

void Update() {
    const int Speed = 2;

    if (Keys[VK_LEFT])
        PlayerX -= Speed;

    if (Keys[VK_RIGHT])
        PlayerX += Speed;

    if (Keys[VK_UP])
        PlayerY -= Speed;

    if (Keys[VK_DOWN])
        PlayerY += Speed;
}

void Render(HWND hwnd) {
    Clear(0x00102030);

    DrawSprite(PlayerX, PlayerY, PlayerSpritePixels, 16, 16);

    HDC dc = GetDC(hwnd);

    RECT rect;
    GetClientRect(hwnd, &rect);

    int windowWidth = rect.right - rect.left;
    int windowHeight = rect.bottom - rect.top;

    StretchDIBits(dc, 0, 0, windowWidth, windowHeight, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, FrameBuffer, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);

    ReleaseDC(hwnd, dc);
}

//====================================================
// Fenêtre
//====================================================

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_KEYDOWN:
            Keys[wParam & 255] = true;
            return 0;

        case WM_KEYUP:
            Keys[wParam & 255] = false;
            return 0;

        case WM_DESTROY:
            Running = false;
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

//====================================================
// Point d'entrée
//====================================================

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    // Initialisation du framebuffer

    BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;

     // Initialisation du sprite joueur

    for (int i = 0; i < 16 * 16; i++) {
        PlayerSpritePixels[i] = 0x0000FF00;
    }
    
    const char* ClassName = "AzureEngineWindow";

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = ClassName;

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(0, ClassName, "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);

    MSG msg = {};

    while (Running) {
        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Update();
        Render(hwnd);
    }
    return 0;
}