# Architecture AzureEngine

Version : v0.0.2-alpha

---

# Présentation

AzureEngine est un projet open source visant à construire un écosystème complet de développement rétro.

Le premier composant du projet est **Azure-8**, une machine virtuelle 8 bits conçue pour servir de base aux futurs outils de développement.

L'objectif est de construire progressivement :

```txt
AzureEngine
│
├── Azure-8
├── AzureASM
├── Azure Studio
├── Marketplace
├── Azure-16
└── Matériel réel
```

Azure-8 constitue le socle technique de l'ensemble du projet.

---

# Architecture actuelle du projet

```txt
AzureEngine
│
├── docs
│
├── roms
│
├── src
│   │
│   ├── Azure8
│   │   ├── CPU
│   │   ├── Memory
│   │   └── Emulator
│   │
│   ├── Core
│   │   └── Type.h
│   │
│   └── main.cpp
│
└── build
```

---

# Azure-8

Azure-8 est une architecture 8 bits simple destinée à l'apprentissage, à l'expérimentation et à la création de jeux rétro.

Principes :

```txt
Architecture simple
Code lisible
Documentation complète
Évolution progressive
```

---

# Vue générale

Azure-8 est composé de :

```txt
CPU
RAM
ROM
```

Le cycle d'exécution suit le schéma classique :

```txt
Fetch
↓
Decode
↓
Execute
```

---

# CPU

Le processeur Azure-8 est un processeur 8 bits.

## Registres utilisateur

```txt
A       8 bits
B       8 bits
C       8 bits
D       8 bits
FLAGS   8 bits
```

Les registres A, B, C et D sont utilisés pour le stockage et la manipulation des données.

---

## Registres système

```txt
PC      16 bits
SP      16 bits
```

### PC

Le Program Counter contient l'adresse de l'instruction en cours d'exécution.

```txt
Taille : 16 bits
```

### SP

Le Stack Pointer contient l'adresse du sommet de la pile.

```txt
Taille : 16 bits
```

---

# Mémoire

Azure-8 dispose de :

```txt
64 Ko de RAM
```

Organisation :

```txt
0000h
│
│
│
FFFFh
```

Taille totale :

```txt
65536 octets
```

---

# Lecture mémoire

Fonctions disponibles :

```cpp
Read8()
Write8()

Read16()
Write16()
```

---

## Valeurs 16 bits

Azure-8 utilise le format :

```txt
Little Endian
```

Exemple :

```txt
1234h
```

En mémoire :

```txt
Adresse     Valeur

0000h       34h
0001h       12h
```

---

# Gestion de la pile

La pile est localisée en haut de la mémoire.

Configuration actuelle :

```txt
STACK_BOTTOM = FE00h
STACK_TOP    = FFFFh
```

Zone réservée :

```txt
FE00h
↓
FFFFh
```

---

## Opérations disponibles

### 8 bits

```cpp
Push8()
Pop8()
```

### 16 bits

```cpp
Push16()
Pop16()
```

---

## Sécurité

Le système détecte :

```txt
Stack Overflow
Stack Underflow
```

Une erreur provoque :

```txt
Arrêt du CPU
```

---

# FLAGS

Le registre FLAGS est codé sur 8 bits.

Organisation actuelle :

```txt
Bit 0 : Zero
Bit 1 : Carry
Bit 2 : Negative
Bit 3 : Overflow

Bits 4 à 7 réservés
```

Représentation :

```txt
7 6 5 4 3 2 1 0

- - - - V N C Z
```

---

## Zero Flag

Activé lorsque :

```txt
Résultat = 0
```

---

## Carry Flag

Activé lors d'un dépassement non signé.

Utilisation future :

```txt
ADD
SUB
```

---

## Negative Flag

Activé si :

```txt
Bit 7 = 1
```

---

## Overflow Flag

Activé lors d'un dépassement signé.

Utilisation future :

```txt
ADD
SUB
CMP
```

---

# Jeu d'instructions

Instructions actuellement disponibles :

| Opcode | Instruction |
|----------|----------|
| 00h | NOP |
| FFh | HLT |

---

## NOP

```asm
NOP
```

Aucune opération.

---

## HLT

```asm
HLT
```

Arrête immédiatement le processeur.

---

# Cycle CPU

Chaque instruction suit les étapes suivantes :

```txt
1. Fetch
2. Decode
3. Execute
```

---

## Fetch

Lecture de l'opcode :

```cpp
FetchByte()
```

---

## Decode

Identification de l'instruction :

```cpp
switch(opcode)
```

---

## Execute

Exécution du comportement associé.

---

# ROM

Les programmes Azure-8 sont stockés dans des ROMs binaires.

Exemple :

```hex
00 00 00 FF
```

Correspond à :

```asm
NOP
NOP
NOP
HLT
```

---

# Émulateur

L'émulateur est composé de :

```txt
Emulator
│
├── CPU
└── Memory
```

Rôles :

```txt
Chargement ROM
Exécution CPU
Gestion mémoire
```

---

# Debug

Azure-8 dispose actuellement des outils suivants :

```txt
DumpStack()
DumpRegister()
DumpMemory()
```

Affichages disponibles :

```txt
PC
SP
FLAGS
OPCODE
```

---

# Philosophie de développement

AzureEngine privilégie :

```txt
Code simple
Architecture claire
Documentation complète
Faible complexité
Contrôle maximal du système
```

Le projet avance par versions courtes et validées.

Chaque fonctionnalité doit être :

```txt
Documentée
Testée
Validée
```

avant l'ajout de nouvelles capacités.

---

# Versions futures

## v0.0.3

Introduction des premières instructions de manipulation de données :

```asm
MOV
LOAD
STORE
```

Puis :

```asm
PUSH
POP

CALL
RET
```

Puis :

```asm
INC
DEC

ADD
SUB

CMP
JZ
JNZ
```

---

# Statut actuel

```txt
Version     : v0.0.2-alpha

CPU         : 8 bits
RAM         : 64 Ko

Registres :

A
B
C
D

FLAGS

PC
SP

Mémoire :
Read8()
Write8()
Read16()
Write16()

Pile :
Push8()
Pop8()
Push16()
Pop16()

Debug :
DumpStack()
DumpRegister()
DumpMemory()
```

---

Fin du document.