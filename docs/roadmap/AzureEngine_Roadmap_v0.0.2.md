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
> Priorité actuelle : **Documentation et Qualité**

---

# Présentation

La version v0.0.2-alpha finalise les fondations techniques du processeur Azure-8.

Les systèmes mémoire, pile, Stack Pointer, FLAGS et Debug sont désormais implémentés et fonctionnels.

Cette version prépare directement l'arrivée des premières instructions de manipulation de données prévues pour la v0.0.3.

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
64 Ko

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

## Résultat

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()

## Statut

✅ TERMINÉ

---

# Lot B - Stack

## Résultat

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

## Statut

✅ TERMINÉ

---

# Lot C - Stack Pointer

## Résultat

Le système de pile Azure-8 est complètement validé.

### Fonctionnalités validées

- [x] Validation SP
- [x] Overflow
- [x] Underflow
- [x] Affichage SP
- [x] DumpStack()
- [x] Tests de charge
- [x] Validation limites mémoire

### Statut

✅ TERMINÉ

---

# Lot D - FLAGS

## Résultat

Le système FLAGS est entièrement implémenté.

### Définition

```txt
Bit 0 : Zero Flag     (Z)
Bit 1 : Carry Flag    (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4 à 7 réservés
```

### Gestion

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()
- [x] GetFlags()

### Mise à jour

- [x] UpdateZeroFlag()
- [x] UpdateCarryFlag()
- [x] UpdateNegativeFlag()
- [x] UpdateOverflowFlag()

### Validation

- [x] Zero Flag
- [x] Carry Flag
- [x] Negative Flag
- [x] Overflow Flag

### Statut

✅ TERMINÉ

---

# Lot E - Debug

## Résultat

Le système de débogage Azure-8 est pleinement opérationnel.

### Affichage CPU

- [x] PC
- [x] SP
- [x] FLAGS
- [x] OPCODE

### Inspection

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

### Statut

✅ TERMINÉ

---

# Lot F - ROMs de validation

## ROMs fondamentales

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

## ROMs mémoire

- [ ] memory16.rom

## ROMs Stack

- [x] stack8.rom
- [x] stack16.rom

## ROMs sécurité

- [x] overflow.rom
- [x] underflow.rom

### Note

Les ROMs Stack et Sécurité sont présentes dans le dépôt.

Leur validation effective est reportée à la v0.0.3 avec l'arrivée des instructions :

```asm
PUSH
POP

CALL
RET
```

### Statut

🟨 Partiellement terminé

---

# Lot G - Documentation

## Objectif

Maintenir les spécifications synchronisées avec le code.

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
- [ ] Nettoyage dépôt Git
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

- [ ] Documentation mise à jour
- [ ] Tests automatisés disponibles
- [ ] Validation finale du dépôt

---

# Objectif de la v0.0.3

Introduction du premier jeu d'instructions Azure-8 :

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

Priorité :

Lot G - Documentation
Lot H - Qualité
```

---

**La partie développement cœur du processeur Azure-8 est désormais terminée pour la v0.0.2. Les derniers travaux concernent principalement la documentation, la qualité du dépôt et la préparation de la release avant le démarrage de la v0.0.3.**