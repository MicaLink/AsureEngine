# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **En développement**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **90 %**
>
> Priorité actuelle : **Finalisation des derniers éléments du Lot C**

---

# Présentation

La version v0.0.2-alpha est consacrée à la consolidation de l'architecture interne d'Azure-8.

L'objectif principal est de finaliser l'infrastructure mémoire et la gestion de la pile avant l'introduction des premiers opcodes manipulant des données.

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

Azure-8 reste un processeur 8 bits.

---

# Objectif principal

Finaliser complètement le système de pile Azure-8.

À la fin de la version v0.0.2, Azure-8 devra disposer :

- d'une mémoire stable ;
- d'une pile robuste ;
- d'un Stack Pointer validé ;
- d'outils de diagnostic complets ;
- d'une base prête pour les FLAGS.

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
- [x] Validation Reset()
- [x] Validation Push8()
- [x] Validation Pop8()
- [x] Validation Push16()
- [x] Validation Pop16()
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow

### Debug

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Dump Stack

### Architecture

- [x] Refactorisation CPU
- [x] Refactorisation Memory

---

# Lot A - Mémoire

✅ Terminé

---

# Lot B - Stack

✅ Terminé

---

# Lot C - Stack Pointer

## Objectif

Valider définitivement le fonctionnement de la pile Azure-8.

### Fonctionnalités validées

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Initialisation du SP
- [x] GetSP()
- [x] Validation complète du SP
- [x] Détection Overflow
- [x] Détection Underflow
- [x] Affichage SP
- [x] Dump Stack

### Travail restant

#### Robustesse

- [ ] Tests de charge
- [ ] Validation limites mémoire

#### Documentation

- [ ] Documentation Stack Pointer
- [ ] Documentation architecture Stack

### Statut

🟨 95 % terminé

---

# Lot D - FLAGS

## Dépendance

⚠️ Début après clôture officielle du Lot C.

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
- [ ] Première implémentation

### Statut

⬜ En attente

---

# Lot E - Debug

## Réalisé

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Dump Stack

### À faire

- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump registres

### Statut

🟨 En cours

---

# Lot F - ROMs de validation

## Objectif

Créer une bibliothèque permanente de ROMs de validation.

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

Leur validation est reportée à la v0.0.3 car elle nécessitera :

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

- [ ] LICENSE
- [ ] Architecture.md
- [ ] Documentation Stack
- [ ] Documentation SP
- [ ] Documentation FLAGS
- [ ] Mise à jour Azure-8 Technical Specification

---

# Lot H - Qualité

- [ ] Vérifier les warnings MSVC
- [ ] Nettoyer le dépôt Git
- [ ] Premiers tests automatisés

---

# Prochaine étape

```txt
1. Tests de charge Stack
2. Documentation Stack
3. Clôture du Lot C
4. Implémentation des FLAGS
```

---

# Objectif de la v0.0.3

```asm
MOV
LOAD
STORE

PUSH
POP

CALL
RET
```

Puis validation officielle :

```txt
stack8.rom
stack16.rom
overflow.rom
underflow.rom
```

---

# État actuel

```txt
Projet : AzureEngine

Version : v0.0.2-alpha

CPU       : 8 bits
PC        : 16 bits
SP        : 16 bits
RAM       : 64 Ko

Progression : ~90 %

Priorité :
Finaliser définitivement le Lot C
```