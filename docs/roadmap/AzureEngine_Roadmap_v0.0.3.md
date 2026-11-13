# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **Développement avancé**
>
> Architecture : **Azure-8**
>
> Progression estimée : **90 %**
>
> Priorité actuelle : **JMP (0x41)**
>
> Lot actif : **Lot D - Comparaisons et branchements**

---

# Vision de la version v0.0.3

La version v0.0.3 a pour objectif de transformer Azure‑8 en un processeur réellement programmable.

À l'issue de cette version, Azure‑8 devra maîtriser :

```txt
Manipulation de données

Mémoire

Pile

Sous-routines

Arithmétique

Comparaisons

Branchements
```

---

# État actuel du processeur

## Registres généraux

```txt
A
B
C
D
```

Codage :

```txt
00h = A

01h = B

02h = C

03h = D
```

---

## Registres système

```txt
PC

SP

FLAGS
```

---

## FLAGS

```txt
Bit 0 = ZERO

Bit 1 = CARRY

Bit 2 = NEGATIVE

Bit 3 = OVERFLOW
```

Définition actuelle :

```cpp
FLAG_ZERO     = (1 << 0);

FLAG_CARRY    = (1 << 1);

FLAG_NEGATIVE = (1 << 2);

FLAG_OVERFLOW = (1 << 3);
```

---

# Jeu d'instructions validé

## Contrôle CPU

```txt
✅ NOP  (00h)

✅ HLT  (FFh)
```

---

## Données

```txt
✅ MOV   (10h)

✅ LOAD  (11h)

✅ STORE (12h)
```

---

## Pile

```txt
✅ PUSH (20h)

✅ POP  (21h)

✅ CALL (22h)

✅ RET  (23h)
```

---

## Arithmétique

```txt
✅ INC (30h)

✅ DEC (31h)

✅ ADD (32h)

✅ SUB (33h)
```

---

## Comparaison

```txt
✅ CMP (40h)
```

---

# État des lots

```txt
✅ Lot A - Données

✅ Lot B - Pile avancée

✅ Lot C - Arithmétique

🟨 Lot D - Comparaisons et branchements

⬜ Lot E - Documentation

⬜ Lot F - Finalisation v0.0.3
```

---

# Lot A - Données

## MOV

```txt
✅ Implémentation

✅ TestMOV

✅ mov.rom
```

---

## LOAD

```txt
✅ Implémentation

✅ TestLOAD

✅ load.rom
```

---

## STORE

```txt
✅ Implémentation

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
✅ Implémentation

✅ TestPUSH

✅ push.rom
```

---

## POP

```txt
✅ Implémentation

✅ TestPOP

✅ pop.rom
```

---

## CALL

```txt
✅ Implémentation

✅ TestCALL

✅ call.rom
```

---

## RET

```txt
✅ Implémentation

✅ TestRET

✅ ret.rom
```

---

## Validation obtenue

```txt
✅ Push8()

✅ Pop8()

✅ Push16()

✅ Pop16()

✅ Sous-routines

✅ Adresse de retour

✅ Contrôle de flux
```

---

## Statut

```txt
✅ LOT B TERMINÉ
```

---

# Lot C - Arithmétique

## INC

```txt
✅ Implémentation

✅ TestINC

✅ inc.rom
```

---

## DEC

```txt
✅ Implémentation

✅ TestDEC

✅ dec.rom
```

---

## ADD

```txt
✅ Implémentation

✅ TestADD

✅ add.rom
```

Validation :

```txt
10 + 32 = 42
```

---

## SUB

```txt
✅ Implémentation

✅ TestSUB

✅ sub.rom
```

Validation :

```txt
50 - 8 = 42
```

---

## Statut

```txt
✅ LOT C TERMINÉ
```

---

# Lot D - Comparaisons et branchements

## CMP

### Opcode

```txt
40h
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Lecture des registres

✅ Comparaison

✅ FLAG_ZERO

✅ FLAG_NEGATIVE

✅ FLAG_CARRY

✅ TestCMP

✅ cmp.rom
```

### Validation ROM

```txt
A = 42

B = 42

↓

CMP A, B

↓

FLAGS = 01h

ZERO     = SET

CARRY    = CLEAR

NEGATIVE = CLEAR

OVERFLOW = CLEAR
```

### Statut

```txt
✅ TERMINÉ
```

---

## JMP

### Opcode

```txt
41h
```

### Description

```asm
JMP Adresse
```

### Validation

```txt
⬜ Implémentation

⬜ TestJMP

⬜ jmp.rom

⬜ Validation ROM
```

### Statut

```txt
🟨 PRIORITÉ ACTUELLE
```

---

## JZ

### Opcode

```txt
42h
```

### Description

```asm
JZ Adresse
```

### Validation

```txt
⬜ Implémentation

⬜ Lecture FLAG_ZERO

⬜ TestJZ

⬜ jz.rom

⬜ Validation ROM
```

---

## JNZ

### Opcode

```txt
43h
```

### Description

```asm
JNZ Adresse
```

### Validation

```txt
⬜ Implémentation

⬜ Lecture FLAG_ZERO

⬜ TestJNZ

⬜ jnz.rom

⬜ Validation ROM
```

---

## Progression du Lot D

```txt
✅ CMP

⬜ JMP

⬜ JZ

⬜ JNZ
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

✅ add.rom

✅ sub.rom

✅ cmp.rom
```

---

# ROMs à créer

```txt
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

✅ TestADD

✅ TestSUB

✅ TestCMP
```

---

# Tests automatisés à réaliser

```txt
⬜ TestJMP

⬜ TestJZ

⬜ TestJNZ
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

✅ ADD

✅ SUB

✅ CMP

✅ 12 instructions validées

✅ 12 tests automatisés validés

✅ 12 ROMs validées

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Arithmétique

✅ Comparaison
```

---

# État actuel

```txt
Projet       : AzureEngine

Architecture : Azure-8

Version      : v0.0.3-alpha

CPU          : 8 bits

PC           : 16 bits

SP           : 16 bits

RAM          : 64 Ko

FLAGS        :
    ZERO
    CARRY
    NEGATIVE
    OVERFLOW

Progression  : 90 %
```

---

# Priorité immédiate

```txt
1. Implémenter JMP

2. Créer TestJMP

3. Créer jmp.rom

4. Valider jmp.rom

5. Implémenter JZ

6. Créer TestJZ

7. Créer jz.rom
```

---

# Objectif de fin de version

À la fin de la v0.0.3, Azure‑8 devra pouvoir exécuter :

```asm
LOAD A, 1000h

LOAD B, 1001h

CMP A, B

JZ Equal

ADD A, B

JMP End

Equal:

STORE A, 2000h

End:

HLT
```

Cette démonstration validera simultanément :

```txt
Mémoire

Arithmétique

Comparaison

Branchement conditionnel

Contrôle de flux
```

---

**Fin de roadmap v0.0.3-alpha**