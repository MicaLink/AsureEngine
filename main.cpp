//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

static bool g_Running = true;

//-----------------------------------------------------
// Procédure de fenêtre
//-----------------------------------------------------

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        case WM_CLOSE:
            g_Running = false;
            DestroyWindow(hwnd);
            return 0;
    
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//-----------------------------------------------------
// Point d'entrée
//-----------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    //-------------------------------------------------
    // Définition de la classe de fenêtre
    //-------------------------------------------------

    WNDCLASSA wc {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "AzureEngineWindow";

    RegisterClassA(&wc);

    //-------------------------------------------------
    // Création de la fenêtre
    //-------------------------------------------------

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, nullptr, nullptr, hInstance, nullptr);

    if (!window) {
        MessageBoxA(nullptr, "Impossible de créer la fenetre.", "Erreur", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(window, nCmdShow);

    //-------------------------------------------------
    // Boucle principale
    //-------------------------------------------------

    MSG message = {};

    while (g_Running) {
        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        //-------------------------------------------------
        // UPDATE
        //-------------------------------------------------

        // Logique du moteur

        //-------------------------------------------------
        // RENDER
        //-------------------------------------------------

        HDC dc = GetDC(window);

        RECT rect;
        GetClientRect(window, &rect);

        FillRect(dc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        ReleaseDC(window, dc);
    }
    return 0;
}