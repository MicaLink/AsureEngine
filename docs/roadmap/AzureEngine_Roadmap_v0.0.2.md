# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **95 %**  
> Priorité actuelle : **Finalisation du Lot D - FLAGS**

---

# Présentation

La version **v0.0.2-alpha** est consacrée à la finalisation des fondations techniques d'Azure-8.

Les sous-systèmes mémoire et pile sont désormais considérés comme stables et validés.

Le travail restant concerne principalement :

- le registre FLAGS ;
- les outils de debug associés ;
- la documentation ;
- les tâches de qualité du projet.

Cette version est la dernière étape avant l'introduction du premier véritable jeu d'instructions de manipulation de données prévu pour la v0.0.3.

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

L'adressage mémoire est réalisé sur :

```txt
16 bits
```

afin de permettre :

```txt
- un espace mémoire de 64 Ko
- une pile robuste
- les futurs sous-programmes
- les futurs appels de fonction
```

---

# Objectif principal

Finaliser l'ensemble des fondations techniques du processeur Azure-8 avant le début du développement du jeu d'instructions utilisateur.

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
- [x] Validation complète du SP
- [x] Overflow
- [x] Underflow
- [x] Validation limites mémoire
- [x] Tests de charge

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

## Statut

✅ TERMINÉ

---

# Lot B - Stack

## Statut

✅ TERMINÉ

---

# Lot C - Stack Pointer

## Résultat

Le système de pile Azure-8 est désormais considéré comme stable et validé.

### Validations obtenues

- [x] Reset
- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()
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

Préparer Azure-8 aux futures opérations logiques et arithmétiques.

### Définition officielle

```txt
Bit 0 : Zero Flag     (Z)
Bit 1 : Carry Flag    (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4 à 7 réservés
```

### Infrastructure validée

#### Définition des FLAGS

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

#### Gestion manuelle

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()
- [x] GetFlags()

#### Helpers automatiques

- [x] UpdateZeroFlag()
- [x] UpdateNegativeFlag()

#### Initialisation

- [x] Reset des FLAGS au démarrage

---

## Travail restant

### Flags automatiques

- [ ] Validation complète de UpdateZeroFlag()
- [ ] Validation complète de UpdateNegativeFlag()

### Debug

- [ ] Affichage FLAGS
- [ ] Dump registres

### Documentation

- [ ] Documentation FLAGS
- [ ] Mise à jour Technical Specification

### Statut

🟨 En cours

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

Leur validation complète est reportée à la v0.0.3 car elle dépend des futures instructions :

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

Préparer AzureEngine aux futures versions.

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

Validation Zero Flag
↓
Validation Negative Flag
↓
Affichage FLAGS
↓
Documentation FLAGS
```

## Étape suivante

```txt
LOT E

Debug avancé
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

- [ ] FLAGS validés
- [ ] Affichage FLAGS
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

Enfin :

```asm
INC
DEC

ADD
SUB
CMP
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

Progression : ~95 %

Lot A       : ✅ Terminé
Lot B       : ✅ Terminé
Lot C       : ✅ Terminé
Lot D       : 🟨 En cours

Priorité    : Validation complète des FLAGS
```

---

**Objectif immédiat : terminer le système FLAGS afin de clôturer définitivement la v0.0.2 et préparer l'arrivée des premières véritables instructions Azure-8.**