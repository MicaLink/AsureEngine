# CodingStyle.md

# AzureEngine Coding Style Guide

Version : 0.0.1

Ce document définit les conventions de codage officielles du projet AzureEngine.

L'objectif est de garantir :

- une lecture simple du code ;
- une maintenance facilitée ;
- une cohérence entre les modules ;
- une contribution plus facile pour les développeurs externes.

---

# Philosophie

AzureEngine est un projet éducatif et technique.

Le code doit privilégier :

1. La lisibilité
2. La simplicité
3. La maintenabilité
4. La stabilité

avant :

- l'optimisation prématurée ;
- les abstractions complexes ;
- les dépendances externes.

---

# Langage

Version minimale :

```txt
C++17
```

Compilateur principal :

```txt
MSVC
```

Compatibilité future :

```txt
GCC
Clang
```

---

# Encodage

Tous les fichiers texte doivent utiliser :

```txt
UTF-8
LF
```

Extensions :

```txt
.h
.cpp
.md
.txt
.asm
```

---

# Nommage des fichiers

Un fichier = une responsabilité.

Exemples :

```txt
CPU.h
CPU.cpp

Memory.h
Memory.cpp

Emulator.h
Emulator.cpp
```

Éviter :

```txt
UtilsEverything.cpp
Helpers.cpp
Misc.cpp
```

---

# Nommage des types

Structures :

```cpp
struct CPU
{
};
```

```cpp
struct Memory
{
};
```

Classes :

```cpp
class Emulator
{
};
```

Utiliser :

```txt
PascalCase
```

---

# Nommage des fonctions

Utiliser :

```txt
PascalCase
```

Exemple :

```cpp
void Reset();

void Step();

void Execute();
```

Éviter :

```cpp
reset();
step();
execute();
```

---

# Nommage des variables membres

Utiliser :

```cpp
struct CPU
{
    uint8_t A;
    uint8_t B;

    uint16_t PC;
    uint16_t SP;
};
```

Pas de préfixe :

```cpp
m_PC
m_SP
```

dans les structures simples.

---

# Variables globales

Préfixe :

```cpp
g_
```

Exemple :

```cpp
uint8_t g_RAM[65536];
```

```cpp
bool g_Running;
```

---

# Constantes

Utiliser :

```cpp
constexpr
```

Exemple :

```cpp
constexpr uint32_t RAM_SIZE = 65536;
```

```cpp
constexpr uint8_t OPCODE_NOP = 0x00;
```

Éviter :

```cpp
#define RAM_SIZE 65536
```

---

# Énumérations

Toujours :

```cpp
enum class
```

Exemple :

```cpp
enum class CPUState
{
    Running,
    Halted
};
```

Éviter :

```cpp
enum CPUState
{
};
```

---

# Accolades

Toujours sur une nouvelle ligne.

Correct :

```cpp
if (condition)
{
    Execute();
}
```

Incorrect :

```cpp
if(condition){
    Execute();
}
```

---

# Conditions

Toujours explicites.

Correct :

```cpp
if (cpu.Halted == true)
{
}
```

ou

```cpp
if (cpu.Halted)
{
}
```

Éviter :

```cpp
if (cpu.Halted != false)
{
}
```

---

# Boucles

Format :

```cpp
for (int i = 0; i < count; ++i)
{
}
```

Préférer :

```cpp
++i
```

à :

```cpp
i++
```

lorsque possible.

---

# Commentaires

Utiliser :

```cpp
//-----------------------------------------------------
// Description
//-----------------------------------------------------
```

Exemple :

```cpp
//-----------------------------------------------------
// Fetch
//-----------------------------------------------------

uint8_t FetchByte()
{
}
```

---

# Fonctions

Une fonction = une responsabilité.

Correct :

```cpp
void Reset();
```

```cpp
void Fetch();
```

```cpp
void Decode();
```

Éviter :

```cpp
void DoEverything();
```

---

# Taille des fonctions

Objectif :

```txt
< 50 lignes
```

Si une fonction devient trop grande :

```txt
extraire une sous-fonction
```

---

# Includes

Ordre :

```cpp
#include <cstdint>

#include "CPU.h"
#include "Memory.h"
```

1. Standard Library
2. Projet local

---

# Magic Numbers

Interdit.

Incorrect :

```cpp
RAM[65535] = 0;
```

Correct :

```cpp
RAM[RAM_SIZE - 1] = 0;
```

---

# Gestion des erreurs

Toujours vérifier :

```cpp
nullptr
```

Exemple :

```cpp
if (file == nullptr)
{
    return false;
}
```

---

# Logging

Version v0.0.1 :

```cpp
printf()
```

autorisé.

Exemple :

```cpp
printf(
    "PC=%04X OPCODE=%02X\n",
    cpu.PC,
    opcode);
```

---

# Architecture

Respecter les responsabilités.

CPU :

```txt
Fetch
Decode
Execute
```

Memory :

```txt
Lecture
Écriture
```

Emulator :

```txt
Chargement ROM
Exécution
```

Main :

```txt
Point d'entrée seulement
```

---

# Dépendances

Version v0.0.1 :

Aucune dépendance externe.

Autorisé :

```txt
STD C++
```

Interdit :

```txt
Boost
Qt
SDL
SFML
OpenGL
DirectX
```

Ces bibliothèques seront évaluées plus tard.

---

# Organisation des commits

Format recommandé :

```txt
[CPU] Add FetchByte()

[Memory] Add Read8()

[ROM] Add loader

[Docs] Update specification
```

---

# Définition de terminé

Un composant est considéré terminé lorsque :

- il compile ;
- il fonctionne ;
- il respecte cette convention ;
- il est documenté ;
- il n'introduit pas de warning critique.

---

# Résumé

Les règles les plus importantes :

✓ PascalCase

✓ constexpr au lieu des macros

✓ enum class

✓ Accolades sur nouvelle ligne

✓ Une fonction = une responsabilité

✓ Code simple avant code intelligent

✓ Documentation systématique

AzureEngine privilégie la clarté et la stabilité
avant l'optimisation.