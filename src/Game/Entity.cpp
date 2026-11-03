#include "Entity.h"

bool Intersects(const Entity& a, const Entity& b) {
    return a.X < b.X + b.Width &&
           a.X + a.Width > b.X &&
           a.Y < b.Y + b.Height &&
           a.Y + a.Height > b.Y;
}