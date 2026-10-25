#include <windows.h>
#include <cstdint>

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

uint32_t FrameBuffer[SCREEN_WIDTH * SCREEN_HEIGHT];

BITMAPINFO BitmapInfo = {};

bool Running = true;

void DrawPixel(int x, int y, uint32_t color) {
    if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
        return;
    }
    FrameBuffer[y * SCREEN_WIDTH + x] = color;
}

void Clear(uint32_t color) {
    for (int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++) {
        FrameBuffer[i] = color;
    }
}

void DrawRect(int x, int y, int w, int h, uint32_t color) {
    for (int py = 0; py < h; py++) {
        for (int px = 0; px < w; px++) {
            DrawPixel(x + px, y + py, color);
        }
        
    }
    
}

void Update() {

}

void Render(HWND hwnd) {
    Clear(0x00102030);

    DrawRect(100, 60, 120, 80, 0x00FF0000);

    HDC dc = GetDC(hwnd);

    RECT rect;
    GetClientRect(hwnd, &rect);

    const int width = rect.right - rect.left;
    const int height = rect.bottom - rect.top;

    StretchDIBits(dc, 0, 0, width, height, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, FrameBuffer, &BitmapInfo, DIB_RGB_COLORS, SRCCOPY);

    ReleaseDC(hwnd, dc);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            Running = false;
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    const char* ClassName = "AzureEngineWindow";

    WNDCLASSA wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = ClassName;

    RegisterClassA(&wc);

    BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    BitmapInfo.bmiHeader.biWidth = SCREEN_WIDTH;
    BitmapInfo.bmiHeader.biHeight = -SCREEN_HEIGHT;
    BitmapInfo.bmiHeader.biPlanes = 1;
    BitmapInfo.bmiHeader.biBitCount = 32;
    BitmapInfo.bmiHeader.biCompression = BI_RGB;

    HWND hwnd = CreateWindowExA(0, ClassName, "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 800, 600, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(hwnd, nCmdShow);

    MSG msg;

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