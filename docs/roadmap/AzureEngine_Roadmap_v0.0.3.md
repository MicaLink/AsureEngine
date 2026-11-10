# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **Planification**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Priorité actuelle : **Instructions de manipulation de données**
>
> Progression : **0 %**

---

# Présentation

La version v0.0.3-alpha marque une étape importante dans le développement d'Azure-8.

Les versions précédentes ont permis de construire les fondations techniques :

```txt
CPU
RAM
ROM Loader

Read16()
Write16()

Stack
Stack Pointer

FLAGS

Debug

Tests automatisés
```

L'objectif de la v0.0.3 est de transformer Azure-8 en un processeur réellement programmable.

---

# Philosophie

Cette version reste fidèle aux principes fondateurs du projet :

```txt
Assembler autant que possible

C avant C++

C++ simple et maîtrisé

Architecture claire

Faible niveau d'abstraction

Contrôle maximal du matériel émulé
```

---

# Objectif principal

Permettre à un programme Azure-8 de :

```txt
Lire des données
Écrire des données
Déplacer des données
Effectuer des calculs
Effectuer des branchements
Utiliser la pile
```

---

# Ordre de développement

La roadmap v0.0.3 est divisée en plusieurs lots.

```txt
Lot A - Instructions de données
Lot B - Pile avancée
Lot C - Arithmétique
Lot D - Comparaison et branchements
Lot E - ROMs de validation
Lot F - Documentation
Lot G - Tests automatisés
```

---

# Lot A - Instructions de données

## Objectif

Introduire les premières instructions manipulant des données.

---

## Instruction MOV

Objectif :

```txt
Copier une valeur entre registres.
```

Exemples :

```asm
MOV A, B
MOV C, D
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Instruction LOAD

Objectif :

```txt
Charger une valeur depuis la mémoire.
```

Exemple :

```asm
LOAD A, 1000h
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Instruction STORE

Objectif :

```txt
Écrire une valeur en mémoire.
```

Exemple :

```asm
STORE A, 1000h
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Statut

⬜ Non commencé

---

# Lot B - Pile avancée

## Objectif

Préparer la gestion des sous-routines.

---

## Instruction PUSH

Exemple :

```asm
PUSH A
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Instruction POP

Exemple :

```asm
POP A
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Instruction CALL

Exemple :

```asm
CALL 1000h
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Instruction RET

Exemple :

```asm
RET
```

À réaliser :

- [ ] Opcode
- [ ] Décodeur
- [ ] Exécution
- [ ] Tests

---

## Statut

⬜ Non commencé

---

# Lot C - Arithmétique

## Objectif

Ajouter les premières opérations mathématiques.

---

## INC

```asm
INC A
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Tests

---

## DEC

```asm
DEC A
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Tests

---

## ADD

```asm
ADD A, B
```

- [ ] Implémentation
- [ ] FLAG_ZERO
- [ ] FLAG_CARRY
- [ ] FLAG_NEGATIVE
- [ ] FLAG_OVERFLOW
- [ ] Tests

---

## SUB

```asm
SUB A, B
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Tests

---

## Statut

⬜ Non commencé

---

# Lot D - Comparaison et branchements

## Objectif

Permettre l'exécution conditionnelle.

---

## CMP

```asm
CMP A, B
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Tests

---

## JZ

```asm
JZ Label
```

- [ ] Implémentation
- [ ] Tests

---

## JNZ

```asm
JNZ Label
```

- [ ] Implémentation
- [ ] Tests

---

## JMP

```asm
JMP Label
```

- [ ] Implémentation
- [ ] Tests

---

## Statut

⬜ Non commencé

---

# Lot E - ROMs de validation

## Objectif

Valider les nouvelles instructions.

---

### memory16.rom

Validation :

```txt
LOAD
STORE
```

- [ ] Validation

---

### stack8.rom

Validation :

```txt
PUSH
POP
```

- [ ] Validation

---

### stack16.rom

Validation :

```txt
CALL
RET
```

- [ ] Validation

---

### overflow.rom

Validation :

```txt
Dépassement pile
```

- [ ] Validation

---

### underflow.rom

Validation :

```txt
Sous-dépassement pile
```

- [ ] Validation

---

## Nouvelles ROMs

- [ ] mov.rom
- [ ] load_store.rom
- [ ] arithmetic.rom
- [ ] branch.rom

---

## Statut

⬜ Non commencé

---

# Lot F - Documentation

## Objectif

Maintenir la documentation synchronisée avec l'évolution du CPU.

---

### Mise à jour

- [ ] Architecture.md

- [ ] Documentation FLAGS.md

- [ ] Documentation Stack.md

- [ ] Documentation SP.md

- [ ] Azure-8_Technical_Specification_v0.0.3.txt

- [ ] README.md

---

## Statut

⬜ Non commencé

---

# Lot G - Tests automatisés

## Objectif

Étendre la couverture de tests.

---

### Mémoire

- [ ] LOAD
- [ ] STORE

### Pile

- [ ] PUSH
- [ ] POP

- [ ] CALL
- [ ] RET

### Arithmétique

- [ ] INC
- [ ] DEC

- [ ] ADD
- [ ] SUB

### Branchement

- [ ] CMP
- [ ] JZ
- [ ] JNZ
- [ ] JMP

---

## Statut

⬜ Non commencé

---

# Critères de validation

Pour clôturer la version v0.0.3 :

### CPU

- [ ] MOV
- [ ] LOAD
- [ ] STORE

- [ ] PUSH
- [ ] POP

- [ ] CALL
- [ ] RET

- [ ] INC
- [ ] DEC

- [ ] ADD
- [ ] SUB

- [ ] CMP
- [ ] JZ
- [ ] JNZ

### ROMs

- [ ] ROMs validées

### Documentation

- [ ] Documentation complète

### Build

- [ ] Build Debug
- [ ] Build Release

- [ ] 0 erreur
- [ ] 0 warning

### Tests

- [ ] Tests automatisés

---

# Vision après la v0.0.3

Une fois Azure-8 doté d'un jeu d'instructions fonctionnel, les prochaines étapes du projet pourront être envisagées :

```txt
AzureASM

Premiers programmes complets

Jeu de démonstration

IDE minimal

SDK Azure-8
```

Mais la priorité reste exclusivement :

```txt
Azure-8
```

jusqu'à obtention d'une plateforme réellement programmable et stable.

---

# État actuel

```txt
Projet      : AzureEngine

Version     : v0.0.3-alpha

Architecture :

CPU 8 bits
RAM 64 Ko

Priorité :

MOV
LOAD
STORE

Progression :

0 %
```

---

**Objectif principal de la v0.0.3 : transformer Azure-8 d'une architecture expérimentale validée en une plateforme réellement programmable pouvant exécuter des programmes non triviaux.**