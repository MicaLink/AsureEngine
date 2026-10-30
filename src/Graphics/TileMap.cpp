#include "TileMap.h"
#include "Renderer.h"
#include "Camera.h"

constexpr int TILE_SIZE = 16;

constexpr int MAP_WIDTH = 20;
constexpr int MAP_HEIGHT = 12;

static int WorldMap[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,1,1,1,0,0,0,1,1,1,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

void DrawTileMap() {
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            unsigned int color = WorldMap[y][x] ? 0x00606060 : 0x00202020;
            
            DrawRect(x * TILE_SIZE - CameraX, y * TILE_SIZE - CameraY, TILE_SIZE, TILE_SIZE, color);
        }
    }
}

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