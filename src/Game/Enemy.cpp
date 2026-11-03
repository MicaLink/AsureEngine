#include "Enemy.h"

#include "Player.h"

Entity Enemy = { 200.0f, 200.0f, 8, 8, 100, true};

constexpr float ENEMY_SPEED = 75.0f;

void UpdateEnemy(float deltaTime) {
    if (Player.X < Enemy.X)
        Enemy.X -= ENEMY_SPEED * deltaTime;
    if (Player.X > Enemy.X)
        Enemy.X += ENEMY_SPEED * deltaTime;
    if (Player.Y < Enemy.Y)
        Enemy.Y -= ENEMY_SPEED * deltaTime;
    if (Player.Y > Enemy.Y)
        Enemy.Y += ENEMY_SPEED * deltaTime;
}