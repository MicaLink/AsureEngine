//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

#include "Core/Timer.h"
#include "Input/Input.h"
#include "Graphics/Renderer.h"
#include "Graphics/Hero.h"

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

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
}

//-----------------------------------------------------
// Point d'entrée
//-----------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    //-------------------------------------------------
    // Classe de fenêtre
    //-------------------------------------------------

    WNDCLASSA windowClass = {};

    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = "AzureEngineWindow";

    if (!RegisterClassA(&windowClass)) {
        MessageBoxA(nullptr, "Impossible d'enregistrer la classe de fenêtre.", "Erreur", MB_OK | MB_ICONERROR);
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
    // Initialisation des sous-systèmes
    //-------------------------------------------------

    Timer timer;

    timer.Initialize();

    InputInitialize();
    RendererInitialize();

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

        float deltaTime = timer.GetDeltaTime();
        
        //---------------------------------------------
        // Entrées clavier
        //---------------------------------------------
        
        InputUpdate();

        //---------------------------------------------
        // Update
        //---------------------------------------------

        const float playerSpeed = 120.0f;

        if (IsKeyDown(VK_LEFT)) {
            g_PlayerX -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(VK_RIGHT)) {
            g_PlayerX += playerSpeed * deltaTime;
        }

        if (IsKeyDown(VK_UP)) {
            g_PlayerY -= playerSpeed * deltaTime;
        }

        if (IsKeyDown(VK_DOWN)) {
            g_PlayerY += playerSpeed * deltaTime;
        }

        //---------------------------------------------
        // Rendu
        //---------------------------------------------

        Clear(0x00102030);
        
        DrawSprite((int)g_PlayerX, (int)g_PlayerY, Hero);

        RendererPresent(window);

        //---------------------------------------------
        // Affichage FPS
        //---------------------------------------------

        char title[256];

        sprintf_s(title, "Azure Engine | FPS : %.0f", timer.GetFPS());

        SetWindowTextA(window, title);

        //---------------------------------------------
        // Réduction charge CPU
        //---------------------------------------------

        Sleep(1);
    }

    //-------------------------------------------------
    // Fin du programme
    //-------------------------------------------------

    return 0;
}