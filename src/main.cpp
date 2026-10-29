//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

#include "Timer.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

static bool g_Running = true;

static float g_DeltaTime = 0.0f;
static float g_FPS = 0.0f;

//-----------------------------------------------------
// Procédure de fenêtre
//-----------------------------------------------------

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message) {
        case WM_CLOSE:
            g_Running = false;
            DestroyWindow(hwnd);
            return 0;
    
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, message, wParam, lParam);
}

//-----------------------------------------------------
// Point d'entrée
//-----------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    //-------------------------------------------------
    // Classe de fenêtre
    //-------------------------------------------------

    WNDCLASSA windowClass {};

    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = "AzureEngineWindow";

    if (!RegisterClassA(&windowClass)) {
        MessageBoxA(nullptr, "Impossible d'enregistrer la classe.", "Erreur", MB_OK | MB_ICONERROR);
        return -1;
    }

    //-------------------------------------------------
    // Création de la fenêtre
    //-------------------------------------------------

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, nullptr, nullptr, hInstance, nullptr);

    if (!window) {
        MessageBoxA(nullptr, "Impossible de créer la fenêtre.", "Erreur", MB_OK | MB_ICONERROR);
        return -1;
    }

    ShowWindow(window, nCmdShow);
    UpdateWindow(window);

    //-------------------------------------------------
    // Timer
    //-------------------------------------------------

    Timer timer;
    timer.Initialize();

    //-------------------------------------------------
    // Boucle principale
    //-------------------------------------------------

    MSG message = {};

    while (g_Running) {

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

        //---------------------------------------------
        // Temps
        //---------------------------------------------

        timer.Update();

        g_DeltaTime = timer.GetDeltaTime();
        g_FPS = timer.GetFPS();
        
        //-------------------------------------------------
        // UPDATE
        //-------------------------------------------------

        // TODO :
        // Input
        // Gameplay
        // Audio
        // Scripts

        //-------------------------------------------------
        // RENDER
        //-------------------------------------------------

        HDC dc = GetDC(window);

        RECT clientRect;
        GetClientRect(window, &clientRect);

        FillRect(dc, &clientRect, (HBRUSH)GetStockObject(BLACK_BRUSH));

        ReleaseDC(window, dc);

        //---------------------------------------------
        // Titre fenêtre
        //---------------------------------------------

        char title[256];

        sprintf_s(title, "Azure Engine | FPS : %.0f", g_FPS);

        SetWindowTextA(window, title);

        //---------------------------------------------
        // Pause légère
        //---------------------------------------------

        Sleep(1);
    }
    return 0;
}