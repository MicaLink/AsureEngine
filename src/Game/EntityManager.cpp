#include "EntityManager.h"

Entity g_Entities[MAX_ENTITIES];
int g_EntityCount = 0;

void ClearEntities() {
    g_EntityCount = 0;
}

Entity* CreateEntity() {
    if (g_EntityCount >= MAX_ENTITIES)
        return nullptr;

    return &g_Entities[g_EntityCount++];
}