# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **60 %**
>
> Priorité actuelle : **Lot C - Arithmétique**
>
> Prochaine instruction : **INC (0x30)**

---

# Présentation

La version v0.0.3-alpha marque une étape majeure dans l'évolution d'Azure-8.

Les systèmes fondamentaux sont désormais opérationnels :

```txt
✅ Mémoire

✅ Registres

✅ Pile

✅ Sous-routines

✅ Chargement ROM

✅ Tests automatisés
```

Azure-8 peut désormais exécuter de véritables programmes structurés utilisant :

```txt
Mémoire

↓

Registres

↓

Pile

↓

Sous-routines
```

---

# Philosophie

AzureEngine continue de suivre les principes suivants :

```txt
Assembler autant que possible

C avant C++

Code simple et lisible

Architecture facilement compréhensible

Développement incrémental

Validation systématique

Documentation continue
```

---

# État actuel du processeur

## Jeu d'instructions validé

```txt
00h  NOP

10h  MOV
11h  LOAD
12h  STORE

20h  PUSH
21h  POP
22h  CALL
23h  RET

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

✅ Push8()
✅ Pop8()

✅ Push16()
✅ Pop16()

✅ FLAGS

✅ ROM Loader

✅ Debug

✅ Tests automatisés
```

---

# Ordre de développement

```txt
✅ Lot A - Instructions de données

✅ Lot B - Pile avancée

⬜ Lot C - Arithmétique

⬜ Lot D - Comparaisons et branchements

⬜ Lot E - ROMs de validation

⬜ Lot F - Documentation

⬜ Lot G - Tests automatisés
```

---

# Lot A - Instructions de données

## MOV

```asm
MOV A, B
```

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestMOV

✅ mov.rom
```

---

## LOAD

```asm
LOAD A, 1000h
```

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestLOAD

✅ load.rom
```

---

## STORE

```asm
STORE A, 1000h
```

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

```asm
PUSH A
```

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestPUSH

✅ push.rom
```

---

## POP

```asm
POP B
```

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestPOP

✅ pop.rom
```

---

## CALL

```asm
CALL Adresse
```

```txt
✅ Opcode

✅ Décodage

✅ Push16()

✅ Sauvegarde adresse retour

✅ Modification du PC

✅ TestCALL

✅ call.rom
```

---

## RET

```asm
RET
```

```txt
✅ Opcode

✅ Décodage

✅ Pop16()

✅ Restauration du PC

✅ TestRET

✅ ret.rom
```

---

## Validation ROM complète

Sous-routine validée :

```asm
CALL Routine

Routine:
RET
```

Résultat :

```txt
✅ Push16()

✅ Pop16()

✅ Adresse de retour

✅ Contrôle de flux

✅ Sous-routine complète
```

---

## Statut

```txt
✅ LOT B TERMINÉ
```

---

# Lot C - Arithmétique

## Objectif

Ajouter les premières capacités de calcul au processeur.

Les premières instructions arithmétiques serviront également à valider :

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

### Opcode prévu

```txt
30h
```

### Fonction

```txt
A = A + 1
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ TestINC

⬜ inc.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

---

## DEC

### Description

```asm
DEC A
```

### Opcode prévu

```txt
31h
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAGS

⬜ TestDEC

⬜ dec.rom
```

---

## ADD

### Description

```asm
ADD A, B
```

### Opcode prévu

```txt
32h
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

---

## SUB

### Description

```asm
SUB A, B
```

### Opcode prévu

```txt
33h
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAGS

⬜ TestSUB

⬜ sub.rom
```

---

## Statut

```txt
⬜ NON COMMENCÉ
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

✅ ret.rom
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

## Tests validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH

✅ TestPOP

✅ TestCALL

✅ TestRET
```

---

## À réaliser

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

✅ RET
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

Progression : 60 %
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

✅ 7 nouvelles instructions validées

✅ 7 tests automatisés validés

✅ 7 ROMs validées

✅ Mémoire

✅ Pile

✅ Sous-routines
```

---

# Priorité immédiate

```txt
Lot C

1. INC

2. TestINC

3. inc.rom

4. Validation ROM

5. DEC

6. TestDEC

7. dec.rom
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter :

```asm
LOAD  A, 1000h

LOAD  B, 1001h

ADD   A, B

STORE A, 2000h

HLT
```

et :

```asm
CALL Routine

Routine:

PUSH A

POP A

RET
```

Cette version transformera Azure-8 en un processeur programmable capable d'exécuter des programmes structurés complets.

---

**Fin de roadmap v0.0.3-alpha**