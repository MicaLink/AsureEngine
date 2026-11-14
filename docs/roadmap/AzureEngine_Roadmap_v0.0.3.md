# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **Développement avancé**
>
> Architecture : **Azure-8**
>
> Progression estimée : **93 %**
>
> Priorité actuelle : **JZ (0x42)**
>
> Lot actif : **Lot D - Comparaisons et branchements**

---

# Vision de la version v0.0.3

La version v0.0.3 transforme Azure‑8 en un processeur programmable complet capable de :

```txt
Manipuler des données

Accéder à la mémoire

Gérer une pile

Exécuter des sous-routines

Effectuer des calculs

Comparer des valeurs

Modifier le flux d'exécution
```

L'objectif restant est la validation des derniers branchements conditionnels.

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

Implémentés :

```txt
✅ ZERO

✅ CARRY

✅ NEGATIVE

✅ OVERFLOW (infrastructure)
```

---

# Jeu d'instructions validé

## Contrôle CPU

```txt
✅ NOP (00h)

✅ HLT (FFh)
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

Statut :

```txt
✅ LOT B TERMINÉ
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

Statut :

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
✅ Implémentation

✅ TestCMP

✅ cmp.rom

✅ Validation ROM

✅ FLAG_ZERO

✅ FLAG_NEGATIVE

✅ FLAG_CARRY
```

### Exemple validé

```txt
42 - 42 = 00

FLAGS = 01h
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

### Exemple validé

```txt
JMP 0004h

↓

PC = 0004h

↓

HLT
```

### Validation ROM

Trace obtenue :

```txt
PC=0000 OPCODE=41

↓

PC=0004 OPCODE=FF
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

### Description

```asm
JZ Adresse
```

### Fonction

```txt
Saut si FLAG_ZERO = 1
```

### Validation

```txt
⬜ Implémentation

⬜ TestJZ

⬜ jz.rom

⬜ Validation ROM
```

### Statut

```txt
🟨 PRIORITÉ ACTUELLE
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

---

## Progression Lot D

```txt
✅ CMP

✅ JMP

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

✅ jmp.rom
```

---

# ROMs à créer

```txt
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

✅ TestJMP
```

---

# Tests automatisés à réaliser

```txt
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

✅ JMP

✅ 13 instructions validées

✅ 13 tests validés

✅ 13 ROMs validées

✅ Gestion mémoire

✅ Gestion pile

✅ Sous-routines

✅ Arithmétique

✅ Comparaison

✅ Branchements inconditionnels
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

Progression  : 93 %
```

---

# Priorité immédiate

```txt
1. Implémenter JZ

2. Créer TestJZ

3. Créer jz.rom

4. Valider jz.rom

5. Implémenter JNZ

6. Créer TestJNZ

7. Créer jnz.rom

8. Valider jnz.rom
```

---

# Objectif de fin de version

Azure‑8 devra être capable d'exécuter :

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

Ce scénario validera :

```txt
✅ Mémoire

✅ Arithmétique

✅ Comparaison

✅ Saut conditionnel

✅ Saut inconditionnel

✅ Contrôle de flux complet
```

---

**Fin de roadmap v0.0.3-alpha**