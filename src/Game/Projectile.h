#pragma once

#include "Entity.h"

constexpr int MAX_PROJECTILES = 64;

extern Entity g_Projectiles[MAX_PROJECTILES];

void InitializeProjectiles();
void SpawnProjectile(float x, float y, float directionX, float directionY);
void UpdateProjectiles(float deltaTime);