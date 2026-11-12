# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **40 %**
>
> Priorité actuelle : **CALL**

---

# Présentation

La version v0.0.3-alpha poursuit la transformation d'Azure-8 en un processeur programmable.

Après la finalisation de l'infrastructure dans la v0.0.2, cette version introduit progressivement les premières instructions capables de manipuler des données, lire et écrire en mémoire, puis utiliser la pile.

Les instructions fondamentales de transfert de données sont désormais totalement opérationnelles et validées.

---

# Philosophie

Azure-8 continue d'être développé selon les principes fondateurs du projet AzureEngine :

```txt
Assembler autant que possible

C avant C++

C++ simple et maîtrisé

Architecture claire

Développement progressif

Compréhension complète
du matériel émulé

Documentation systématique
```

---

# État actuel du processeur

## Instructions disponibles

```txt
00h  NOP

10h  MOV
11h  LOAD
12h  STORE

20h  PUSH
21h  POP

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

## Objectif

Mettre en place les premiers échanges de données entre registres et mémoire.

---

## MOV

```asm
MOV A, B
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ Test automatisé

✅ mov.rom validée
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

✅ Test automatisé

✅ load.rom validée
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

✅ Test automatisé

✅ store.rom validée
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

## Résultat du Lot A

Premier cycle complet mémoire → registre → mémoire validé :

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

Donner au jeu d'instructions l'accès à la pile Azure-8.

Infrastructure déjà disponible :

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

✅ Test automatisé

✅ push.rom validée
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

✅ Test automatisé

✅ pop.rom validée
```

### Validation ROM

```txt
SP before execution = FFFE

Memory[FFFF] = 42

↓

POP B

↓

Register B = 42

SP = FFFF
```

### Statut

✅ TERMINÉ

---

## CALL

```asm
CALL Adresse
```

Opcode prévu :

```txt
22h
```

### Objectif

```txt
Empiler l'adresse de retour

Modifier PC

Transférer l'exécution
vers une sous-routine
```

### Réalisation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ Test automatisé

⬜ call.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

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

⬜ Test automatisé

⬜ ret.rom
```

### Statut

⬜ Non commencé

---

## État du Lot B

```txt
✅ PUSH

✅ POP

⬜ CALL

⬜ RET
```

### Statut

🟨 EN COURS

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
⬜ call.rom

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

## Statut

🟨 EN COURS

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

## Statut

⬜ Non commencé

---

# Lot G - Tests automatisés

## Tests validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH

✅ TestPOP
```

---

## Tests à réaliser

### Pile

```txt
⬜ TestCALL

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

## Statut

🟨 EN COURS

---

# Critères de validation

## Transfert de données

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

⬜ CALL

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

Progression : 40 %
```

---

# Accomplissements v0.0.3

```txt
✅ MOV

✅ LOAD

✅ STORE

✅ PUSH

✅ POP

✅ 5 nouvelles instructions validées

✅ 5 nouveaux tests automatisés validés

✅ 5 ROMs de validation validées

✅ Transfert mémoire ↔ registres

✅ Première utilisation complète de la pile
```

---

# Priorité immédiate

```txt
Lot B

1. CALL

2. TestCALL

3. call.rom

4. Validation CALL

5. RET

6. TestRET

7. ret.rom

8. Validation RET
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter :

```asm
CALL Routine

HLT

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

Cette version transformera Azure-8 en un processeur programmable capable d'exécuter des programmes structurés comportant mémoire, pile et sous-routines.

---

**Fin de roadmap v0.0.3-alpha**