# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement avancé**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **80 %**
>
> Priorité actuelle : **CMP (0x40)**
>
> Lot actif : **Lot D - Comparaisons et branchements**

---

# Présentation

La version v0.0.3-alpha a désormais validé l'ensemble du cœur d'exécution de base d'Azure‑8.

Les fonctionnalités suivantes sont désormais opérationnelles :

```txt
✅ Registres

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Arithmétique

✅ Chargement ROM

✅ Tests automatisés
```

Azure‑8 peut maintenant :

```txt
Lire des données

↓

Les manipuler

↓

Effectuer des calculs

↓

Utiliser la pile

↓

Exécuter des sous-routines
```

La prochaine étape consiste à introduire la logique de décision du processeur.

---

# État actuel du processeur

## Jeu d'instructions validé

### Système

```txt
00h NOP

FFh HLT
```

---

### Données

```txt
10h MOV

11h LOAD

12h STORE
```

---

### Pile

```txt
20h PUSH

21h POP

22h CALL

23h RET
```

---

### Arithmétique

```txt
30h INC

31h DEC

32h ADD

33h SUB
```

---

# Infrastructure validée

```txt
✅ RAM 64 Ko

✅ Read8()
✅ Write8()

✅ Read16()
✅ Write16()

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

✅ Lot C - Arithmétique

🟨 Lot D - Comparaisons et branchements

⬜ Lot E - Documentation

⬜ Lot F - Finalisation v0.0.3
```

---

# Lot A - Instructions de données

## Instructions validées

```txt
✅ MOV

✅ LOAD

✅ STORE
```

## ROMs validées

```txt
✅ mov.rom

✅ load.rom

✅ store.rom
```

## Statut

```txt
✅ TERMINÉ
```

---

# Lot B - Pile avancée

## Instructions validées

```txt
✅ PUSH

✅ POP

✅ CALL

✅ RET
```

## ROMs validées

```txt
✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom
```

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

## Statut

```txt
✅ TERMINÉ
```

---

# Lot C - Arithmétique

## INC

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestINC

✅ inc.rom
```

---

## DEC

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestDEC

✅ dec.rom
```

---

## ADD

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestADD

✅ add.rom
```

Validation ROM :

```txt
10 + 32 = 42
```

---

## SUB

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ TestSUB

✅ sub.rom
```

Validation ROM :

```txt
50 - 8 = 42
```

---

## Statut du Lot C

```txt
✅ INC

✅ DEC

✅ ADD

✅ SUB
```

```txt
✅ LOT C TERMINÉ
```

---

# Lot D - Comparaisons et branchements

## Objectif

Ajouter la logique décisionnelle du processeur.

Ce lot permettra :

```txt
Comparaisons

Conditions

Branches

Boucles

Contrôle de flux avancé
```

---

## CMP

### Description

```asm
CMP A, B
```

### Opcode proposé

```txt
40h
```

### Fonction

```txt
Effectuer A - B

Mettre à jour les FLAGS

Ne modifier aucun registre
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ TestCMP

⬜ cmp.rom
```

### Statut

```txt
🟨 PRIORITÉ ACTUELLE
```

---

## JMP

### Description

```asm
JMP Adresse
```

### Opcode proposé

```txt
41h
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Modification PC

⬜ TestJMP

⬜ jmp.rom
```

---

## JZ

### Description

```asm
JZ Adresse
```

### Opcode proposé

```txt
42h
```

### Fonction

```txt
Saut si FLAG_ZERO = 1
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Lecture FLAG_ZERO

⬜ TestJZ

⬜ jz.rom
```

---

## JNZ

### Description

```asm
JNZ Adresse
```

### Opcode proposé

```txt
43h
```

### Fonction

```txt
Saut si FLAG_ZERO = 0
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Lecture FLAG_ZERO

⬜ TestJNZ

⬜ jnz.rom
```

---

## Progression Lot D

```txt
⬜ CMP

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
```

---

# ROMs à créer

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

✅ TestADD

✅ TestSUB
```

---

# Tests automatisés à réaliser

```txt
⬜ TestCMP

⬜ TestJMP

⬜ TestJZ

⬜ TestJNZ
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

Progression : 80 %
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

✅ 11 nouvelles instructions validées

✅ 11 tests automatisés validés

✅ 11 ROMs validées

✅ Gestion mémoire

✅ Gestion pile

✅ Sous-routines

✅ Arithmétique complète de base
```

---

# Priorité immédiate

```txt
Lot D

1. CMP

2. TestCMP

3. cmp.rom

4. Validation ROM

5. JMP

6. TestJMP

7. jmp.rom

8. Validation ROM
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure‑8 devra être capable d'exécuter :

```asm
LOAD A, 1000h

LOAD B, 1001h

ADD A, B

CMP A, B

JZ Equal

JMP End

Equal:

STORE A, 2000h

End:

HLT
```

Cette version transformera Azure‑8 en un processeur programmable capable d'exécuter des calculs, des comparaisons et des branchements conditionnels.

---

**Fin de roadmap v0.0.3-alpha**