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
> Priorité actuelle : **Finalisation du Lot E - Debug**

---

# Présentation

La version v0.0.2-alpha finalise les fondations techniques d'Azure-8.

Les sous-systèmes mémoire, pile, Stack Pointer et FLAGS sont désormais implémentés et validés.

Cette version prépare directement la future v0.0.3 qui introduira les premières véritables instructions de manipulation de données.

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

# État d'avancement

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

## Résultat

Le système FLAGS est opérationnel.

### Fonctionnalités validées

- [x] Définition officielle
- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

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

# Lot E - Debug (PRIORITÉ ACTUELLE)

## Réalisé

### Exécution

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Affichage FLAGS

### Diagnostic

- [x] Dump Stack
- [x] Dump Register()

---

## Travail restant

### Mémoire

- [ ] DumpMemory()

### Validation

- [ ] Validation DumpMemory()

### Statut

🟨 En cours

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

Les ROMs Stack sont présentes dans le dépôt.

Leur validation est reportée à la v0.0.3 car elle dépend des instructions :

```asm
PUSH
POP
CALL
RET
```

---

# Lot G - Documentation

## Tâches

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

## Tâches

- [ ] Vérification warnings MSVC
- [ ] Nettoyage dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Ordre de développement

## Étape actuelle

```txt
LOT E

DumpMemory()
↓
Validation DumpMemory()
```

## Puis

```txt
LOT G

Documentation
```

## Puis

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

- [ ] DumpMemory()
- [ ] Documentation mise à jour
- [ ] Tests automatisés disponibles

---

# Objectif de la v0.0.3

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

Priorité :

Lot E - Debug
```

---

**Objectif immédiat : implémenter DumpMemory() afin de clôturer le système de debug et finaliser la v0.0.2.**