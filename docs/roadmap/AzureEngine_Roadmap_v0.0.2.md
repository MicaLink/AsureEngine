# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **Pré-release**
>
> Version précédente : **v0.0.1-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **99 %**
>
> Priorité actuelle : **Lot H - Qualité**

---

# Présentation

La version v0.0.2-alpha finalise les fondations techniques de la plateforme Azure-8.

Cette version introduit :

- l'adressage mémoire 16 bits ;
- le système de pile ;
- le registre Stack Pointer ;
- le registre FLAGS ;
- les outils avancés de débogage ;
- les ROMs de validation ;
- la documentation complète de l'architecture.

L'objectif principal est de stabiliser Azure-8 avant l'arrivée des premières instructions de manipulation de données prévues pour la v0.0.3.

---

# Architecture officielle Azure-8

## Registres utilisateur

```txt
A       8 bits
B       8 bits
C       8 bits
D       8 bits

FLAGS   8 bits
```

---

## Registres système

```txt
PC      16 bits
SP      16 bits
```

---

## Mémoire

```txt
RAM 64 Ko

0000h → FFFFh
```

---

# État global d'avancement

## CPU

- [x] Fetch
- [x] Decode
- [x] Execute

---

## Mémoire

- [x] Read8()
- [x] Write8()

- [x] Read16()
- [x] Write16()

- [x] Validation Little Endian

---

## Stack

- [x] Push8()
- [x] Pop8()

- [x] Push16()
- [x] Pop16()

---

## Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM

- [x] Validation complète

- [x] Overflow
- [x] Underflow

- [x] Tests de charge

---

## FLAGS

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()

- [x] IsFlagSet()
- [x] GetFlags()

- [x] UpdateZeroFlag()
- [x] UpdateCarryFlag()

- [x] UpdateNegativeFlag()
- [x] UpdateOverflowFlag()

---

## Debug

- [x] Affichage PC
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Affichage OPCODE

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

---

# Lot A - Mémoire

## Fonctionnalités

- [x] Read8()
- [x] Write8()

- [x] Read16()
- [x] Write16()

- [x] Little Endian

## Statut

✅ TERMINÉ

---

# Lot B - Stack

## Fonctionnalités

- [x] Push8()
- [x] Pop8()

- [x] Push16()
- [x] Pop16()

## Statut

✅ TERMINÉ

---

# Lot C - Stack Pointer

## Fonctionnalités

- [x] Gestion du registre SP
- [x] Limites de pile
- [x] Validation mémoire
- [x] Détection Overflow
- [x] Détection Underflow
- [x] Tests de charge

## Statut

✅ TERMINÉ

---

# Lot D - FLAGS

## Fonctionnalités

- [x] Zero Flag
- [x] Carry Flag
- [x] Negative Flag
- [x] Overflow Flag

- [x] SetFlag()
- [x] ClearFlag()

- [x] IsFlagSet()
- [x] GetFlags()

- [x] UpdateZeroFlag()
- [x] UpdateCarryFlag()

- [x] UpdateNegativeFlag()
- [x] UpdateOverflowFlag()

## Statut

✅ TERMINÉ

---

# Lot E - Debug

## Fonctionnalités

### Affichage CPU

- [x] PC
- [x] SP
- [x] FLAGS
- [x] OPCODE

### Outils

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

## Statut

✅ TERMINÉ

---

# Lot F - ROMs de validation

## ROMs fondamentales

### nop.rom

Validation :

```asm
NOP
NOP
NOP
NOP
HLT
```

Statut :

- [x] Créée
- [x] Testée
- [x] Validée

---

### halt.rom

Validation :

```asm
HLT
```

Statut :

- [x] Créée
- [x] Testée
- [x] Validée

---

### invalid.rom

Validation :

```txt
Opcode inconnu
```

Statut :

- [x] Créée
- [x] Testée
- [x] Validée

---

## ROMs avancées

### memory16.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### stack8.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### stack16.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### overflow.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### underflow.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

---

## Statut

✅ TERMINÉ POUR LA V0.0.2

---

# Lot G - Documentation

## Objectif

Maintenir la documentation synchronisée avec le code.

---

## Documentation générale

- [x] README.md
- [x] LICENSE
- [x] Architecture.md

---

## Documentation technique

- [x] Documentation Stack.md
- [x] Documentation SP.md
- [x] Documentation FLAGS.md

---

## Spécifications

- [x] Azure-8_Technical_Specification_v0.0.1.txt
- [x] Azure-8_Technical_Specification_v0.0.2.txt

---

## Roadmaps

- [x] AzureEngine_Roadmap_v0.0.1.md
- [x] AzureEngine_Roadmap_v0.0.2.md

---

## Statut

✅ TERMINÉ

---

# Lot H - Qualité

## Objectif

Préparer la release officielle v0.0.2-alpha.

---

## Code

- [ ] Vérification warnings MSVC

- [ ] Nettoyage du code

  - [ ] FFAGS → FLAGS
  - [ ] hight → high

- [ ] Uniformisation du style

---

## Compilation

- [ ] Validation Build Debug
- [ ] Validation Build Release

---

## Dépôt

- [ ] Vérification structure du dépôt
- [ ] Vérification documentation finale
- [ ] Validation des fichiers ROM

---

## Tests

- [ ] Premiers tests automatisés

---

## Statut

🟨 EN COURS

---

# Ordre de développement

## Étape actuelle

```txt
LOT H

Qualité
```

---

## Puis

```txt
Release

v0.0.2-alpha
```

---

## Ensuite

```txt
Début du développement

v0.0.3
```

---

# Critères de validation de la v0.0.2

## Architecture

- [x] Mémoire validée
- [x] Stack validée
- [x] Stack Pointer validé
- [x] FLAGS validés

---

## Debug

- [x] Debug validé

---

## ROMs

- [x] nop.rom validée
- [x] halt.rom validée
- [x] invalid.rom validée

---

## Documentation

- [x] Documentation complète

---

## Release

- [ ] Validation finale du dépôt
- [ ] Validation qualité
- [ ] Tag Git

---

# Objectif de la v0.0.3

Premières instructions de manipulation de données :

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

# État actuel

```txt
Projet      : AzureEngine

Version     : v0.0.2-alpha

CPU         : 8 bits
PC          : 16 bits
SP          : 16 bits
FLAGS       : 8 bits

RAM         : 64 Ko

Progression : ~99 %

Lot A       : ✅ Terminé
Lot B       : ✅ Terminé
Lot C       : ✅ Terminé
Lot D       : ✅ Terminé
Lot E       : ✅ Terminé
Lot F       : ✅ Terminé
Lot G       : ✅ Terminé
Lot H       : 🟨 En cours

Priorité :

Lot H - Qualité
```

---

# Résumé

La version v0.0.2-alpha est désormais fonctionnellement complète.

Les fondations d'Azure-8 sont terminées :

```txt
✓ Mémoire 16 bits
✓ Stack
✓ Stack Pointer
✓ FLAGS
✓ Debug
✓ ROMs de validation
✓ Documentation
```

Les derniers travaux concernent uniquement la qualité, la validation finale du dépôt et la préparation de la release officielle.

Une fois le Lot H terminé, le projet pourra être publié sous le tag :

```txt
v0.0.2-alpha
```

avant le démarrage du développement de la version :

```txt
v0.0.3
```

consacrée aux premières instructions de manipulation de données.