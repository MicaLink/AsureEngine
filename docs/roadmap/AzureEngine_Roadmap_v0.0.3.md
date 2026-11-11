# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **20 %**
>
> Priorité actuelle : **STORE**

---

# Présentation

La version v0.0.3-alpha marque la transformation d'Azure-8 en un processeur réellement programmable.

La v0.0.2 a permis de construire l'infrastructure fondamentale :

```txt
CPU
RAM
ROM Loader

Read8()
Write8()

Read16()
Write16()

Stack
Stack Pointer

FLAGS

Debug

Tests automatisés
```

La v0.0.3 ajoute progressivement les premières instructions de manipulation de données et de mémoire.

---

# Philosophie

Azure-8 continue d'être développé selon les principes du projet AzureEngine :

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

# Objectif principal

Permettre à Azure-8 de :

```txt
Déplacer des données

Lire la mémoire

Écrire la mémoire

Manipuler la pile

Effectuer des calculs

Effectuer des branchements
```

---

# État actuel du processeur

## Instructions disponibles

```txt
00h  NOP

10h  MOV

11h  LOAD

FFh  HLT
```

---

## Infrastructure disponible

```txt
✅ RAM 64 Ko

✅ Read8()
✅ Write8()

✅ Read16()
✅ Write16()

✅ Stack

✅ Stack Pointer

✅ FLAGS

✅ Debug

✅ ROM Loader

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

Permettre à Azure-8 de manipuler des données et d'interagir avec la mémoire.

---

## MOV

### Description

Copie une valeur d'un registre vers un autre.

```asm
MOV A, B
```

### Validation

- [x] Spécification
- [x] Opcode
- [x] Décodage
- [x] Exécution
- [x] Test automatisé
- [x] mov.rom validée

### Statut

✅ TERMINÉ

---

## LOAD

### Description

Charge une valeur mémoire dans un registre.

```asm
LOAD A, 1000h
```

### Encodage

```txt
11h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

### Validation

- [x] Opcode
- [x] Décodage
- [x] Exécution
- [x] Test automatisé
- [x] load.rom validée

### Statut

✅ TERMINÉ

---

## STORE

### Description

Écrit la valeur d'un registre dans la mémoire.

```asm
STORE A, 1000h
```

### Encodage

```txt
12h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] store.rom

### Statut

🟨 PRIORITÉ ACTUELLE

---

## Statut du Lot A

🟨 EN COURS

---

# Lot B - Pile avancée

## PUSH

```asm
PUSH A
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test
- [ ] push.rom

---

## POP

```asm
POP A
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test
- [ ] pop.rom

---

## CALL

```asm
CALL 1000h
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test
- [ ] call.rom

---

## RET

```asm
RET
```

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test
- [ ] ret.rom

---

## Statut

⬜ Non commencé

---

# Lot C - Arithmétique

## INC

```asm
INC A
```

- [ ] Implémentation
- [ ] Gestion FLAGS
- [ ] Test
- [ ] inc.rom

---

## DEC

```asm
DEC A
```

- [ ] Implémentation
- [ ] Gestion FLAGS
- [ ] Test
- [ ] dec.rom

---

## ADD

```asm
ADD A, B
```

- [ ] Implémentation
- [ ] Gestion FLAGS
- [ ] Test
- [ ] add.rom

---

## SUB

```asm
SUB A, B
```

- [ ] Implémentation
- [ ] Gestion FLAGS
- [ ] Test
- [ ] sub.rom

---

## Statut

⬜ Non commencé

---

# Lot D - Comparaisons et branchements

## CMP

```asm
CMP A, B
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Test
- [ ] cmp.rom

---

## JMP

```asm
JMP Adresse
```

- [ ] Implémentation
- [ ] Test
- [ ] jmp.rom

---

## JZ

```asm
JZ Adresse
```

- [ ] Implémentation
- [ ] Test
- [ ] jz.rom

---

## JNZ

```asm
JNZ Adresse
```

- [ ] Implémentation
- [ ] Test
- [ ] jnz.rom

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
```

---

## ROMs existantes à revalider plus tard

```txt
⬜ memory16.rom

⬜ stack8.rom

⬜ stack16.rom

⬜ overflow.rom

⬜ underflow.rom
```

Validation reportée jusqu'à l'implémentation complète des nouvelles instructions.

---

## ROMs à créer

### Données

```txt
⬜ store.rom
```

### Pile

```txt
⬜ push.rom
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

## Tests validés

```txt
✅ TestMOV

✅ TestLOAD
```

---

## À réaliser

### Données

```txt
⬜ TestSTORE
```

### Pile

```txt
⬜ TestPUSH
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

⬜ STORE
```

---

## Pile

```txt
⬜ PUSH
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

## ROMs

```txt
⬜ Toutes les ROMs validées
```

---

## Documentation

```txt
⬜ Documentation complète
```

---

## Compilation

```txt
⬜ Build Debug

⬜ Build Release

⬜ 0 erreur

⬜ 0 warning
```

---

## Tests

```txt
⬜ Couverture complète
des tests automatisés
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

Progression : 20 %

NOP         ✅
MOV         ✅
LOAD        ✅

STORE       ⬜
```

---

# Priorité immédiate

```txt
1. STORE

2. TestSTORE

3. store.rom

4. Validation STORE

5. PUSH

6. POP
```

---

# Objectif de la v0.0.3

À la fin de cette version, Azure-8 devra être capable d'exécuter :

```asm
LOAD  A, 1000h

ADD   A, B

STORE A, 2000h

HLT
```

Cette version transformera Azure-8 d'une infrastructure validée en un processeur programmable capable d'exécuter de véritables programmes.

---

**Fin de roadmap v0.0.3-alpha**