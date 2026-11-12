# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **70 %**
>
> Priorité actuelle : **ADD (0x32)**
>
> Lot actif : **Lot C - Arithmétique**

---

# Présentation

La version v0.0.3-alpha marque l'entrée d'Azure‑8 dans sa première phase de calcul.

Les fondations du processeur sont désormais terminées :

```txt
✅ Registres

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Chargement ROM

✅ Tests automatisés
```

Azure‑8 est maintenant capable de :

```txt
Lire la mémoire

↓

Manipuler les registres

↓

Utiliser la pile

↓

Exécuter des sous-routines

↓

Effectuer des opérations arithmétiques simples
```

---

# Philosophie

AzureEngine continue de suivre ses principes :

```txt
Assembler autant que possible

C avant C++

Code simple

Architecture lisible

Validation systématique

Documentation continue
```

---

# Jeu d'instructions actuel

## Instructions validées

```txt
00h  NOP

10h  MOV
11h  LOAD
12h  STORE

20h  PUSH
21h  POP
22h  CALL
23h  RET

30h  INC
31h  DEC

FFh  HLT
```

---

# Infrastructure validée

```txt
✅ RAM 64 Ko

✅ Read8()
✅ Write8()

✅ Read16()
✅ Write16()

✅ Stack

✅ Push8()
✅ Pop8()

✅ Push16()
✅ Pop16()

✅ Program Counter

✅ Stack Pointer

✅ FLAGS

✅ ROM Loader

✅ Debug

✅ Tests automatisés
```

---

# État des lots

```txt
✅ Lot A - Instructions de données

✅ Lot B - Pile avancée

🟨 Lot C - Arithmétique

⬜ Lot D - Comparaisons et branchements

⬜ Lot E - ROMs de validation

⬜ Lot F - Documentation

⬜ Lot G - Tests automatisés
```

---

# Lot A - Instructions de données

## MOV

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestMOV
✅ mov.rom
```

---

## LOAD

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestLOAD
✅ load.rom
```

---

## STORE

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestSTORE
✅ store.rom
```

---

## Statut

```txt
✅ LOT A TERMINÉ
```

---

# Lot B - Pile avancée

## PUSH

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestPUSH
✅ push.rom
```

---

## POP

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestPOP
✅ pop.rom
```

---

## CALL

```txt
✅ Opcode
✅ Décodage
✅ Push16()
✅ Sauvegarde de l'adresse de retour
✅ Modification du PC
✅ TestCALL
✅ call.rom
```

---

## RET

```txt
✅ Opcode
✅ Décodage
✅ Pop16()
✅ Restauration du PC
✅ TestRET
✅ ret.rom
```

---

## Validation complète

Sous-routine validée :

```asm
CALL Routine

Routine:
RET
```

Validation obtenue :

```txt
✅ Adresse de retour

✅ Push16()

✅ Pop16()

✅ Contrôle de flux

✅ Sous-routines fonctionnelles
```

---

## Statut

```txt
✅ LOT B TERMINÉ
```

---

# Lot C - Arithmétique

## Objectif

Introduire les premières capacités de calcul.

Les instructions de ce lot permettront de valider :

```txt
FLAG_ZERO

FLAG_NEGATIVE

FLAG_CARRY

FLAG_OVERFLOW
```

---

## INC

### Description

```asm
INC A
```

### Opcode

```txt
30h
```

### Fonction

```txt
A = A + 1
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ FLAG_ZERO

✅ FLAG_NEGATIVE

✅ TestINC

✅ inc.rom
```

### Validation ROM

```txt
A = 41

↓

INC A

↓

A = 42
```

### Statut

✅ TERMINÉ

---

## DEC

### Description

```asm
DEC A
```

### Opcode

```txt
31h
```

### Fonction

```txt
A = A - 1
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ FLAG_ZERO

✅ FLAG_NEGATIVE

✅ TestDEC

