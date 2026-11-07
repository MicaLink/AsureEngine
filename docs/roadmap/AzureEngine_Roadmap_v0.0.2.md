# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**

---

# Présentation

La version **v0.0.2-alpha** poursuit la construction des fondations techniques d'Azure-8.

Après la validation de :

- l'exécution d'une ROM binaire ;
- la boucle Fetch / Decode / Execute ;
- l'instruction NOP ;
- l'instruction HLT ;
- la mémoire 8 bits ;
- la console de débogage ;

l'objectif est désormais de construire l'infrastructure mémoire avancée nécessaire aux futures instructions du processeur.

Cette version est principalement consacrée à :

- la gestion mémoire 16 bits ;
- la pile (Stack) ;
- le Stack Pointer ;
- les FLAGS ;
- la préparation des futures instructions CPU.

---

# Architecture officielle Azure-8

Azure-8 est un processeur **8 bits**.

## Registres utilisateur

```txt
A : 8 bits
B : 8 bits
C : 8 bits
D : 8 bits
FLAGS : 8 bits
```

## Registres système

```txt
PC : 16 bits
SP : 16 bits
```

## Mémoire

```txt
64 Ko

0000h → FFFFh
```

## Philosophie

Azure-8 manipule :

```txt
des données sur 8 bits
```

mais possède :

```txt
un adressage mémoire sur 16 bits
```

afin de permettre :

- des programmes plus grands ;
- une pile fonctionnelle ;
- les futures instructions CALL et RET ;
- les futures extensions du système.

Cette architecture s'inspire directement des processeurs 8 bits historiques comme :

- MOS 6502
- Z80
- Motorola 6809

---

# Objectif principal

Permettre à Azure-8 de disposer d'une infrastructure mémoire robuste avant l'arrivée des premières instructions de manipulation de données.

À la fin de cette version, Azure-8 devra pouvoir :

- lire des adresses 16 bits ;
- écrire des adresses 16 bits ;
- gérer une pile fonctionnelle ;
- gérer le Stack Pointer ;
- préparer l'arrivée du futur ISA.

---

# État d'avancement

**Progression estimée : 40 %**

### Fonctionnalités validées

- [x] Read16()
- [x] Write16()
- [x] Little Endian
- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()
- [x] Réorganisation du module Memory
- [x] Réorganisation du module CPU

---

# Lot A - Mémoire 16 bits

## Objectif

Ajouter les opérations mémoire nécessaires à l'adressage 16 bits.

### Tâches

- [x] Implémenter Read16()
- [x] Implémenter Write16()
- [x] Validation Little Endian
- [x] Réorganisation de Memory.h
- [x] Réorganisation de Memory.cpp

### Statut

✅ Terminé

---

# Lot B - Stack

## Objectif

Créer la première implémentation de la pile Azure-8.

### Tâches

- [x] Définir le comportement de la pile
- [x] Définir l'utilisation du registre SP
- [x] Implémenter Push8()
- [x] Implémenter Pop8()
- [x] Implémenter Push16()
- [x] Implémenter Pop16()

### Statut

✅ Terminé

---

# Lot C - Sécurisation du Stack Pointer

## Objectif

Rendre la pile fiable et sécurisée.

### Tâches

- [ ] Valider l'incrémentation du SP
- [ ] Valider la décrémentation du SP
- [ ] Détection Stack Overflow
- [ ] Détection Stack Underflow
- [ ] Messages d'erreur
- [ ] Tests de robustesse

### Statut

🟨 En cours

---

# Lot D - FLAGS

## Objectif

Préparer les futures opérations logiques et arithmétiques.

### FLAGS prévus

```txt
Bit 0 : Zero Flag
Bit 1 : Carry Flag
Bit 2 : Negative Flag
Bit 3 : Overflow Flag
```

### Tâches

- [ ] Définition officielle des FLAGS
- [ ] Mise à jour de la spécification technique
- [ ] Helpers de manipulation des FLAGS

### Statut

⬜ Non commencé

---

# Lot E - Préparation du futur ISA

## Objectif

Préparer les premières véritables instructions Azure-8.

### Étude

- [ ] MOV
- [ ] LOAD
- [ ] STORE

### Documentation

- [ ] Définition des opcodes
- [ ] Formats d'instruction
- [ ] Modes d'adressage

### Statut

⬜ Non commencé

---

# Lot F - ROM de validation

## Objectif

Créer des ROM permanentes permettant de tester Azure-8.

### Tâches

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom
- [ ] memory16.rom
- [ ] stack8.rom
- [ ] stack16.rom

### Statut

⬜ Non commencé

---

# Lot G - Debug

## Objectif

Améliorer les capacités de diagnostic du processeur.

### Tâches

- [ ] Affichage SP
- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump Stack
- [ ] Affichage complet des registres

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

⬜ Non commencé

---

# Lot H - Documentation

## Objectif

Maintenir la documentation synchronisée avec le code.

### Tâches

- [ ] Mise à jour Azure-8 Technical Specification
- [ ] Documentation Read16()
- [ ] Documentation Write16()
- [ ] Documentation Push8()
- [ ] Documentation Pop8()
- [ ] Documentation Push16()
- [ ] Documentation Pop16()
- [ ] Documentation SP

### Statut

⬜ Non commencé

---

# Architecture cible en fin de v0.0.2

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
│   │   ├── Reset
│   │   ├── Read8
│   │   ├── Write8
│   │   ├── Read16
│   │   └── Write16
│   │
│   └── Emulator
│
├── docs
├── roms
└── tests
```

---

# Critères de validation

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [ ] SP est sécurisé
- [ ] Overflow détecté
- [ ] Underflow détecté
- [ ] Les ROMs de validation passent
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

La version v0.0.3 introduira les premières véritables instructions exploitables du processeur 8 bits :

```asm
MOV
LOAD
STORE

INC
DEC

ADD
SUB
```

Ces instructions manipuleront :

```txt
des données 8 bits
```

stockées dans :

```txt
les registres A, B, C et D
```

---

# Prochaine tâche immédiate

Développer :

```txt
Stack Overflow Detection
Stack Underflow Detection
Validation complète du SP
```

afin de finaliser entièrement le système de pile.

---

# État actuel

```txt
Projet : AzureEngine

Version actuelle : v0.0.2-alpha

Architecture :

CPU 8 bits
Adressage mémoire 16 bits
RAM 64 Ko

Progression : ~40 %

Statut : En développement

Prochaine étape :
Sécurisation du Stack Pointer
```

---

**Objectif du jalon : disposer d'une infrastructure mémoire solide et d'une pile sécurisée avant l'arrivée des premières instructions de manipulation de données du processeur 8 bits Azure-8.**