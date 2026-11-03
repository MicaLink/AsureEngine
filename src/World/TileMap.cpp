#include "TileMap.h"

#include "../Core/Colors.h"

#include "../Graphics/Camera.h"
#include "../Graphics/Renderer.h"
#include "../Graphics/RendererConfig.h"

namespace {
    int g_WorldMap[MAP_HEIGHT][MAP_WIDTH];
}

//-----------------------------------------------------
// Initialisation carte
//-----------------------------------------------------

void InitializeTileMap() {

    //---------------------------------------------
    // Remplissage sol
    //---------------------------------------------

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            g_WorldMap[y][x] = 0;
        }
    }

    //---------------------------------------------
    // Bordures
    //---------------------------------------------

    for (int x = 0; x < MAP_WIDTH; x++) {
        g_WorldMap[0][x] = 1;
        g_WorldMap[MAP_HEIGHT - 1][x] = 1;
    }

    for (int y = 0; y < MAP_HEIGHT; y++) {
        g_WorldMap[y][0] = 1;
        g_WorldMap[y][MAP_WIDTH - 1] = 1;
    }

    //---------------------------------------------
    // Mur de test
    //---------------------------------------------

    for (int x = 10; x < 40; x++) {
        g_WorldMap[20][x] = 1;
    }

    //---------------------------------------------
    // Bloc de test
    //---------------------------------------------

    for (int y = 30; y < 40; y++) {
        for (int x = 30; x < 40; x++) {
            g_WorldMap[y][x] = 1;
        }
    }
}

//-----------------------------------------------------
// Rendu
//-----------------------------------------------------

void DrawTileMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            const int screenX = x * TILE_SIZE - CameraX;
            const int screenY = y * TILE_SIZE - CameraY;

            //-------------------------------------
            // Culling horizontal
            //-------------------------------------

            if (screenX + TILE_SIZE < 0)
                continue;
            if (screenX >= SCREEN_WIDTH)
                continue;

            //-------------------------------------
            // Culling vertical
            //-------------------------------------

            if (screenY + TILE_SIZE < 0)
                continue;
            if (screenY >= SCREEN_HEIGHT)
                continue;

            //-------------------------------------
            // Couleur tuile
            //-------------------------------------

            const uint32_t color = g_WorldMap[y][x] ? COLOR_LIGHT_GRAY : COLOR_DARK_GRAY;

            DrawRect(screenX, screenY, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

//-----------------------------------------------------
// Collision
//-----------------------------------------------------

bool IsTileSolid(int worldX, int worldY) {
    const int tileX = worldX / TILE_SIZE;
    const int tileY = worldY / TILE_SIZE;

    //---------------------------------------------
    // Hors carte
    //---------------------------------------------

    if (tileX < 0)
        return true;

    if (tileY < 0)
        return true;

    if (tileX >= MAP_WIDTH)
        return true;
    
    if (tileY >= MAP_HEIGHT)
        return true;

    //---------------------------------------------
    // Collision
    //---------------------------------------------

    return g_WorldMap[tileY][tileX] == 1;
}