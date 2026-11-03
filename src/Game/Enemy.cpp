#include "Enemy.h"

#include "EntityManager.h"
#include "Player.h"

constexpr float ENEMY_SPEED = 75.0f;

void UpdateEnemy(float deltaTime) {
    for (int i = 0; i < g_EntityCount; i++) {
        Entity& enemy = g_Entities[i];
        if (enemy.Active) {
            if (Player.X < enemy.X)
                enemy.X -= ENEMY_SPEED * deltaTime;
            if (Player.X > enemy.X)
                enemy.X += ENEMY_SPEED * deltaTime;
            if (Player.Y < enemy.Y)
                enemy.Y -= ENEMY_SPEED * deltaTime;
            if (Player.Y > enemy.Y)
                enemy.Y += ENEMY_SPEED * deltaTime;
        }
    }
}