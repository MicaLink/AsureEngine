#include "TileMap.h"

#include "Renderer.h"
#include "Camera.h"

namespace {
    int WorldMap[MAP_HEIGHT][MAP_WIDTH];
}

//-----------------------------------------------------
// Initialisation
//-----------------------------------------------------

void InitializeTileMap() {
    // Sol vide
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            WorldMap[y][x] = 0;
        }
    }

    // Bordures

    for (int x = 0; x < MAP_WIDTH; x++) {
        WorldMap[0][x] = 1;
        WorldMap[MAP_HEIGHT - 1][x] = 1;
    }

    for (int y = 0; y < MAP_HEIGHT; y++) {
        WorldMap[y][0] = 1;
        WorldMap[y][MAP_WIDTH - 1] = 1;
    }

    // Mur de test

    for (int x = 10; x < 40; x++) {
        WorldMap[20][x] = 1;
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

            // Culling horizontal

            if (screenX + TILE_SIZE < 0)
                continue;
            if (screenX >= SCREEN_WIDTH)
                continue;

            // Culling vertical

            if (screenY + TILE_SIZE < 0)
                continue;
            if (screenY >= SCREEN_HEIGHT)
                continue;

            unsigned int color = WorldMap[y][x] ? 0x00606060 : 0x00202020;

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

    if (tileX < 0)
        return true;

    if (tileY < 0)
        return true;

    if (tileX >= MAP_WIDTH)
        return true;
    
    if (tileY >= MAP_HEIGHT)
        return true;

    return WorldMap[tileY][tileX] == 1;
}