# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **Finalisation**
>
> Architecture : **Azure-8**
>
> Progression estimée : **96 %**
>
> Priorité actuelle : **JNZ (0x43)**
>
> Lot actif : **Lot D - Comparaisons et branchements**

---

# Vision de la version v0.0.3

La version v0.0.3 transforme Azure‑8 en un processeur programmable complet.

Fonctionnalités désormais disponibles :

```txt
✅ Manipulation de données

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Arithmétique

✅ Comparaisons

✅ Branchements conditionnels
```

Il ne reste plus qu'une seule instruction à valider avant la clôture du Lot D.

---

# Architecture actuelle

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

Définition :

```cpp
FLAG_ZERO     = (1 << 0);

FLAG_CARRY    = (1 << 1);

FLAG_NEGATIVE = (1 << 2);

FLAG_OVERFLOW = (1 << 3);
```

---

# Jeu d'instructions Azure‑8

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

## Comparaisons

```txt
✅ CMP (40h)
```

---

## Branchements

```txt
✅ JMP (41h)

✅ JZ  (42h)

⬜ JNZ (43h)
```

---

# État des lots

```txt
✅ Lot A - Données

✅ Lot B - Pile avancée

✅ Lot C - Arithmétique

🟨 Lot D - Comparaisons et branchements

⬜ Lot E - Documentation finale

⬜ Lot F - Clôture v0.0.3
```

---

# Lot A - Données

## Validation complète

```txt
✅ MOV

✅ LOAD

✅ STORE
```

ROMs :

```txt
✅ mov.rom

✅ load.rom

✅ store.rom
```

Statut :

```txt
✅ TERMINÉ
```

---

# Lot B - Pile avancée

## Validation complète

```txt
✅ PUSH

✅ POP

✅ CALL

✅ RET
```

ROMs :

```txt
✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom
```

Validation obtenue :

```txt
✅ Pile 8 bits

✅ Pile 16 bits

✅ Sous-routines

✅ Adresse de retour

✅ Contrôle de flux
```

Statut :

```txt
✅ TERMINÉ
```

---

# Lot C - Arithmétique

## Validation complète

```txt
✅ INC

✅ DEC

✅ ADD

✅ SUB
```

ROMs :

```txt
✅ inc.rom

✅ dec.rom

✅ add.rom

✅ sub.rom
```

Validation obtenue :

```txt
✅ ZERO

✅ NEGATIVE

✅ CARRY (ADD/SUB)

✅ Infrastructure OVERFLOW
```

Statut :

```txt
✅ TERMINÉ
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
✅ Implémentation

✅ TestCMP

✅ cmp.rom

✅ Validation ROM
```

Validation ROM :

```txt
CMP 42, 42

↓

FLAGS = 01h

ZERO = SET
```

Statut :

```txt
✅ TERMINÉ
```

---

## JMP

### Opcode

```txt
41h
```

### Validation

```txt
✅ Implémentation

✅ TestJMP

✅ jmp.rom

✅ Validation ROM
```

Validation ROM :

```txt
PC=0000

↓

JMP 0004h

↓

PC=0004
```

Statut :

```txt
✅ TERMINÉ
```

---

## JZ

### Opcode

```txt
42h
```

### Fonction

```txt
Saut si FLAG_ZERO = 1
```

### Validation

```txt
✅ Implémentation

✅ TestJZ

✅ jz.rom

✅ Validation ROM
```

Validation ROM :

```txt
ZERO = SET

↓

JZ 0004h

↓

PC = 0004h

↓

HLT
```

Statut :

```txt
✅ TERMINÉ
```

---

## JNZ

### Opcode

```txt
43h
```

### Fonction

```txt
Saut si FLAG_ZERO = 0
```

### Validation

```txt
⬜ Implémentation

⬜ TestJNZ

⬜ jnz.rom

⬜ Validation ROM
```

### Statut

```txt
🟨 PRIORITÉ ACTUELLE
```

---

## Progression du Lot D

```txt
✅ CMP

✅ JMP

✅ JZ

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

✅ jmp.rom

✅ jz.rom
```

---

# ROMs restantes

```txt
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

✅ TestJMP

✅ TestJZ
```

---

# Tests restants

```txt
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

✅ JMP

✅ JZ

✅ 14 instructions validées

✅ 14 tests validés

✅ 14 ROMs validées

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Arithmétique

✅ Comparaisons

✅ Branchements conditionnels
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

Progression  : 96 %
```

---

# Priorité immédiate

```txt
1. Implémenter JNZ

2. Créer TestJNZ

3. Valider TestJNZ

4. Créer jnz.rom

5. Valider jnz.rom

6. Clôturer le Lot D

7. Finaliser v0.0.3
```

---

# Objectif de clôture v0.0.3

À la fin de la version :

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

devra s'exécuter correctement.

Cette démonstration validera :

```txt
✅ Mémoire

✅ Arithmétique

✅ Comparaison

✅ Sauts conditionnels

✅ Sauts inconditionnels

✅ Contrôle de flux complet
```

---

**Fin de roadmap v0.0.3-alpha**