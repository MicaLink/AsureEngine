#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }
    return DefWindowProc(hwnd, msg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int) {
    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"AzureWindow";

    if (!RegisterClassW(&wc)) {
        MessageBoxW(nullptr, L"Failed to register window class", L"Azure Engine", MB_OK | MB_ICONERROR);
        return -1;
    }

    HWND window = CreateWindowExW(
        0,
        L"AzureWindow",
        L"Azure Engine",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        800,
        600,
        nullptr,
        nullptr,
        hInstance,
        nullptr
    );

    if (!window) {
        MessageBoxW(nullptr, L"Failed to create window", L"Azure Engine", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(window, SW_SHOW);

    MSG msg = {};
    while (GetMessageW(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return static_cast<int>(msg.wParam);
}