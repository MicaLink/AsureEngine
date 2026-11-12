# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **50 %**
>
> Priorité actuelle : **RET**

---

# Présentation

La version v0.0.3-alpha transforme progressivement Azure-8 en un processeur programmable.

Après la mise en place complète de l'infrastructure lors de la v0.0.2, cette version apporte les premières instructions utilisables :

```txt
Manipulation des registres

Lecture mémoire

Écriture mémoire

Pile

Sous-routines
```

La moitié de la roadmap est désormais validée.

---

# Philosophie

Azure-8 continue d'être développé selon les principes du projet AzureEngine :

```txt
Assembler autant que possible

C avant C++

Architecture simple

Code facilement lisible

Compréhension complète
du matériel émulé

Développement progressif

Documentation systématique
```

---

# État actuel du processeur

## Instructions validées

```txt
00h  NOP

10h  MOV
11h  LOAD
12h  STORE

20h  PUSH
21h  POP
22h  CALL

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

✅ Stack Pointer

✅ FLAGS

✅ ROM Loader

✅ Debug

✅ Tests automatisés
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

## MOV

```asm
MOV A, B
```

### Validation

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestMOV
✅ mov.rom
```

### Statut

✅ TERMINÉ

---

## LOAD

```asm
LOAD A, 1000h
```

### Validation

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestLOAD
✅ load.rom
```

### Statut

✅ TERMINÉ

---

## STORE

```asm
STORE A, 1000h
```

### Validation

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestSTORE
✅ store.rom
```

### Validation ROM

```txt
Memory[1000h] before execution = 0

↓

STORE A, 1000h

↓

Memory[1000h] after execution = 42
```

### Statut

✅ TERMINÉ

---

## Résultat

Premier cycle complet mémoire ↔ registres validé.

```asm
LOAD  A, 1000h

MOV   B, A

STORE B, 1001h

HLT
```

### Statut

✅ LOT A TERMINÉ

---

# Lot B - Pile avancée

## Objectif

Permettre aux instructions Azure-8 d'utiliser directement la pile.

Infrastructure disponible :

```txt
✅ Push8()

✅ Pop8()

✅ Push16()

✅ Pop16()

✅ Stack Pointer

✅ Overflow

✅ Underflow
```

---

## PUSH

```asm
PUSH A
```

Opcode :

```txt
20h
```

### Validation

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestPUSH
✅ push.rom
```

### Validation ROM

```txt
A = 42

↓

PUSH A

↓

Memory[FFFF] = 42

↓

SP = FFFE
```

### Statut

✅ TERMINÉ

---

## POP

```asm
POP B
```

Opcode :

```txt
21h
```

### Validation

```txt
✅ Opcode
✅ Décodage
✅ Exécution
✅ TestPOP
✅ pop.rom
```

### Validation ROM

```txt
Memory[FFFF] = 42

↓

POP B

↓

B = 42

↓

SP = FFFF
```

### Statut

✅ TERMINÉ

---

## CALL

```asm
CALL Adresse
```

Opcode :

```txt
22h
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Sauvegarde adresse retour

✅ Push16()

✅ Modification du PC

✅ TestCALL

✅ call.rom
```

### Validation ROM

```txt
CALL 0004h

↓

Push16(0003h)

↓

PC = 0004h

↓

HLT
```

Résultat :

```txt
Stack[FFFE] = 03

Stack[FFFF] = 00

SP = FFFD

PC = 0005
```

### Statut

✅ TERMINÉ

---

## RET

```asm
RET
```

Opcode prévu :

```txt
23h
```

### Objectif

```txt
Récupérer l'adresse de retour

Restaurer PC

Revenir à l'appelant
```

### Réalisation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ TestRET

⬜ ret.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

---

## État du Lot B

```txt
✅ PUSH

✅ POP

✅ CALL

⬜ RET
```

### Progression

```txt
75 %
```

---

# Lot C - Arithmétique

## INC

```txt
⬜ Implémentation
⬜ FLAGS
⬜ Test
⬜ inc.rom
```

---

## DEC

```txt
⬜ Implémentation
⬜ FLAGS
⬜ Test
⬜ dec.rom
```

---

## ADD

```txt
⬜ Implémentation
⬜ FLAGS
⬜ Test
⬜ add.rom
```

---

## SUB

```txt
⬜ Implémentation
⬜ FLAGS
⬜ Test
⬜ sub.rom
```

---

## Statut

⬜ Non commencé

---

# Lot D - Comparaisons et branchements

## CMP

```txt
⬜ Implémentation
⬜ FLAGS
⬜ Test
⬜ cmp.rom
```

---

## JMP

```txt
⬜ Implémentation
⬜ Test
⬜ jmp.rom
```

---

## JZ

```txt
⬜ Implémentation
⬜ Test
⬜ jz.rom
```

---

## JNZ

```txt
⬜ Implémentation
⬜ Test
⬜ jnz.rom
```

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

✅ load.rom

✅ store.rom

✅ push.rom

✅ pop.rom

✅ call.rom
```

---

## ROMs existantes à revalider

```txt
⬜ memory16.rom

⬜ stack8.rom

⬜ stack16.rom

⬜ overflow.rom

⬜ underflow.rom
```

---

## ROMs à créer

### Pile

```txt
⬜ ret.rom
```

### Arithmétique

```txt
⬜ inc.rom

⬜ dec.rom

⬜ add.rom

⬜ sub.rom
```

### Branchements

```txt
⬜ cmp.rom

⬜ jmp.rom

⬜ jz.rom

⬜ jnz.rom
```

---

# Lot F - Documentation

## À mettre à jour

```txt
⬜ Architecture.md

⬜ Azure-8_Instruction_Set_v0.0.3.md

⬜ Azure-8_Technical_Specification_v0.0.3.txt

⬜ README.md
```

---

# Lot G - Tests automatisés

## Validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH

✅ TestPOP

✅ TestCALL
```

---

## À réaliser

### Pile

```txt
⬜ TestRET
```

### Arithmétique

```txt
⬜ TestINC

⬜ TestDEC

⬜ TestADD

⬜ TestSUB
```

### Branchements

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

⬜ RET
```

---

## Arithmétique

```txt
⬜ INC

⬜ DEC

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

Progression : 50 %
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

✅ 6 nouvelles instructions validées

✅ 6 tests automatisés validés

✅ 6 ROMs validées

✅ Gestion mémoire

✅ Gestion registres

✅ Gestion pile

✅ Premier mécanisme de sous-routine
```

---

# Priorité immédiate

```txt
Lot B

1. RET

2. TestRET

3. ret.rom

4. Validation RET
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter :

```asm
CALL Routine

...

Routine:

PUSH A

POP A

RET
```

puis :

```asm
LOAD  A, 1000h

LOAD  B, 1001h

ADD   A, B

STORE A, 2000h

HLT
```

Cette version transformera Azure-8 en un processeur programmable capable d'exécuter de véritables programmes structurés.

---

**Fin de roadmap v0.0.3-alpha**