✅ dec.rom
```

### Validation ROM

```txt
A = 42

↓

DEC A

↓

A = 41
```

### Statut

✅ TERMINÉ

---

## ADD

### Description

```asm
ADD A, B
```

### Opcode

```txt
32h
```

### Fonction

```txt
A = A + B
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ FLAG_CARRY

⬜ FLAG_OVERFLOW

⬜ TestADD

⬜ add.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

---

## SUB

### Description

```asm
SUB A, B
```

### Opcode

```txt
33h
```

### Fonction

```txt
A = A - B
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ FLAG_CARRY

⬜ FLAG_OVERFLOW

⬜ TestSUB

⬜ sub.rom
```

### Statut

⬜ NON COMMENCÉ

---

## Statut du Lot C

```txt
✅ INC

✅ DEC

⬜ ADD

⬜ SUB
```

Progression :

```txt
50 %
```

---

# Lot D - Comparaisons et branchements

## CMP

```txt
⬜ Implémentation
⬜ FLAGS
⬜ TestCMP
⬜ cmp.rom
```

---

## JMP

```txt
⬜ Implémentation
⬜ TestJMP
⬜ jmp.rom
```

---

## JZ

```txt
⬜ Implémentation
⬜ TestJZ
⬜ jz.rom
```

---

## JNZ

```txt
⬜ Implémentation
⬜ TestJNZ
⬜ jnz.rom
```

---

## Statut

```txt
⬜ NON COMMENCÉ
```

---

# ROMs validées

```txt
✅ nop.rom

✅ halt.rom

✅ invalid.rom

✅ mov.rom

✅ load.rom

✅ store.rom

✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom

✅ inc.rom

✅ dec.rom
```

---

# ROMs à créer

## Arithmétique

```txt
⬜ add.rom

⬜ sub.rom
```

## Branchements

```txt
⬜ cmp.rom

⬜ jmp.rom

⬜ jz.rom

⬜ jnz.rom
```

---

# Tests automatisés validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH

✅ TestPOP

✅ TestCALL

✅ TestRET

✅ TestINC

✅ TestDEC
```

---

# Tests automatisés à réaliser

## Arithmétique

```txt
⬜ TestADD

⬜ TestSUB
```

## Branchements

```txt
⬜ TestCMP

⬜ TestJMP

⬜ TestJZ

⬜ TestJNZ
```

---

# Critères de validation

## Données

```txt
✅ MOV

✅ LOAD

✅ STORE
```

---

## Pile

```txt
✅ PUSH

✅ POP

✅ CALL

✅ RET
```

---

## Arithmétique

```txt
✅ INC

✅ DEC

⬜ ADD

⬜ SUB
```

---

## Branchements

```txt
⬜ CMP

⬜ JMP

⬜ JZ

⬜ JNZ
```

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

Progression : 70 %
```

---

# Accomplissements v0.0.3

```txt
✅ MOV

✅ LOAD

✅ STORE

✅ PUSH

✅ POP

✅ CALL

✅ RET

✅ INC

✅ DEC

✅ 9 nouvelles instructions validées

✅ 9 tests automatisés validés

✅ 9 ROMs validées

✅ Gestion mémoire

✅ Gestion pile

✅ Sous-routines

✅ Premières opérations arithmétiques
```

---

# Priorité immédiate

```txt
Lot C

1. ADD

2. TestADD

3. add.rom

4. Validation ROM

5. SUB

6. TestSUB

7. sub.rom

8. Validation ROM
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure‑8 devra être capable d'exécuter :

```asm
LOAD  A, 1000h

LOAD  B, 1001h

ADD   A, B

STORE A, 2000h

HLT
```

ainsi que :

```asm
CALL Routine

Routine:

PUSH A

POP A

RET
```

Cette version transformera Azure‑8 en un processeur programmable disposant de mémoire, pile, sous-routines et calcul arithmétique.

---

**Fin de roadmap v0.0.3-alpha**