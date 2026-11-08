# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **98 %**  
> Priorité actuelle : **Finalisation du Lot D - FLAGS**

---

# Présentation

La version **v0.0.2-alpha** est consacrée à la finalisation des fondations techniques d'Azure-8.

Les systèmes mémoire, pile, Stack Pointer et debug principal sont désormais considérés comme stables.

Cette version constitue la dernière étape avant l'arrivée du premier véritable jeu d'instructions Azure-8 prévu pour la v0.0.3.

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

0000h → FFFFh
```

## Philosophie

Azure-8 manipule exclusivement :

```txt
des données sur 8 bits
```

Les registres 16 bits sont utilisés uniquement pour :

```txt
- l'adressage mémoire
- la pile
- le Program Counter
- les futurs appels de fonctions
```

---

# Objectif principal

Finaliser toutes les fondations techniques nécessaires avant l'apparition des premières instructions de manipulation de données.

---

# État d'avancement

## Fonctionnalités validées

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

### Stack

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

### Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Initialisation du SP
- [x] GetSP()
- [x] Validation complète du SP
- [x] Validation des limites mémoire
- [x] Tests de charge
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow

### FLAGS

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()
- [x] GetFlags()

- [x] UpdateZeroFlag()
- [x] UpdateNegativeFlag()

### Debug

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Dump Stack
- [x] Dump Registers

### Architecture

- [x] Refactorisation CPU
- [x] Refactorisation Memory

---

# Lot A - Mémoire

## Résultat

### Fonctionnalités

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()

### Statut

✅ TERMINÉ

---

# Lot B - Stack

## Résultat

### Fonctionnalités

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

### Statut

✅ TERMINÉ

---

# Lot C - Stack Pointer

## Résultat

Le système de pile Azure-8 est validé.

### Fonctionnalités validées

- [x] Validation SP
- [x] Overflow
- [x] Underflow
- [x] Affichage SP
- [x] Dump Stack
- [x] Tests de charge
- [x] Validation limites mémoire

### Statut

✅ TERMINÉ

---

# Lot D - FLAGS (PRIORITÉ ACTUELLE)

## Objectif

Préparer Azure-8 aux futures opérations logiques, arithmétiques et de contrôle de flux.

---

## Définition officielle

```txt
Bit 0 : Zero Flag     (Z)
Bit 1 : Carry Flag    (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4 à 7 : Réservés
```

---

## Infrastructure

### Définition

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

### Gestion manuelle

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()
- [x] GetFlags()

### Mise à jour automatique

- [x] UpdateZeroFlag()
- [x] UpdateNegativeFlag()

### Initialisation

- [x] Reset des FLAGS

---

## Validation

### Zero Flag

- [x] Activation lorsque valeur = 0
- [x] Désactivation lorsque valeur ≠ 0

### Negative Flag

- [x] Activation lorsque le bit 7 = 1
- [x] Désactivation lorsque le bit 7 = 0

### Validation combinée

- [x] Fonctionnement simultané de Z et N

---

## Travail restant

### Carry Flag

- [ ] Helpers dédiés
- [ ] Validation complète

### Overflow Flag

- [ ] Helpers dédiés
- [ ] Validation complète

### Documentation

- [ ] Documentation FLAGS
- [ ] Mise à jour Technical Specification

### Statut

🟨 En cours (≈ 95 %)

---

# Lot E - Debug

## Réalisé

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Dump Stack
- [x] Dump Registers

## À faire

- [ ] Dump Memory

### Statut

🟨 Presque terminé

---

# Lot F - ROMs de validation

## Objectif

Maintenir une bibliothèque permanente de validation Azure-8.

### ROMs fondamentales

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

### ROMs mémoire

- [ ] memory16.rom

### ROMs Stack

- [x] stack8.rom
- [x] stack16.rom

### ROMs sécurité

- [x] overflow.rom
- [x] underflow.rom

### Note

Les ROMs Stack sont présentes dans le dépôt.

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

- [ ] Vérifier les warnings MSVC
- [ ] Nettoyer le dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Ordre de développement

## Étape actuelle

```txt
LOT D

Carry Flag
↓
Overflow Flag
↓
Documentation FLAGS
```

## Étape suivante

```txt
LOT E

Dump Memory
```

## Puis

```txt
Finalisation v0.0.2
```

## Puis

```txt
v0.0.3

MOV
LOAD
STORE
```

---

# Critères de validation de la v0.0.2

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Mémoire validée
- [x] Stack validée
- [x] Stack Pointer validé

- [x] Infrastructure FLAGS
- [x] Validation Zero Flag
- [x] Validation Negative Flag

- [ ] Validation Carry Flag
- [ ] Validation Overflow Flag

- [ ] Documentation FLAGS
- [ ] Documentation mise à jour

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

Progression : ~98 %

Lot A       : ✅ Terminé
Lot B       : ✅ Terminé
Lot C       : ✅ Terminé
Lot D       : 🟨 En cours
Lot E       : 🟨 En cours

Priorité :

Carry Flag
Overflow Flag
Documentation FLAGS
```

---

**Objectif immédiat : finaliser Carry Flag et Overflow Flag afin de clôturer définitivement le Lot D et terminer la v0.0.2.**