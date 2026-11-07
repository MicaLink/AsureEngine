# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.1-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **90 %**
>
> Prochaine priorité : **Lot D - FLAGS**

---

# Présentation

La version v0.0.2-alpha est consacrée à la consolidation de l'infrastructure interne d'Azure-8.

Cette version permet de finaliser :

- la mémoire ;
- la pile ;
- le Stack Pointer ;
- le système de validation ;
- les outils de debug.

L'objectif est de disposer d'une architecture stable avant l'arrivée des premières véritables instructions de manipulation de données.

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

Azure-8 reste un processeur strictement 8 bits.

Les registres 16 bits servent uniquement à :

- l'adressage mémoire ;
- la pile ;
- les futurs appels de fonctions.

---

# Objectif principal

Finaliser l'ensemble des fondations techniques avant l'introduction du premier véritable jeu d'instructions Azure-8.

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
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow

### Debug

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Dump Stack

### Robustesse

- [x] Tests de charge Push8()
- [x] Tests de charge Push16()
- [x] Validation complète Stack

---

# Lot A - Mémoire

✅ Terminé

---

# Lot B - Stack

✅ Terminé

---

# Lot C - Stack Pointer

## Objectif

Valider complètement le système de pile Azure-8.

### Résultat

- [x] Validation du SP
- [x] Validation Push8()
- [x] Validation Pop8()
- [x] Validation Push16()
- [x] Validation Pop16()
- [x] Overflow détecté
- [x] Underflow détecté
- [x] Affichage SP
- [x] Dump Stack
- [x] Tests de charge
- [x] Validation limites mémoire

### Statut

✅ TERMINÉ

---

# Lot D - FLAGS (NOUVELLE PRIORITÉ)

## Objectif

Préparer les futures opérations CPU.

### FLAGS prévus

```txt
Bit 0 : Zero Flag
Bit 1 : Carry Flag
Bit 2 : Negative Flag
Bit 3 : Overflow Flag
```

### Tâches

- [ ] Définition officielle des FLAGS
- [ ] Structure interne FLAGS
- [ ] Helpers CPU
- [ ] Documentation
- [ ] Première implémentation

### Statut

🟨 En cours de conception

---

# Lot E - Debug

## Réalisé

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Dump Stack

## À faire

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

Leur validation effective est reportée à la v0.0.3 car elle dépend des futures instructions :

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

- [ ] Vérifier les warnings MSVC
- [ ] Nettoyer le dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Prochaine étape

```txt
Lot D

FLAGS

├── Zero Flag
├── Carry Flag
├── Negative Flag
└── Overflow Flag
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

Lot A : ✅ Terminé
Lot B : ✅ Terminé
Lot C : ✅ Terminé

Prochaine étape :
FLAGS
```

---

**Le système de pile Azure-8 est désormais considéré comme stable et validé. La prochaine étape est l'implémentation du système FLAGS qui servira de fondation aux futures instructions arithmétiques et logiques.**