# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Début du développement : Après publication du premier jalon officiel

---

# Présentation

La version **v0.0.2-alpha** marque le début de la deuxième phase de développement d'Azure-8.

Après avoir validé le cycle complet :

```txt
ROM
↓
Fetch
↓
Decode
↓
Execute
↓
HALT
```

l'objectif est maintenant de transformer Azure-8 en un processeur capable de manipuler des données de manière plus avancée.

Cette version introduit :

- la lecture 16 bits ;
- l'écriture 16 bits ;
- la pile (Stack) ;
- la gestion du registre SP ;
- les bases nécessaires aux futures instructions système.

---

# Objectif de la version

Valider toutes les fondations nécessaires à la future implémentation de :

```asm
MOV
LOAD
STORE

PUSH
POP

CALL
RET
```

À la fin de cette version, Azure-8 devra être capable :

- de lire des données sur 16 bits ;
- d'écrire des données sur 16 bits ;
- de gérer une pile fonctionnelle ;
- de préparer les futurs sous-programmes.

---

# État d'avancement

**Progression estimée : 15 %**

Fonctionnalités déjà validées :

- [x] Read16()
- [x] Write16()
- [x] Little Endian
- [x] Réorganisation du module Memory
- [x] Refactorisation du CPU

---

# Lot A - Mémoire 16 bits

## Objectif

Permettre la lecture et l'écriture de valeurs sur 16 bits.

### Tâches

- [x] Implémenter Read16()
- [x] Implémenter Write16()
- [x] Validation Little Endian
- [x] Réorganisation de Memory.h
- [x] Réorganisation de Memory.cpp

### Exemple

```cpp
memory.Write16(
    0x1000,
    0x1234);
```

Résultat attendu :

```txt
RAM[1000] = 34
RAM[1001] = 12
```

Lecture :

```cpp
memory.Read16(
    0x1000);
```

Résultat :

```txt
1234
```

### Statut

✅ Terminé

---

# Lot B - Stack

## Objectif

Créer la première implémentation officielle de la pile Azure-8.

### Tâches

- [ ] Définir l'organisation mémoire de la pile
- [ ] Définir le comportement du Stack Pointer
- [ ] Implémenter Push8()
- [ ] Implémenter Pop8()
- [ ] Implémenter Push16()
- [ ] Implémenter Pop16()

### Validation

Programme de test :

```txt
Push8(0x42)

Pop8()
```

Résultat attendu :

```txt
42
```

### Statut

⬜ Non commencé

---

# Lot C - Stack Pointer

## Objectif

Valider le fonctionnement du registre SP.

### Tâches

- [ ] Décrément automatique du SP
- [ ] Incrément automatique du SP
- [ ] Validation du comportement Little Endian
- [ ] Protection contre les débordements

### Statut

⬜ Non commencé

---

# Lot D - Flags CPU

## Objectif

Préparer les futures instructions de calcul.

### Tâches

- [ ] Documenter FLAGS
- [ ] Définir Zero Flag
- [ ] Définir Carry Flag
- [ ] Définir Negative Flag
- [ ] Définir Overflow Flag

### Statut

⬜ Non commencé

---

# Lot E - Préparation du futur ISA

## Objectif

Préparer les futures instructions de manipulation de données.

### Étude

- [ ] MOV
- [ ] LOAD
- [ ] STORE

### Documentation

- [ ] Définition des opcodes
- [ ] Définition des formats
- [ ] Définition des modes d'adressage

### Statut

⬜ Non commencé

---

# Lot F - ROM de validation

## Objectif

Créer des programmes de test permanents.

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

Améliorer les outils de diagnostic.

### Tâches

- [ ] Affichage SP
- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump Stack

### Exemple attendu

```txt
PC=0005
SP=FFFE

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
- [ ] Documentation Stack
- [ ] Documentation SP

### Statut

⬜ Non commencé

---

# Architecture cible

À la fin de la v0.0.2 :

```txt
AzureEngine
│
├── Azure8
│   │
│   ├── CPU
│   │   ├── Fetch
│   │   ├── Decode
│   │   ├── Execute
│   │   ├── Flags
│   │   └── Stack
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
│
├── roms
│
└── tests
```

---

# Critères de validation

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [ ] Push8 fonctionne
- [ ] Pop8 fonctionne
- [ ] Push16 fonctionne
- [ ] Pop16 fonctionne
- [ ] SP est correctement géré
- [ ] Les ROM de validation passent
- [ ] La documentation est à jour

---

# Hors périmètre

Les fonctionnalités suivantes restent exclues de la série v0.0.x :

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

La version v0.0.3 introduira les premières instructions exploitant la mémoire.

Instructions prévues :

```asm
MOV
LOAD
STORE
INC
DEC
ADD
SUB
```

Cette étape transformera Azure-8 en un processeur réellement programmable.

---

# Prochaine tâche immédiate

La prochaine tâche de développement est :

```txt
Push8()
Pop8()
```

Cette étape permettra de valider :

- le Stack Pointer ;
- l'organisation de la pile ;
- les futures instructions PUSH et POP ;
- les futurs appels de fonctions.

---

# État actuel

```txt
Projet : AzureEngine

Version actuelle : v0.0.2-alpha

Statut : En développement

Prochaine tâche :
Push8()
Pop8()
```

---

**Objectif du jalon : rendre Azure-8 capable de stocker et récupérer ses premières données depuis une pile fonctionnelle.**