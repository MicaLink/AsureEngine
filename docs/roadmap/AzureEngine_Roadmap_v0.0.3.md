# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **65 %**
>
> Priorité actuelle : **DEC (0x31)**
>
> Lot actif : **Lot C - Arithmétique**

---

# Présentation

La version v0.0.3-alpha poursuit la transformation d'Azure‑8 en un processeur programmable capable d'exécuter de véritables programmes.

Les blocs fondamentaux sont désormais validés :

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

Appeler une sous-routine

↓

Retourner à l'appelant
```

---

# Philosophie

AzureEngine continue de suivre ses principes fondateurs :

```txt
Assembler autant que possible

C avant C++

Code lisible

Développement incrémental

Validation systématique

Documentation continue
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
23h  RET

30h  INC

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
✅ Sauvegarde adresse retour
✅ Modification PC
✅ TestCALL
✅ call.rom
```

---

## RET

```txt
✅ Opcode
✅ Décodage
✅ Pop16()
✅ Restauration PC
✅ TestRET
✅ ret.rom
```

---

## Validation complète

Sous-routines validées :

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

Les instructions arithmétiques permettront de valider :

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
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ TestDEC

⬜ dec.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

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

### Opcode

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
🟨 EN COURS
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

✅ inc.rom
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

✅ TestINC
```

---

## À réaliser

### Arithmétique

```txt
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
✅ INC

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

Progression : 65 %
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

✅ 8 nouvelles instructions validées

✅ 8 tests automatisés validés

✅ 8 ROMs validées

✅ Gestion mémoire

✅ Gestion pile

✅ Sous-routines

✅ Première instruction arithmétique
```

---

# Priorité immédiate

```txt
Lot C

1. DEC

2. TestDEC

3. dec.rom

4. Validation ROM

5. ADD

6. TestADD

7. add.rom

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

et :

```asm
CALL Routine

Routine:

PUSH A

POP A

RET
```

Cette version transformera Azure‑8 en un processeur programmable capable d'exécuter des programmes structurés complets.

---

**Fin de roadmap v0.0.3-alpha**