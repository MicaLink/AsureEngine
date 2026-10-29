//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

//=====================================================
// Variables globales
//=====================================================

static bool g_Running = true;

static float g_DeltaTime = 0.0f;
static float g_FPS = 0.0f;

//=====================================================
// Procédure de fenêtre
//=====================================================

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
    // Classe de fenêtre
    //-------------------------------------------------

    WNDCLASSA wc {};

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "AzureEngineWindow";

    if (!RegisterClassA(&wc)) {
        MessageBoxA(nullptr, "Impossible d'enregistrer la classe.", "Erreur", MB_OK | MB_ICONERROR);
        return -1;
    }

    //-------------------------------------------------
    // Création de la fenêtre
    //-------------------------------------------------

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, nullptr, nullptr, hInstance, nullptr);

    if (!window) {
        MessageBoxA(nullptr, "Impossible de créer la fenetre.", "Erreur", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(window, nCmdShow);
    UpdateWindow(window);

    //-------------------------------------------------
    // Timer haute précision
    //-------------------------------------------------

    LARGE_INTEGER frequency;
    LARGE_INTEGER lastCouter;

    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&lastCouter);

    //-------------------------------------------------
    // Boucle principale
    //-------------------------------------------------

    MSG message = {};

    while (g_Running) {

        //---------------------------------------------
        // Temps
        //---------------------------------------------

        LARGE_INTEGER currentCounter;
        QueryPerformanceCounter(&currentCounter);

        g_DeltaTime = static_cast<float>(currentCounter.QuadPart - lastCouter.QuadPart) / static_cast<float>(frequency.QuadPart);
        lastCouter = currentCounter;

        if (g_DeltaTime > 0.0f) {
            g_FPS = 1.0f / g_DeltaTime;
        }
        
        //---------------------------------------------
        // Titre fenêtre
        //---------------------------------------------

        char title[256];

        sprintf_s(title, "Azure Engine | FPS : %.0f");
        SetWindowTextA(window, title);

        //---------------------------------------------
        // Messages Windows
        //---------------------------------------------

        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                g_Running = false;
            }

            TranslateMessage(&message);
            DispatchMessage(&message);
        }


        

        //-------------------------------------------------
        // UPDATE
        //-------------------------------------------------

        // TODO :
        // Input
        // Physique
        // Audio
        // IA

        //-------------------------------------------------
        // RENDER
        //-------------------------------------------------

        HDC dc = GetDC(window);

        RECT rect;
        GetClientRect(window, &rect);

        FillRect(dc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        ReleaseDC(window, dc);

        //---------------------------------------------
        // Limiter CPU
        //---------------------------------------------
        
        Sleep(1);
    }
    return 0;
}