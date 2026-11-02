//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

#include "Core/Timer.h"

#include "Input/Input.h"

#include "Graphics/Animation.h"
#include "Graphics/Camera.h"
#include "Graphics/Hero.h"
#include "Graphics/Renderer.h"
#include "Graphics/TileMap.h"

#include "Game/Player.h"

//-----------------------------------------------------
// Constantes
//-----------------------------------------------------

constexpr int SCREEN_WIDTH = 320;
constexpr int SCREEN_HEIGHT = 200;

constexpr int HERO_SIZE = 8;
constexpr float PLAYER_SPEED = 200.0f;

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

static bool g_Running = true;

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
// Test collision joueur
//-----------------------------------------------------

static bool CanMoveTo(float x, float y) {
    return !IsTileSolid(static_cast<int>(x), static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x) + HERO_SIZE - 1, static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x), static_cast<int>(y) + HERO_SIZE - 1) &&
           !IsTileSolid(static_cast<int>(x) + HERO_SIZE - 1, static_cast<int>(y) + HERO_SIZE - 1);
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
    // Initialisation systèmes
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

        const float deltaTime = timer.GetDeltaTime();
        
        //---------------------------------------------
        // Entrées
        //---------------------------------------------
        
        InputUpdate();


        //---------------------------------------------
        // Déplacement du joueur
        //---------------------------------------------

        float newX = Player.X;
        float newY = Player.Y;

        if (IsKeyDown(VK_LEFT))
            newX -= PLAYER_SPEED * deltaTime;

        if (IsKeyDown(VK_RIGHT))
            newX += PLAYER_SPEED * deltaTime;

        if (IsKeyDown(VK_UP))
            newY -= PLAYER_SPEED * deltaTime;

        if (IsKeyDown(VK_DOWN))
            newY += PLAYER_SPEED * deltaTime;

        //---------------------------------------------
        // Collision X
        //---------------------------------------------

        if (CanMoveTo(newX, Player.Y)) {
            Player.X = newX;
        }

        //---------------------------------------------
        // Collision Y
        //---------------------------------------------

        if (CanMoveTo(Player.X, newY)) {
            Player.Y = newY;
        }

        //---------------------------------------------
        // Animation
        //---------------------------------------------

        UpdateAnimation(HeroAnimation, deltaTime);

        //---------------------------------------------
        // Caméra
        //---------------------------------------------

        UpdateCamera(static_cast<int>(Player.X), static_cast<int>(Player.Y), SCREEN_WIDTH, SCREEN_HEIGHT);

        //---------------------------------------------
        // Rendu
        //---------------------------------------------

        Clear(0x00101010);

        DrawTileMap();

        DrawSprite(static_cast<int>(Player.X), static_cast<int>(Player.Y), GetAnimationFrame(HeroAnimation));

        RendererPresent(window);

        //---------------------------------------------
        // FPS
        //---------------------------------------------

        char title[256];

        sprintf_s(title, "Azure Engine | FPS : %.0f", timer.GetFPS());

        SetWindowTextA(window, title);

        //---------------------------------------------
        // Réduction charge CPU
        //---------------------------------------------

        Sleep(1);
    }

    return 0;
}