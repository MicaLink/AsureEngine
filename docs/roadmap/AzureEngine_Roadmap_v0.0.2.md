# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.1-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **99 %**
>
> Priorité actuelle : **Lot G - Documentation**

---

# Présentation

La version v0.0.2-alpha finalise les fondations techniques du processeur Azure-8.

Cette version ajoute :

- la mémoire 16 bits ;
- la pile ;
- le Stack Pointer ;
- le système FLAGS ;
- les outils de debug avancés ;
- les ROMs de validation.

Cette version constitue la dernière étape avant l'introduction des premières instructions de manipulation de données prévues pour la v0.0.3.

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

## Registres système

```txt
PC      16 bits
SP      16 bits
```

## Mémoire

```txt
RAM 64 Ko

0000h → FFFFh
```

---

# État global d'avancement

## Mémoire

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()
- [x] Validation Little Endian

## CPU

- [x] Fetch
- [x] Decode
- [x] Execute

## Stack

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

## Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Validation complète
- [x] Overflow
- [x] Underflow
- [x] Tests de charge

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

✅ TERMINÉ

---

# Lot B - Stack

✅ TERMINÉ

---

# Lot C - Stack Pointer

✅ TERMINÉ

---

# Lot D - FLAGS

✅ TERMINÉ

---

# Lot E - Debug

✅ TERMINÉ

### Fonctionnalités validées

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

- [x] Affichage PC
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Affichage OPCODE

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
- [x] Validée

---

### halt.rom

Validation :

```asm
HLT
```

Statut :

- [x] Créée
- [x] Validée

---

### invalid.rom

Validation :

```txt
Opcode inconnu
```

Statut :

- [x] Créée
- [x] Validée

---

## ROMs mémoire

### memory16.rom

Statut :

- [x] Créée
- [ ] Validation reportée à la v0.0.3

---

## ROMs Stack

### stack8.rom

Statut :

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### stack16.rom

Statut :

- [x] Créée
- [ ] Validation reportée à la v0.0.3

---

## ROMs sécurité

### overflow.rom

Statut :

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### underflow.rom

Statut :

- [x] Créée
- [ ] Validation reportée à la v0.0.3

---

## Statut du Lot F

🟨 Partiellement terminé

### Validé dans la v0.0.2

- [x] nop.rom
- [x] halt.rom
- [x] invalid.rom

### Reporté à la v0.0.3

- [ ] memory16.rom
- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

---

# Lot G - Documentation

## Objectif

Maintenir la documentation synchronisée avec le code.

### Tâches

- [ ] LICENSE
- [ ] Architecture.md

- [ ] Documentation Stack
- [ ] Documentation SP
- [ ] Documentation FLAGS

- [ ] Mise à jour Azure-8 Technical Specification

### Statut

⬜ Non commencé

---

# Lot H - Qualité

## Objectif

Préparer AzureEngine pour les futures versions.

### Tâches

- [ ] Vérification warnings MSVC
- [ ] Nettoyage du code
- [ ] Nettoyage du dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Ordre de développement

## Étape actuelle

```txt
LOT G

Documentation
```

## Ensuite

```txt
LOT H

Qualité
```

## Puis

```txt
Release v0.0.2-alpha
```

---

# Critères de validation de la v0.0.2

- [x] Mémoire validée
- [x] Stack validée
- [x] Stack Pointer validé
- [x] FLAGS validés
- [x] Debug validé

- [x] nop.rom validée
- [x] halt.rom validée
- [x] invalid.rom validée

- [ ] Documentation mise à jour
- [ ] Validation finale du dépôt
- [ ] Tests automatisés disponibles

---

# Objectif de la v0.0.3

Introduction du premier véritable jeu d'instructions Azure-8 :

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

Lot F       : 🟨 Validation partielle

Priorité :

Lot G - Documentation
Lot H - Qualité
```

---

**La partie développement du cœur Azure‑8 est désormais terminée pour la v0.0.2. Les ROMs fondamentales sont validées et les prochains travaux concernent principalement la documentation, la qualité du code et la préparation de la release v0.0.2-alpha.**