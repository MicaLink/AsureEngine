# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **30 %**
>
> Priorité actuelle : **Lot B - Pile avancée**

---

# Présentation

La version v0.0.3-alpha marque la transition d'Azure-8 vers une architecture réellement programmable.

La version v0.0.2 a permis de construire l'ensemble des fondations techniques :

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

La version v0.0.3 étend désormais le processeur avec ses premières instructions de manipulation de données, première étape avant l'arrivée des opérations de pile, de calcul et de branchement.

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

12h  STORE

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

Permettre les premiers échanges de données entre registres et mémoire.

---

## MOV

### Description

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

### Description

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

### Description

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

## Bilan du Lot A

Premier cycle complet de données validé :

```asm
LOAD  A, 1000h

MOV   B, A

STORE B, 1001h

HLT
```

Résultat :

```txt
Lecture mémoire

↓

Manipulation registre

↓

Écriture mémoire
```

### Statut

✅ TERMINÉ

---

# Lot B - Pile avancée

## Objectif

Exposer la pile au jeu d'instructions Azure-8.

L'infrastructure est déjà disponible :

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

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] push.rom

---

## POP

```asm
POP A
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] pop.rom

---

## CALL

```asm
CALL 1000h
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] call.rom

---

## RET

```asm
RET
```

### Réalisation

- [ ] Opcode
- [ ] Décodage
- [ ] Exécution
- [ ] Test automatisé
- [ ] ret.rom

---

## Statut

🟨 PRIORITÉ ACTUELLE

---

# Lot C - Arithmétique

## INC

```asm
INC A
```

- [ ] Implémentation
- [ ] FLAGS
- [ ] Test
- [ ] inc.rom

---

## DEC

```asm
DEC A
```

- [ ] Implémentation
- [ ] FLAGS
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

✅ store.rom
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

Ces ROMs seront revalidées une fois le jeu d'instructions de pile terminé.

---

## ROMs à créer

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

✅ TestSTORE
```

---

## Tests à réaliser

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

✅ STORE
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

Progression : 30 %
```

---

# Accomplissements v0.0.3

```txt
✅ MOV

✅ LOAD

✅ STORE

✅ 3 nouvelles ROMs validées

✅ 3 nouveaux tests automatisés validés

✅ Premier cycle complet
   mémoire → registres → mémoire
```

---

# Priorité immédiate

```txt
Lot B

1. PUSH

2. TestPUSH

3. push.rom

4. Validation PUSH

5. POP

6. TestPOP

7. pop.rom

8. Validation POP
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

Cette version transformera Azure-8 en une architecture programmable capable d'exécuter de véritables programmes.

---

**Fin de roadmap v0.0.3-alpha**