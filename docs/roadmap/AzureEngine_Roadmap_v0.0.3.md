# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **35 %**
>
> Priorité actuelle : **POP**

---

# Présentation

La version v0.0.3-alpha poursuit la transformation d'Azure-8 en un processeur réellement programmable.

Après la mise en place complète de l'infrastructure dans la v0.0.2, cette version se concentre sur l'ajout progressif des instructions du processeur.

Les premières instructions de manipulation de données sont désormais entièrement validées.

---

# Philosophie

Azure-8 continue d'être développé selon les principes du projet AzureEngine :

```txt
Assembler autant que possible

C avant C++

C++ simple et maîtrisé

Architecture claire

Compréhension du matériel

Développement progressif

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

FFh  HLT
```

---

## Infrastructure validée

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

Manipuler et transférer des données entre registres et mémoire.

---

## MOV

```asm
MOV A, B
```

### Validation

```txt
✅ Spécification

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

Memory[1000h] after execution = 42
```

### Statut

✅ TERMINÉ

---

## Résultat du Lot A

Premier cycle complet de données validé :

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

Exposer la pile au jeu d'instructions Azure-8.

Infrastructure déjà validée :

```txt
✅ Push8()

✅ Pop8()

✅ Push16()

✅ Pop16()

✅ SP

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
POP A
```

Opcode proposé :

```txt
21h
```

### Réalisation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ Test automatisé

⬜ pop.rom
```

### Statut

🟨 PRIORITÉ ACTUELLE

---

## CALL

```asm
CALL Adresse
```

### Réalisation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ Test automatisé

⬜ call.rom
```

---

## RET

```asm
RET
```

### Réalisation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ Test automatisé

⬜ ret.rom
```

---

## Statut du Lot B

🟨 EN COURS

---

# Lot C - Arithmétique

## INC

```asm
INC A
```

```txt
⬜ Implémentation

⬜ Gestion FLAGS

⬜ Test

⬜ inc.rom
```

---

## DEC

```asm
DEC A
```

```txt
⬜ Implémentation

⬜ Gestion FLAGS

⬜ Test

⬜ dec.rom
```

---

## ADD

```asm
ADD A, B
```

```txt
⬜ Implémentation

⬜ Gestion FLAGS

⬜ Test

⬜ add.rom
```

---

## SUB

```asm
SUB A, B
```

```txt
⬜ Implémentation

⬜ Gestion FLAGS

⬜ Test

⬜ sub.rom
```

---

## Statut

⬜ Non commencé

---

# Lot D - Comparaisons et branchements

## CMP

```asm
CMP A, B
```

```txt
⬜ Implémentation

⬜ FLAGS

⬜ Test

⬜ cmp.rom
```

---

## JMP

```asm
JMP Adresse
```

```txt
⬜ Implémentation

⬜ Test

⬜ jmp.rom
```

---

## JZ

```asm
JZ Adresse
```

```txt
⬜ Implémentation

⬜ Test

⬜ jz.rom
```

---

## JNZ

```asm
JNZ Adresse
```

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
⬜ pop.rom

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

## Validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH
```

---

## À réaliser

### Pile

```txt
⬜ TestPOP

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

## Instructions de données

```txt
✅ MOV

✅ LOAD

✅ STORE
```

---

## Pile

```txt
✅ PUSH

⬜ POP

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

Progression : 35 %
```

---

# Accomplissements v0.0.3

```txt
✅ MOV

✅ LOAD

✅ STORE

✅ PUSH

✅ 4 nouvelles ROMs validées

✅ 4 nouveaux tests automatisés validés

✅ Premier accès mémoire complet

✅ Première écriture mémoire complète

✅ Première utilisation de la pile via une instruction CPU
```

---

# Priorité immédiate

```txt
Lot B

1. POP

2. TestPOP

3. pop.rom

4. Validation POP

5. CALL

6. RET
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

puis :

```asm
CALL Routine

...

Routine:

PUSH A

POP A

RET
```

Cette version transformera Azure-8 en un processeur programmable capable d'exécuter de véritables programmes structurés.

---

**Fin de roadmap v0.0.3-alpha**