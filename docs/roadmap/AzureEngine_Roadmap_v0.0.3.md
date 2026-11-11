# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **5 %**
>
> Priorité actuelle : **Lot A - Instructions de données**

---

# Présentation

La version v0.0.3-alpha marque le début de la seconde phase de développement d'Azure-8.

Les versions précédentes ont permis de construire et stabiliser toute l'infrastructure fondamentale du processeur :

```txt
CPU
RAM
ROM Loader

Read8()
Write8()

Read16()
Write16()

Stack
Stack Pointer

FLAGS

Debug

Tests automatisés
```

L'objectif de la v0.0.3 est désormais de transformer Azure-8 en une plateforme réellement programmable.

---

# Philosophie

Azure-8 continue d'être développé selon les principes fondamentaux du projet AzureEngine :

```txt
Assembler autant que possible

C avant C++

C++ simple et maîtrisé

Architecture compréhensible

Contrôle maximal du matériel émulé

Développement progressif

Documentation systématique
```

---

# Objectif principal

Permettre à un programme Azure-8 de :

```txt
Lire des données

Écrire des données

Déplacer des données

Manipuler la pile

Effectuer des calculs

Effectuer des branchements
```

---

# État actuel du CPU

## Instructions disponibles

```txt
00h  NOP

10h  MOV

FFh  HLT
```

---

## MOV

Première instruction de manipulation de données.

Format :

```asm
MOV Destination, Source
```

Exemple :

```asm
MOV A, B
```

Encodage :

```txt
10h

Byte 0 : Opcode

Byte 1 : Destination

Byte 2 : Source
```

Statut :

```txt
✅ Opcode

✅ Décodage

✅ Exécution
```

---

# Ordre de développement

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

Introduire les premières instructions permettant de manipuler des données.

---

## MOV

### Description

Copie une valeur d'un registre vers un autre.

Exemple :

```asm
MOV A, B
```

### Réalisation

- [x] Opcode
- [x] Décodage
- [x] Exécution

### Reste à faire

- [ ] mov.rom
- [ ] Test automatisé

---

## LOAD

### Description

Charger une valeur mémoire vers un registre.

Exemple :

```asm
LOAD A, 1000h
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Tests

---

## STORE

### Description

Écrire un registre en mémoire.

Exemple :

```asm
STORE A, 1000h
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Tests

---

## Statut

🟨 EN COURS

---

# Lot B - Pile avancée

## Objectif

Permettre la manipulation de la pile par le jeu d'instructions.

---

## PUSH

```asm
PUSH A
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Tests

---

## POP

```asm
POP A
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Tests

---

## CALL

```asm
CALL 1000h
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Tests

---

## RET

```asm
RET
```

- [ ] Opcode
- [ ] Décodage
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
- [ ] Gestion FLAGS
- [ ] Tests

---

## DEC

```asm
DEC A
```

- [ ] Implémentation
- [ ] Gestion FLAGS
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
- [ ] Gestion FLAGS
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

## JMP

```asm
JMP Adresse
```

- [ ] Implémentation
- [ ] Tests

---

## JZ

```asm
JZ Adresse
```

- [ ] Implémentation
- [ ] Tests

---

## JNZ

```asm
JNZ Adresse
```

- [ ] Implémentation
- [ ] Tests

---

## Statut

⬜ Non commencé

---

# Lot E - ROMs de validation

## Objectif

Valider chaque nouvelle instruction.

---

### ROMs existantes

- [ ] memory16.rom
- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

---

### Nouvelles ROMs

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

Maintenir la documentation synchronisée avec le code.

---

### Documentation

- [ ] Mise à jour Architecture.md

- [ ] Mise à jour Documentation Stack.md

- [ ] Mise à jour Documentation FLAGS.md

- [ ] Azure-8_Instruction_Set_v0.0.3.md

- [ ] Azure-8_Technical_Specification_v0.0.3.txt

- [ ] Mise à jour README.md

---

## Statut

⬜ Non commencé

---

# Lot G - Tests automatisés

## Objectif

Étendre la couverture de tests.

---

### Instructions de données

- [ ] Test MOV

- [ ] Test LOAD

- [ ] Test STORE

---

### Instructions pile

- [ ] Test PUSH

- [ ] Test POP

- [ ] Test CALL

- [ ] Test RET

---

### Instructions arithmétiques

- [ ] Test INC

- [ ] Test DEC

- [ ] Test ADD

- [ ] Test SUB

---

### Branchements

- [ ] Test CMP

- [ ] Test JMP

- [ ] Test JZ

- [ ] Test JNZ

---

## Statut

⬜ Non commencé

---

# Critères de validation

## CPU

### Données

- [x] MOV

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

### Branchements

- [ ] CMP

- [ ] JMP

- [ ] JZ

- [ ] JNZ

---

## Documentation

- [ ] Documentation complète

---

## ROMs

- [ ] ROMs validées

---

## Compilation

- [ ] Build Debug

- [ ] Build Release

- [ ] 0 erreur

- [ ] 0 warning

---

## Tests

- [ ] Tests automatisés complets

---

# État actuel

```txt
Projet      : AzureEngine

Version     : v0.0.3-alpha

CPU         : 8 bits

PC          : 16 bits

SP          : 16 bits

FLAGS       : 8 bits

RAM         : 64 Ko

Progression : 5 %

État :

MOV implémenté

Priorité :

MOV ROM
↓
MOV Test
↓
LOAD
↓
STORE
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter un programme du type :

```asm
LOAD A, 1000h

LOAD B, 1001h

ADD A, B

STORE A, 2000h

HLT
```

Cette version transformera Azure-8 d'une infrastructure validée en un processeur capable d'exécuter de véritables programmes.

---

**Fin de roadmap v0.0.3-alpha**