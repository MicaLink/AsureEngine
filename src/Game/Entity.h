#pragma once

//-----------------------------------------------------
// Type d'entité
//-----------------------------------------------------

enum class EntityType {None, Player, Enemy, Projectile};

//-----------------------------------------------------
// Entité
//-----------------------------------------------------

struct Entity {
    float X = 0.0f;
    float Y = 0.0f;

    int Width = 0;
    int Height = 0;

    float VelocityX = 0.0f;
    float VelocityY = 0.0f;

    int Health = 100;

    bool Active = true;

    EntityType Type = EntityType::None;
};

//-----------------------------------------------------
// Collision
//-----------------------------------------------------

bool Intersects(const Entity& a, const Entity& b);