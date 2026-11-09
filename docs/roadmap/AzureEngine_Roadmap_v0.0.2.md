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

La version v0.0.2-alpha finalise les fondations techniques d'Azure-8.

Cette version introduit :

- l'adressage mémoire 16 bits ;
- le système de pile ;
- le Stack Pointer ;
- le système FLAGS ;
- les outils de debug avancés ;
- les ROMs de validation.

L'objectif principal est de stabiliser l'architecture Azure-8 avant l'arrivée des premières instructions de manipulation de données dans la v0.0.3.

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

# État général

## CPU

- [x] Fetch
- [x] Decode
- [x] Execute

## Mémoire

- [x] Read8()
- [x] Write8()

- [x] Read16()
- [x] Write16()

- [x] Validation Little Endian

## Stack

- [x] Push8()
- [x] Pop8()

- [x] Push16()
- [x] Pop16()

## Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM

- [x] Overflow
- [x] Underflow

- [x] Tests de charge

## FLAGS

- [x] Zero
- [x] Carry
- [x] Negative
- [x] Overflow

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()

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

## Statut du Lot F

✅ TERMINÉ POUR LA v0.0.2

### Validé

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

- [x] Architecture.md

- [ ] Documentation Stack
- [ ] Documentation Stack Pointer
- [ ] Documentation FLAGS

- [ ] Azure-8_Technical_Specification_v0.0.2.txt

### Statut

🟨 En cours

---

# Lot H - Qualité

## Objectif

Préparer la release v0.0.2-alpha.

### Tâches

- [ ] Vérification warnings MSVC

- [ ] Nettoyage du code
  - [ ] FFAGS → FLAGS
  - [ ] hight → high

- [ ] Nettoyage dépôt Git

- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Ordre de développement

## Étape actuelle

```txt
LOT G

Documentation Stack
↓
Documentation SP
↓
Documentation FLAGS
↓
Azure-8 Technical Specification v0.0.2
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

- [ ] Documentation complète
- [ ] Validation du dépôt
- [ ] Tests automatisés

---

# Objectif de la v0.0.3

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

Priorité :

Lot G - Documentation
```

---

**Le développement du cœur d'Azure‑8 et la validation des ROMs fondamentales sont désormais terminés. La v0.0.2 entre dans sa phase finale de documentation et de préparation à la release avant le démarrage de la v0.0.3.**