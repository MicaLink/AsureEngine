# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **98 %**  
> Priorité actuelle : **Finalisation du Lot D - FLAGS**

---

# Présentation

La version **v0.0.2-alpha** est consacrée à la finalisation de l'architecture de base d'Azure-8.

L'ensemble des composants critiques du processeur est désormais opérationnel :

- mémoire ;
- pile ;
- Stack Pointer ;
- système de debug ;
- infrastructure FLAGS.

Cette version prépare directement le terrain pour la future v0.0.3 qui introduira les premières instructions capables de manipuler des données utilisateur.

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

Azure-8 manipule uniquement :

```txt
des valeurs 8 bits
```

Les registres 16 bits sont utilisés exclusivement pour :

```txt
- l'adressage mémoire
- la pile
- le Program Counter
- les futurs appels de fonctions
```

---

# Objectif principal

Achever définitivement les fondations du processeur avant le démarrage du futur jeu d'instructions Azure-8.

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
- [x] Détection Overflow
- [x] Détection Underflow
- [x] Validation des limites mémoire
- [x] Tests de charge

### FLAGS

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()

- [x] UpdateZeroFlag()
- [x] UpdateNegativeFlag()

- [x] GetFlags()

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

Le système de pile Azure-8 est considéré comme stable.

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

# Lot D - FLAGS

## Objectif

Préparer Azure-8 aux futures opérations arithmétiques, logiques et de contrôle de flux.

---

## Définition officielle

```txt
Bit 0 : Zero Flag     (Z)
Bit 1 : Carry Flag    (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4 à 7 : Réservés
```

Représentation :

```txt
7 6 5 4 3 2 1 0

- - - - V N C Z
```

---

## Infrastructure FLAGS

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

### Gestion automatique

- [x] UpdateZeroFlag()
- [x] UpdateNegativeFlag()

### Initialisation

- [x] Reset des FLAGS

---

## Validation FLAGS

### Zero Flag

- [x] Activation si résultat = 0
- [x] Désactivation si résultat ≠ 0

### Negative Flag

- [x] Activation si bit 7 = 1
- [x] Désactivation si bit 7 = 0

### Validation combinée

- [x] Fonctionnement simultané validé

---

## Travail restant

### Évolution future

- [ ] Carry Flag pour ADD
- [ ] Carry Flag pour SUB
- [ ] Overflow Flag signé
- [ ] Intégration aux futures instructions

### Documentation

- [ ] Documentation FLAGS
- [ ] Mise à jour Azure-8 Technical Specification

### Statut

🟨 Quasiment terminé

---

# Lot E - Debug

## Fonctionnalités réalisées

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Dump Stack
- [x] Dump Registers

## Travaux futurs

- [ ] Dump Memory

### Statut

✅ Fonctionnel

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
Finalisation du Lot D

↓

Documentation FLAGS

↓

Mise à jour Technical Specification

↓

Clôture officielle v0.0.2
```

## Étape suivante

```txt
Préparation v0.0.3
```

## Puis

```txt
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
- [x] Infrastructure FLAGS validée

- [ ] Documentation FLAGS terminée
- [ ] Documentation technique mise à jour
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
Lot D       : 🟨 Quasiment terminé
Lot E       : ✅ Fonctionnel

Priorité :

Documentation FLAGS
Documentation technique
Préparation v0.0.3
```

---

**Azure-8 dispose désormais d'une base technique solide. La v0.0.3 pourra se concentrer sur l'arrivée des premières instructions de manipulation de données sans nécessiter de refonte de l'architecture interne.**