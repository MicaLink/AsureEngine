# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **10 %**
>
> Priorité actuelle : **LOAD**

---

# Présentation

La version v0.0.3-alpha marque le début de la transformation d'Azure-8 en un processeur réellement programmable.

La v0.0.2 a permis de construire et valider toute l'infrastructure fondamentale :

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

La v0.0.3 ajoute progressivement les premières instructions utiles permettant de manipuler des données, accéder à la mémoire et exécuter des programmes plus complexes.

---

# Philosophie

Azure-8 continue d'être développé selon les principes fondamentaux d'AzureEngine :

```txt
Assembler autant que possible

C avant C++

C++ simple et maîtrisé

Architecture claire

Développement progressif

Compréhension totale du matériel émulé

Documentation systématique
```

---

# Objectif principal

Permettre à Azure-8 de :

```txt
Déplacer des données

Lire la mémoire

Écrire la mémoire

Manipuler la pile

Effectuer des calculs

Effectuer des branchements
```

---

# État actuel du processeur

## Instructions disponibles

```txt
00h  NOP

10h  MOV

FFh  HLT
```

---

## Infrastructure disponible

```txt
✅ RAM 64 Ko

✅ Read8()
✅ Write8()

✅ Read16()
✅ Write16()

✅ Stack

✅ Stack Pointer

✅ FLAGS

✅ Debug

✅ ROM Loader
```

---

# Ordre de développement

```txt
Lot A - Instructions de données

Lot B - Pile avancée

Lot C - Arithmétique

Lot D - Comparaisons et branchements

Lot E - ROMs de validation

Lot F - Documentation

Lot G - Tests automatisés
```

---

# Lot A - Instructions de données

## Objectif

Permettre à Azure-8 de manipuler des données et d'interagir avec la mémoire.

---

## MOV

### Description

Copie une valeur d'un registre vers un autre.

Exemple :

```asm
MOV A, B
```

### Encodage

```txt
10h

Byte 0 : Opcode

Byte 1 : Destination

Byte 2 : Source
```

### Validation

- [x] Spécification
- [x] Opcode
- [x] Décodage
- [x] Exécution
- [x] Test automatisé
- [x] mov.rom validée

### Résultat

```txt
MOV terminé et validé.
```

---

## LOAD

### Description

Charge une valeur mémoire dans un registre.

Exemple :

```asm
LOAD A, 1000h
```

### Encodage

```txt
11h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] load.rom

### Priorité

🔥 PRIORITÉ ACTUELLE

---

## STORE

### Description

Écrit la valeur d'un registre dans la mémoire.

Exemple :

```asm
STORE A, 1000h
```

### Encodage

```txt
12h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] store.rom

---

## Statut

🟨 EN COURS

---

# Lot B - Pile avancée

## Objectif

Ajouter des instructions manipulant directement la pile.

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

# Lot D - Comparaisons et branchements

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

## ROMs validées

```txt
✅ nop.rom

✅ halt.rom

✅ invalid.rom

✅ mov.rom
```

---

## ROMs à réaliser

- [ ] load.rom
- [ ] store.rom

- [ ] arithmetic.rom

- [ ] branch.rom

- [ ] stack8.rom
- [ ] stack16.rom

---

## Statut

🟨 En cours

---

# Lot F - Documentation

## Documentation

- [ ] Mise à jour Architecture.md

- [ ] Azure-8_Instruction_Set_v0.0.3.md

- [ ] Azure-8_Technical_Specification_v0.0.3.txt

- [ ] Mise à jour README.md

---

## Statut

⬜ Non commencé

---

# Lot G - Tests automatisés

## Validés

```txt
✅ TestMOV
```

---

## À réaliser

### Mémoire

- [ ] TestLOAD
- [ ] TestSTORE

### Pile

- [ ] TestPUSH
- [ ] TestPOP
- [ ] TestCALL
- [ ] TestRET

### Arithmétique

- [ ] TestINC
- [ ] TestDEC
- [ ] TestADD
- [ ] TestSUB

### Branchements

- [ ] TestCMP
- [ ] TestJMP
- [ ] TestJZ
- [ ] TestJNZ

---

## Statut

🟨 En cours

---

# Critères de validation

## Instructions de données

- [x] MOV

- [ ] LOAD
- [ ] STORE

---

## Pile

- [ ] PUSH
- [ ] POP
- [ ] CALL
- [ ] RET

---

## Arithmétique

- [ ] INC
- [ ] DEC
- [ ] ADD
- [ ] SUB

---

## Branchements

- [ ] CMP
- [ ] JMP
- [ ] JZ
- [ ] JNZ

---

## ROMs

- [ ] ROMs validées

---

## Documentation

- [ ] Documentation complète

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

Progression : 10 %

MOV         ✅

LOAD        ⬜
STORE       ⬜
```

---

# Priorité immédiate

```txt
1. LOAD

2. load.rom

3. TestLOAD

4. STORE

5. store.rom

6. TestSTORE
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter un programme tel que :

```asm
LOAD A, 1000h

LOAD B, 1001h

ADD A, B

STORE A, 2000h

HLT
```

Cette version transformera Azure-8 d'une architecture de validation technique en un processeur capable d'exécuter de véritables programmes.

---

**Fin de roadmap v0.0.3-alpha**