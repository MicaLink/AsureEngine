//=====================================================
// Azure Engine
// main.cpp
//=====================================================

#include <Windows.h>
#include <cstdio>

#include "Core/Colors.h"
#include "Core/Timer.h"

#include "Input/Input.h"

#include "Graphics/Animation.h"
#include "Graphics/Camera.h"
#include "Graphics/Hero.h"
#include "Graphics/Renderer.h"
#include "Graphics/RendererConfig.h"

#include "World/TileMap.h"

#include "Game/Player.h"
#include "Game/Enemy.h"
#include "Game/Entity.h"

//-----------------------------------------------------
// Constantes
//-----------------------------------------------------

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
// Collision TileMap
//-----------------------------------------------------

static bool CanMoveTo(float x, float y) {
    return !IsTileSolid(static_cast<int>(x), static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x) + HERO_SIZE - 1, static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x), static_cast<int>(y) + HERO_SIZE - 1) &&
           !IsTileSolid(static_cast<int>(x) + HERO_SIZE - 1, static_cast<int>(y) + HERO_SIZE - 1);
}

//-----------------------------------------------------
// Entrée programme
//-----------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {

    //-------------------------------------------------
    // Classe de fenêtre
    //-------------------------------------------------

    WNDCLASSA windowClass = {};

    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = "AzureEngineWindow";

    if (!RegisterClassA(&windowClass))
        return -1;

    //-------------------------------------------------
    // Création de la fenêtre
    //-------------------------------------------------

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

    if (!window)
        return -1;

    ShowWindow(window, nCmdShow);
    UpdateWindow(window);

    //-------------------------------------------------
    // Initialisation
    //-------------------------------------------------

    Timer timer;

    timer.Initialize();

    InputInitialize();
    RendererInitialize();
    InitializeTileMap();

    //-------------------------------------------------
    // Boucle principale
    //-------------------------------------------------

    MSG message = {};

    while (g_Running) {

        //---------------------------------------------
        // Messages Windows
        //---------------------------------------------

        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) { 
            if (message.message == WM_QUIT) 
                g_Running = false;
            
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
        // Joueur
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
        if (CanMoveTo(newX, Player.Y))
            Player.X = newX;
        if (CanMoveTo(Player.X, newY))
            Player.Y = newY;

        //---------------------------------------------
        // Enemy
        //---------------------------------------------
        
        UpdateEnemy(deltaTime);

        //---------------------------------------------
        // Animation
        //---------------------------------------------

        UpdateAnimation(HeroAnimation, deltaTime);

        //---------------------------------------------
        // Caméra
        //---------------------------------------------

        UpdateCamera(static_cast<int>(Player.X), static_cast<int>(Player.Y), SCREEN_WIDTH, SCREEN_HEIGHT);

        //---------------------------------------------
        // Collision Enemy
        //---------------------------------------------

        bool collisionEnemy = Intersects(Player, Enemy);

        //---------------------------------------------
        // Rendu
        //---------------------------------------------

        Clear(COLOR_BLACK);

        DrawTileMap();

        DrawWorldRect(static_cast<int>(Enemy.X), static_cast<int>(Enemy.Y), Enemy.Width, Enemy.Height, collisionEnemy ? COLOR_GREEN : COLOR_RED);

        DrawSprite(static_cast<int>(Player.X), static_cast<int>(Player.Y), GetAnimationFrame(HeroAnimation));

        RendererPresent(window);

        //---------------------------------------------
        // Titre fenêtre
        //---------------------------------------------

        char title[256];
        
        if (collisionEnemy)
            sprintf_s(title, "COLLISION ! | FPS : %.0f", timer.GetFPS());
        else
            sprintf_s(title, "Azure Engine | FPS : %.0f", timer.GetFPS());

        SetWindowTextA(window, title);

        //---------------------------------------------
        // CPU
        //---------------------------------------------

        Sleep(1);
    }

    return 0;
}