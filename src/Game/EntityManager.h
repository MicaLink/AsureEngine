#pragma once

#include "Entity.h"

constexpr int MAX_ENTITIES = 128;

extern Entity g_Entities[MAX_ENTITIES];
extern int g_EntityCount;

Entity* CreateEntity();

void ClearEntities();