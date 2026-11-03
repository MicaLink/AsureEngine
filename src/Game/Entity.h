#pragma once

struct Entity {
    float X = 0.0f;
    float Y = 0.0f;

    int Width = 0;
    int Height = 0;

    int Health = 100;

    bool Active = true;
};

bool Intersects(const Entity& a, const Entity& b);