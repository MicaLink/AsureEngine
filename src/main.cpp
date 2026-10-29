//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

#include "Timer.h"
#include "Input.h"
#include "Renderer.h"

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

static bool g_Running = true;

static float g_PlayerX = 100.0f;
static float g_PlayerY = 100.0f;

//-----------------------------------------------------
// Procédure de fenêtre
//-----------------------------------------------------

LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CLOSE:
            g_Running = false;
            DestroyWindow(hwnd);
            return 0;
    
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
    }

    return DefWindowProc(hwnd, msg, wParam, lParam);
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

    RegisterClassA(&wc);

    //-------------------------------------------------
    // Création de la fenêtre
    //-------------------------------------------------

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 1280, 720, nullptr, nullptr, hInstance, nullptr);

    ShowWindow(window, nCmdShow);

    //-------------------------------------------------
    // Timer
    //-------------------------------------------------

    Timer timer;

    timer.Initialize();

    InputInitialize();
    RendererInitialize();

    //-------------------------------------------------
    // Boucle principale
    //-------------------------------------------------

    MSG msg = {};

    while (g_Running) {

        //---------------------------------------------
        // Messages Windows
        //---------------------------------------------

        while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE)) {    
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        //---------------------------------------------
        // Temps
        //---------------------------------------------

        timer.Update();

        float dt = timer.GetDeltaTime();
        
        //-------------------------------------------------
        // UPDATE
        //-------------------------------------------------
        
        InputUpdate();

        const float Speed = 200.0f;

        if (IsKeyDown(VK_LEFT)) {
            g_PlayerX -= Speed * dt;
        }

        if (IsKeyDown(VK_RIGHT)) {
            g_PlayerX += Speed * dt;
        }

        if (IsKeyDown(VK_UP)) {
            g_PlayerY -= Speed * dt;
        }

        if (IsKeyDown(VK_DOWN)) {
            g_PlayerY += Speed * dt;
        }

        Clear(0x00101010);
        
        DrawRect((int)g_PlayerX, (int)g_PlayerY, 16, 16, 0x0000FF00);

        RendererEndFrame(window);

        char title[256];

        sprintf_s(title, "Azure Engine | FPS : %.0f", timer.GetFPS());

        SetWindowTextA(window, title);

        //---------------------------------------------
        // Pause légère
        //---------------------------------------------

        Sleep(1);
    }
    return 0;
}