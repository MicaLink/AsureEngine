# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **60 %**

---

# Présentation

La version **v0.0.2-alpha** poursuit la construction des fondations techniques de Azure-8.

Après la validation du premier processeur capable de charger et exécuter une ROM, cette version a pour objectif de finaliser toute l'infrastructure mémoire nécessaire aux futures instructions du processeur.

Cette étape prépare directement :

```asm
MOV
LOAD
STORE

PUSH
POP

CALL
RET
```

---

# Architecture officielle Azure-8

Azure-8 est un processeur **8 bits**.

## Registres utilisateur

```txt
A       8 bits
B       8 bits
C       8 bits
D       8 bits
FLAGS   8 bits
```

## Registres système

```txt
PC      16 bits
SP      16 bits
```

## Mémoire

```txt
64 Ko

0000h -> FFFFh
```

## Philosophie

Azure-8 travaille sur :

```txt
des données 8 bits
```

mais utilise :

```txt
un adressage mémoire 16 bits
```

comme les processeurs historiques :

- MOS 6502
- Z80
- Motorola 6809

L'objectif est de conserver un véritable processeur 8 bits tout en disposant d'un espace mémoire suffisamment grand pour les futures évolutions.

---

# Objectif principal

À la fin de la version v0.0.2, Azure-8 devra disposer de :

- mémoire 16 bits fonctionnelle ;
- pile (Stack) fonctionnelle ;
- Stack Pointer sécurisé ;
- gestion des FLAGS préparée ;
- environnement prêt pour les futures instructions mémoire.

---

# État d'avancement

## Fonctionnalités terminées

### Mémoire

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()
- [x] Validation Little Endian

### CPU

- [x] Fetch
- [x] Decode
- [x] Execute

### Pile

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

### Architecture

- [x] Réorganisation CPU
- [x] Réorganisation Memory
- [x] Préparation Stack

---

# Lot A - Mémoire

## Objectif

Finaliser la couche mémoire Azure-8.

### Tâches

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()

### Statut

✅ Terminé

---

# Lot B - Stack

## Objectif

Créer une pile fonctionnelle.

### Tâches

- [x] Push8()
- [x] Pop8()

### Validation

```cpp
cpu.Push8(memory, 0x42);

u8 value =
    cpu.Pop8(memory);
```

Résultat :

```txt
42
```

---

### Tâches

- [x] Push16()
- [x] Pop16()

### Validation

```cpp
cpu.Push16(
    memory,
    0x1234);

u16 value =
    cpu.Pop16(memory);
```

Résultat :

```txt
1234
```

### Statut

✅ Terminé

---

# Lot C - Sécurisation du Stack Pointer

## Objectif

Empêcher les erreurs d'utilisation de la pile.

### Tâches

- [x] Définition de la zone Stack
- [x] Définition STACK_TOP
- [x] Définition STACK_BOTTOM
- [x] Validation SP au Reset

### Tâches restantes

- [ ] Validation complète SP
- [ ] Stack Overflow Detection
- [ ] Stack Underflow Detection
- [ ] Messages d'erreur dédiés
- [ ] ROM de validation

### Statut

🟨 En cours

---

# Lot D - FLAGS

## Objectif

Préparer les futures instructions CPU.

### FLAGS prévus

```txt
Bit 0 : Zero
Bit 1 : Carry
Bit 2 : Negative
Bit 3 : Overflow
```

### Tâches

- [ ] Définition officielle
- [ ] Helpers CPU
- [ ] Documentation

### Statut

⬜ Non commencé

---

# Lot E - Debug

## Objectif

Améliorer les informations de diagnostic.

### Tâches

- [x] Affichage PC
- [x] Affichage Opcode

### À faire

- [ ] Affichage SP
- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump pile
- [ ] Dump registres

### Exemple attendu

```txt
PC=0005
SP=FFFC

A=00
B=00
C=00
D=00

FLAGS=00
```

### Statut

🟨 En cours

---

# Lot F - ROMs de validation

## Objectif

Créer un jeu de tests permanent.

### Tâches

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom
- [ ] memory16.rom
- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

### Statut

⬜ Non commencé

---

# Lot G - Documentation

## Objectif

Conserver les spécifications synchronisées avec le code.

### Tâches

- [ ] Mise à jour Azure-8 Technical Specification
- [ ] Documentation Stack
- [ ] Documentation SP
- [ ] Documentation FLAGS
- [ ] Documentation Read16()
- [ ] Documentation Write16()

### Statut

⬜ Non commencé

---

# Architecture cible v0.0.2

```txt
AzureEngine
│
├── Azure8
│   │
│   ├── CPU
│   │   ├── Fetch
│   │   ├── Decode
│   │   ├── Execute
│   │   ├── Stack
│   │   └── Flags
│   │
│   ├── Memory
│   │   ├── Read8
│   │   ├── Write8
│   │   ├── Read16
│   │   └── Write16
│   │
│   └── Emulator
│
├── docs
│
├── roms
│
└── tests
```

---

# Critères de validation

La version v0.0.2 sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [ ] Stack sécurisée
- [ ] Overflow détecté
- [ ] Underflow détecté
- [ ] FLAGS définis
- [ ] ROMs de validation fonctionnelles
- [ ] Documentation mise à jour

---

# Hors périmètre

Toujours exclus de la série v0.0.x :

- GPU
- Audio
- BIOS
- AzureASM
- Azure Studio
- Marketplace
- Azure-16
- Jeux
- Réseau
- Matériel réel

---

# Objectif de la v0.0.3

La version v0.0.3 introduira les premières véritables instructions de manipulation de données :

```asm
MOV
LOAD
STORE

INC
DEC

ADD
SUB
```

Ces instructions manipuleront exclusivement les registres 8 bits :

```txt
A
B
C
D
```

---

# Prochaine tâche immédiate

Implémenter :

```txt
Stack Overflow Detection

Stack Underflow Detection

Validation complète du Stack Pointer
```

Une fois cette étape terminée, l'infrastructure mémoire d'Azure-8 sera considérée comme stable.

---

# État actuel

```txt
Projet : AzureEngine

Version actuelle : v0.0.2-alpha

Architecture :

CPU           8 bits
PC            16 bits
SP            16 bits
RAM           64 Ko

Progression : ~60 %

Statut : En développement

Prochaine étape :
Sécurisation complète du Stack Pointer
```

---

**Objectif du jalon : terminer entièrement l'infrastructure mémoire avant l'arrivée des premières véritables instructions du processeur Azure-8.**