# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **92 %**  
> Priorité actuelle : **Lot D - FLAGS**

---

# Présentation

La version **v0.0.2-alpha** est consacrée à la consolidation de l'architecture interne d'Azure-8.

Après la validation complète de la mémoire et de la pile, cette version termine les fondations nécessaires avant l'arrivée du premier véritable jeu d'instructions manipulant des données.

Les objectifs sont :

- finaliser le système mémoire ;
- finaliser le système de pile ;
- implémenter le registre FLAGS ;
- améliorer les outils de debug ;
- préparer la v0.0.3.

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
des données sur 8 bits
```

Les registres 16 bits sont réservés à :

```txt
- l'adressage mémoire
- la pile
- le Program Counter
- les futurs appels de fonctions
```

---

# Objectif principal

Finaliser complètement les fondations techniques d'Azure-8 avant l'arrivée des premières instructions de manipulation de données.

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
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow
- [x] Validation des limites mémoire
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

Le système de pile Azure-8 est désormais considéré comme stable.

### Validations obtenues

- [x] Reset
- [x] Push8
- [x] Pop8
- [x] Push16
- [x] Pop16
- [x] Affichage SP
- [x] Dump Stack
- [x] Overflow
- [x] Underflow
- [x] Tests de charge
- [x] Validation limites mémoire

### Statut

✅ TERMINÉ

---

# Lot D - FLAGS (PRIORITÉ ACTUELLE)

## Objectif

Préparer les futures opérations logiques et arithmétiques du processeur.

### Définition officielle

```txt
Bit 0 : Zero Flag (Z)
Bit 1 : Carry Flag (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4-7 : Réservés
```

### Fonctionnalités validées

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()
- [x] IsFlagSet()
- [x] GetFlags()

- [x] Reset des FLAGS au démarrage

### Travail restant

- [ ] Mise à jour automatique des FLAGS
- [ ] Documentation FLAGS
- [ ] Affichage FLAGS dans le Debug

### Statut

🟨 En cours

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

Créer une bibliothèque permanente de ROMs permettant de valider Azure-8 tout au long de son évolution.

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

Les ROMs Stack et Sécurité existent déjà dans le dépôt.

Leur validation effective est reportée à la v0.0.3 car elle nécessitera les futures instructions :

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

FLAGS
↓
Debug FLAGS
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
v0.0.3

MOV
LOAD
STORE
```

---

# Critères de validation de la v0.0.2

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [x] Stack validée
- [x] Stack Pointer validé

- [ ] FLAGS terminés
- [ ] Documentation mise à jour
- [ ] Tests automatisés disponibles

---

# Objectif de la v0.0.3

La version v0.0.3 introduira les premières véritables instructions de manipulation de données :

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

et permettra la validation officielle de :

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
FLAGS     : 8 bits

RAM       : 64 Ko

Progression : ~92 %

Lot A : ✅ Terminé
Lot B : ✅ Terminé
Lot C : ✅ Terminé

Priorité :
Lot D - FLAGS
```

---

**Le système mémoire et la pile Azure-8 sont désormais considérés comme stables. Le prochain jalon consiste à finaliser le système FLAGS qui servira de fondation aux futures instructions arithmétiques, logiques et de contrôle de flux.**