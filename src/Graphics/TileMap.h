#pragma once

constexpr int TILE_SIZE = 16;

constexpr int MAP_WIDTH = 100;
constexpr int MAP_HEIGHT = 100;

void InitializeTileMap();

void DrawTileMap();

bool IsTileSolid(int worldX, int worldY);