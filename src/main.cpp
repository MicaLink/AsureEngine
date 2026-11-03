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

#include "Game/Entity.h"
#include "Game/EntityManager.h"
#include "Game/Enemy.h"
#include "Game/Player.h"

//-----------------------------------------------------
// Gameplay
//-----------------------------------------------------

constexpr float PLAYER_SPEED = 200.0f;

static bool g_Running = true;
static float g_DamageTimer = 0.0f;

//-----------------------------------------------------
// Fenêtre
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
    constexpr int SIZE = 8;

    return !IsTileSolid(static_cast<int>(x), static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x) + SIZE - 1, static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x), static_cast<int>(y) + SIZE - 1) &&
           !IsTileSolid(static_cast<int>(x) + SIZE - 1, static_cast<int>(y) + SIZE - 1);
}

//-----------------------------------------------------
// Joueur
//-----------------------------------------------------

static void UpdatePlayer(float deltaTime) {
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
}

//-----------------------------------------------------
// Ennemis
//-----------------------------------------------------

static bool UpdateEnemyCollision(float deltaTime) {
    bool collision = false;

    g_DamageTimer += deltaTime;

    for (int i = 0; i < g_EntityCount; i++) {
        if (Intersects(Player, g_Entities[i])) {
            collision = true;

            if (g_DamageTimer >= 0.25f) {
                Player.Health--;
                g_DamageTimer = 0.0f;
            }
        }
    }
    return collision;
}

//-----------------------------------------------------
// Entités de test
//-----------------------------------------------------

static void CreateTestEntities() {
    Entity* enemy;
    enemy = CreateEntity();

    if (enemy) {
        enemy->X = 200.0f;
        enemy->Y = 200.0f;
        enemy->Width = 8;
        enemy->Height = 8;
    }
    enemy = CreateEntity();
    
    if (enemy) {
        enemy->X = 260.0f;
        enemy->Y = 180.0f;
        enemy->Width = 8;
        enemy->Height = 8;
    }
    enemy = CreateEntity();
    
    if (enemy) {
        enemy->X = 320.0f;
        enemy->Y = 240.0f;
        enemy->Width = 8;
        enemy->Height = 8;
    }
}

//-----------------------------------------------------
// WinMain
//-----------------------------------------------------

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow) {
    WNDCLASSA windowClass = {};

    windowClass.lpfnWndProc = WindowProc;
    windowClass.hInstance = hInstance;
    windowClass.lpszClassName = "AzureEngineWindow";

    if (!RegisterClassA(&windowClass))
        return -1;

    HWND window = CreateWindowExA(0, "AzureEngineWindow", "Azure Engine", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

    if (!window)
        return -1;

    ShowWindow(window, nCmdShow);

    //-------------------------------------------------
    // Initialisation
    //-------------------------------------------------

    Timer timer;

    timer.Initialize();

    InputInitialize();
    RendererInitialize();
    InitializeTileMap();
    ClearEntities();
    CreateTestEntities();

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
        // Update
        //---------------------------------------------
        
        InputUpdate();
        UpdatePlayer(deltaTime);
        UpdateEnemy(deltaTime);
        UpdateAnimation(HeroAnimation, deltaTime);
        UpdateCamera(static_cast<int>(Player.X), static_cast<int>(Player.Y), SCREEN_WIDTH, SCREEN_HEIGHT);

        const bool collisionEnemy = UpdateEnemyCollision(deltaTime);

        //---------------------------------------------
        // Game Over
        //---------------------------------------------

        if (Player.Health <= 0) {
            MessageBoxA(nullptr, "Game Over", "Azure Engine", MB_OK);

            g_Running = false;
        }

        //---------------------------------------------
        // Rendu
        //---------------------------------------------

        Clear(COLOR_BLACK);

        DrawTileMap();

        for (int i = 0; i < g_EntityCount; i++) {
            DrawWorldRect(static_cast<int>(g_Entities[i].X), static_cast<int>(g_Entities[i].Y), g_Entities[i].Width, g_Entities[i].Height, COLOR_RED);
        }
        
        DrawSprite(static_cast<int>(Player.X), static_cast<int>(Player.Y), GetAnimationFrame(HeroAnimation));

        RendererPresent(window);

        //---------------------------------------------
        // Titre fenêtre
        //---------------------------------------------

        char title[256];
        
        sprintf_s(title, "HP:%d | Enemies:%d | FPS:%.0f", Player.Health, g_EntityCount, timer.GetFPS());

        SetWindowTextA(window, title);

        Sleep(1);
    }

    return 0;
}