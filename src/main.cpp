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
// Constantes Gameplay
//-----------------------------------------------------

constexpr float PLAYER_SPEED = 200.0f;

constexpr int PLAYER_SIZE = 8;
constexpr int TARGET_KILL = 3;

//-----------------------------------------------------
// Variables globales
//-----------------------------------------------------

static bool g_Running = true;

static float g_DamageTimer = 0.0f;
static float g_AttackTimer = 0.0f;

static int g_KillCount = 0;

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
    return !IsTileSolid(static_cast<int>(x), static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x) + PLAYER_SIZE - 1, static_cast<int>(y)) &&
           !IsTileSolid(static_cast<int>(x), static_cast<int>(y) + PLAYER_SIZE - 1) &&
           !IsTileSolid(static_cast<int>(x) + PLAYER_SIZE - 1, static_cast<int>(y) + PLAYER_SIZE - 1);
}

//-----------------------------------------------------
// Initialisation ennemis
//-----------------------------------------------------

static void CreateTestEntities() {
    Entity* enemy;
    enemy = CreateEntity();

    if (enemy) {
        enemy->X = 200.0f;
        enemy->Y = 200.0f;
        enemy->Width = 8;
        enemy->Height = 8;
        enemy->Health = 100;
    }
    enemy = CreateEntity();
    
    if (enemy) {
        enemy->X = 300.0f;
        enemy->Y = 250.0f;
        enemy->Width = 8;
        enemy->Height = 8;
        enemy->Health = 100;
    }
    enemy = CreateEntity();
    
    if (enemy) {
        enemy->X = 400.0f;
        enemy->Y = 350.0f;
        enemy->Width = 8;
        enemy->Height = 8;
        enemy->Health = 100;
    }
}

//-----------------------------------------------------
// Déplacement joueur
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
// Dégâts ennemis
//-----------------------------------------------------

static void UpdateEnemyDamage(float deltaTime) {
    g_DamageTimer += deltaTime;

    if (g_DamageTimer < 0.25f) 
        return;

    for (int i = 0; i < g_EntityCount; i++) {
        Entity& enemy = g_Entities[i];

        if (!enemy.Active)
            continue;
        if (Intersects(Player, enemy)) {
            Player.Health--;
            g_DamageTimer = 0.0f;
            break;
        }
    }
}

//-----------------------------------------------------
// Attaque joueur
//-----------------------------------------------------

static void UpdatePlayerAttack(float deltaTime) {
    g_AttackTimer += deltaTime;

    if (!IsKeyDown(VK_SPACE))
        return;
    if (g_AttackTimer < 0.30f)
        return;
    g_AttackTimer = 0.0f;
    
    for (int i = 0; i < g_EntityCount; i++) {
        Entity& enemy = g_Entities[i];
        if (!enemy.Active)
            continue;
        if (Intersects(Player, enemy))
            enemy.Health -= 10;
        if (enemy.Health <= 0) {
            enemy.Active = false;
            g_KillCount++;
        }
    }
}

//-----------------------------------------------------
// Rendu ennemis
//-----------------------------------------------------

static void DrawEnemies() {
    for (int i = 0; i < g_EntityCount; i++) {
        const Entity& enemy = g_Entities[i];
        if (!enemy.Active)
            continue;

        DrawWorldRect(static_cast<int>(enemy.X), static_cast<int>(enemy.Y), enemy.Width, enemy.Height, COLOR_RED);
    }
}

//-----------------------------------------------------
// Point d'entrée
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
        while (PeekMessage(&message, nullptr, 0, 0, PM_REMOVE)) { 
            if (message.message == WM_QUIT) 
                g_Running = false;
            
            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        timer.Update();

        const float deltaTime = timer.GetDeltaTime();
        //---------------------------------------------
        // Update
        //---------------------------------------------


        InputUpdate();
        UpdatePlayer(deltaTime);
        UpdateEnemies(deltaTime);
        UpdatePlayerAttack(deltaTime);
        UpdateEnemyDamage(deltaTime);
        UpdateAnimation(HeroAnimation, deltaTime);
        UpdateCamera(static_cast<int>(Player.X), static_cast<int>(Player.Y), SCREEN_WIDTH, SCREEN_HEIGHT);

        //---------------------------------------------
        // Victoire
        //---------------------------------------------

        if (g_KillCount >= TARGET_KILL) {
            MessageBoxA(nullptr, "Victoire!", "Azure Engine", MB_OK);

            g_Running = false;
        }

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

        DrawEnemies();

        DrawSprite(static_cast<int>(Player.X), static_cast<int>(Player.Y), GetAnimationFrame(HeroAnimation));

        RendererPresent(window);

        //---------------------------------------------
        // Infos
        //---------------------------------------------

        char title[256];
        
        sprintf_s(title, "HP:%d | Kills:%d/%d | Enemies:%d | FPS:%.0f ", Player.Health, g_KillCount, TARGET_KILL, g_EntityCount, timer.GetFPS());

        SetWindowTextA(window, title);

        Sleep(1);
    }

    return 0;
}