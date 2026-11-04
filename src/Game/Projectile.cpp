#include "Projectile.h"

Entity g_Projectiles[MAX_PROJECTILES];

namespace {
    constexpr float PROJECTILE_SPEED = 300.0f;
}

void InitializeProjectiles() {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        g_Projectiles[i].Active = false;
        g_Projectiles[i].Type = EntityType::Projectile;
    }
}

void SpawnProjectile(float x, float y, float directionX, float directionY) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        if (g_Projectiles[i].Active)
            continue;

        Entity& projectile = g_Projectiles[i];
        projectile.Active = true;
        projectile.X = x;
        projectile.Y = y;
        projectile.Width = 4;
        projectile.Height = 4;
        projectile.VelocityX = directionX * PROJECTILE_SPEED;
        projectile.VelocityY = directionY * PROJECTILE_SPEED;

        return;
    }
}
    
void UpdateProjectiles(float deltaTime) {
    for (int i = 0; i < MAX_PROJECTILES; i++) {
        Entity& projectile = g_Projectiles[i];

        if (!projectile.Active)
            continue;
            
        projectile.X += projectile.VelocityX * deltaTime;
        projectile.Y += projectile.VelocityY * deltaTime;
    }
}