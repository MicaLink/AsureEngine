#include <windows.h>
#include <cstdint>
#include <cstdio>

//====================================================
// Configuration
//====================================================

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

constexpr int WORLD_WIDTH = 2000;
constexpr int WORLD_HEIGHT = 2000;

constexpr int TILE_SIZE = 32;

constexpr uint32_t BACKGROUND_COLOR = 0x00102030;
constexpr uint32_t COLOR_GRID = 0x00303030;

constexpr uint32_t TRANSPARENT_COLOR = 0xFFFF00FF;

//====================================================
// Structures
//====================================================

struct Sprite {
    int Width;
    int Height;
    const uint32_t* Pixels;
};

//====================================================
// Variables globales
//====================================================

bool Running = true;
bool Keys[256] = {};

int PlayerX = 100;
int PlayerY = 100;

int CameraX = 0;
int CameraY = 0;

float DeltaTime = 0.0f;
float FPS = 0.0f;

uint32_t FrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

BITMAPINFO BitmapInfo = {};

//====================================================
// Sprite du héros
//====================================================

uint32_t HeroPixels[64] = {
    0xFFFF00FF,0xFFFF00FF,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0xFFFF00FF,0xFFFF00FF,
    0xFFFF00FF,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0xFFFF00FF,
    0x0000FF00,0x0000FF00,0x00FFFFFF,0x0000FF00,0x0000FF00,0x00FFFFFF,0x0000FF00,0x0000FF00,
    0x0000FF00,0x0000FF00,0x00000000,0x0000FF00,0x0000FF00,0x00000000,0x0000FF00,0x0000FF00,
    0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,0x0000FF00,
    0xFFFF00FF,0x0000FF00,0x0000FF00,0x00FF0000,0x00FF0000,0x0000FF00,0x0000FF00,0xFFFF00FF,
    0xFFFF00FF,0x0000FF00,0x0000FF00,0xFFFF0000,0xFFFF0000,0x0000FF00,0x0000FF00,0xFFFF00FF,
    0xFFFF00FF,0xFFFF00FF,0x0000FF00,0xFFFF00FF,0xFFFF00FF,0x0000FF00,0xFFFF00FF,0xFFFF00FF
};

Sprite Hero = {8, 8, HeroPixels};

//====================================================
// Dessin bas niveau
//====================================================

void DrawPixel(int x, int y, uint32_t color) {
    if (x < 0 || x >= SCREEN_WIDTH) return;
    if (y < 0 || y >= SCREEN_HEIGHT ) return;
    
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

void DrawSprite(int worldX, int worldY, const Sprite& sprite) {
    int screenX = worldX - CameraX;
    int screenY = worldY - CameraY;

    for (int sy = 0; sy < sprite.Height; sy++) {
        for (int sx = 0; sx < sprite.Width; sx++) {
            uint32_t color = sprite.Pixels[sy * sprite.Width + sx];
            
            if (color != TRANSPARENT_COLOR) {
                DrawPixel(screenX + sx, screenY + sy, color);
            }   
        }
    }
}

//====================================================
// Logique Jeu
//====================================================

void Update() {
    constexpr float Speed = 120.0f;

    if (Keys[VK_LEFT])
        PlayerX -= static_cast<int>(Speed * DeltaTime);

    if (Keys[VK_RIGHT])
        PlayerX += static_cast<int>(Speed * DeltaTime);

    if (Keys[VK_UP])
        PlayerY -= static_cast<int>(Speed * DeltaTime);

    if (Keys[VK_DOWN])
        PlayerY += static_cast<int>(Speed * DeltaTime);

    if (PlayerX < 0)
        PlayerX = 0;
    
    if (PlayerY < 0)
        PlayerY = 0;

    if (PlayerX > WORLD_WIDTH - Hero.Width)
        PlayerX = WORLD_WIDTH - Hero.Width;

    if (PlayerY > WORLD_HEIGHT - Hero.Height)
        PlayerY = WORLD_HEIGHT - Hero.Height;

    CameraX = PlayerX - SCREEN_WIDTH / 2;
    CameraY = PlayerY - SCREEN_HEIGHT / 2;

    if (CameraX > WORLD_WIDTH - SCREEN_WIDTH)
        CameraX = WORLD_WIDTH - SCREEN_WIDTH;

    if (CameraY > WORLD_HEIGHT - SCREEN_HEIGHT)
        CameraY = WORLD_HEIGHT - SCREEN_HEIGHT;
}

//====================================================
// Rendu
//====================================================

void Render(HWND hwnd) {
    Clear(BACKGROUND_COLOR);

    for (int y = 0; y < WORLD_HEIGHT; y += TILE_SIZE) {
        for (int x = 0; x < WORLD_WIDTH; x += TILE_SIZE) {
            DrawRect(x - CameraX, y - CameraY, TILE_SIZE - 1, TILE_SIZE - 1, COLOR_GRID);
        }
        
    }
    
    DrawSprite(PlayerX, PlayerY, Hero);

    HDC dc = GetDC(hwnd);

    RECT rc;
    GetClientRect(hwnd, &rc);

    int width = rc.right - rc.left;
    int height = rc.bottom - rc.top;

    StretchDIBits(dc, 0, 0, width, height, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, FrameBuffer, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);

    ReleaseDC(hwnd, dc);
}

//====================================================
// Fenêtre Win32
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
    BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;
    
    const char* ClassName = "AzureEngineWindow";

    WNDCLASSA wc = {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = ClassName;

    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(0, ClassName, "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);

    LARGE_INTEGER Frequency;
    LARGE_INTEGER LastCounter;

    QueryPerformanceFrequency(&Frequency);
    QueryPerformanceCounter(&LastCounter);

    MSG msg = {};

    while (Running) {
        LARGE_INTEGER CurrentCounter;
        QueryPerformanceCounter(&CurrentCounter);

        DeltaTime = static_cast<float>(CurrentCounter.QuadPart - LastCounter.QuadPart) / static_cast<float>(Frequency.QuadPart);

        LastCounter = CurrentCounter;

        if (DeltaTime > 0.0f)
            FPS = 1.0f / DeltaTime;

        char Title[128];

        sprintf_s(Title, "Azure Engine - FPS %.0f", FPS);

        SetWindowTextA(hwnd, Title);

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        Update();
        Render(hwnd);
    }
    return 0;
}