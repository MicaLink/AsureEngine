# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **Terminé**
>
> Version précédente : **v0.0.1-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **100 %**

---

# Présentation

La version v0.0.2-alpha finalise les fondations techniques de l'architecture Azure-8.

Cette version introduit :

- l'adressage mémoire 16 bits ;
- le système de pile ;
- le registre Stack Pointer ;
- le registre FLAGS ;
- les outils avancés de débogage ;
- les ROMs de validation ;
- la documentation technique complète ;
- les premiers tests automatisés.

Cette version constitue la première base stable du processeur Azure-8 avant l'introduction des futures instructions de manipulation de données prévues dans la v0.0.3.

---

# Architecture officielle Azure-8

## Registres utilisateur

```txt
A       8 bits
B       8 bits
C       8 bits
D       8 bits

FLAGS   8 bits
```

## Registres système

```txt
PC      16 bits
SP      16 bits
```

## Mémoire

```txt
RAM 64 Ko

0000h → FFFFh
```

---

# État global d'avancement

## CPU

- [x] Fetch
- [x] Decode
- [x] Execute

## Mémoire

- [x] Read8()
- [x] Write8()

- [x] Read16()
- [x] Write16()

- [x] Validation Little Endian

## Stack

- [x] Push8()
- [x] Pop8()

- [x] Push16()
- [x] Pop16()

## Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM

- [x] Overflow
- [x] Underflow

- [x] Validation complète

## FLAGS

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()

- [x] IsFlagSet()
- [x] GetFlags()

- [x] UpdateZeroFlag()
- [x] UpdateCarryFlag()

- [x] UpdateNegativeFlag()
- [x] UpdateOverflowFlag()

## Debug

- [x] Affichage PC
- [x] Affichage SP
- [x] Affichage FLAGS
- [x] Affichage OPCODE

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

---

# Lot A - Mémoire

## Résultat

- [x] Read8()
- [x] Write8()

- [x] Read16()
- [x] Write16()

- [x] Validation Little Endian

## Statut

✅ TERMINÉ

---

# Lot B - Stack

## Résultat

- [x] Push8()
- [x] Pop8()

- [x] Push16()
- [x] Pop16()

## Statut

✅ TERMINÉ

---

# Lot C - Stack Pointer

## Résultat

- [x] Gestion du registre SP
- [x] Validation des limites mémoire
- [x] Stack Overflow
- [x] Stack Underflow
- [x] Tests de charge

## Statut

✅ TERMINÉ

---

# Lot D - FLAGS

## Résultat

- [x] FLAG_ZERO
- [x] FLAG_CARRY
- [x] FLAG_NEGATIVE
- [x] FLAG_OVERFLOW

- [x] SetFlag()
- [x] ClearFlag()

- [x] IsFlagSet()
- [x] GetFlags()

- [x] UpdateZeroFlag()
- [x] UpdateCarryFlag()

- [x] UpdateNegativeFlag()
- [x] UpdateOverflowFlag()

## Statut

✅ TERMINÉ

---

# Lot E - Debug

## Résultat

### Affichage CPU

- [x] PC
- [x] SP
- [x] FLAGS
- [x] OPCODE

### Outils

- [x] DumpStack()
- [x] DumpRegister()
- [x] DumpMemory()

## Statut

✅ TERMINÉ

---

# Lot F - ROMs de validation

## ROMs fondamentales

### nop.rom

- [x] Créée
- [x] Testée
- [x] Validée

### halt.rom

- [x] Créée
- [x] Testée
- [x] Validée

### invalid.rom

- [x] Créée
- [x] Testée
- [x] Validée

---

## ROMs avancées

### memory16.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### stack8.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### stack16.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### overflow.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

### underflow.rom

- [x] Créée
- [ ] Validation reportée à la v0.0.3

## Statut

✅ TERMINÉ POUR LA V0.0.2

---

# Lot G - Documentation

## Documentation générale

- [x] README.md
- [x] LICENSE
- [x] Architecture.md

## Documentation technique

- [x] Documentation Stack.md
- [x] Documentation SP.md
- [x] Documentation FLAGS.md

## Spécifications

- [x] Azure-8_Technical_Specification_v0.0.1.txt
- [x] Azure-8_Technical_Specification_v0.0.2.txt

## Roadmaps

- [x] AzureEngine_Roadmap_v0.0.1.md
- [x] AzureEngine_Roadmap_v0.0.2.md

## Statut

✅ TERMINÉ

---

# Lot H - Qualité

## Nettoyage du code

- [x] FFAGS → FLAGS
- [x] hight → high

- [x] Relecture générale du code

---

## Compilation

- [x] Build Debug
- [x] Build Release

- [x] Vérification warnings MSVC (Debug)
- [x] Vérification warnings MSVC (Release)

### Résultat Debug

```txt
0 erreur
0 warning
```

### Résultat Release

```txt
0 erreur
0 warning
```

---

## Validation du dépôt

- [x] Vérification de l'arborescence
- [x] Vérification de la documentation
- [x] Vérification des ROMs
- [x] Vérification du .gitignore

---

## Premiers tests automatisés

### Tests mémoire

- [x] TestReadWrite8()
- [x] TestReadWrite16()

### Tests pile

- [x] TestPushPop8()
- [x] TestPushPop16()

### Tests FLAGS

- [x] TestZeroFlag()
- [x] TestCarryFlag()
- [x] TestNegativeFlag()
- [x] TestOverflowFlag()

### Tests CPU

- [x] TestReset()

### Résultat

```txt
AzureEngine Tests

All tests passed successfully.
```

---

## Statut

✅ TERMINÉ

---

# Critères de validation de la v0.0.2

## Architecture

- [x] Mémoire validée
- [x] Stack validée
- [x] Stack Pointer validé
- [x] FLAGS validés

## Debug

- [x] Debug validé

## ROMs

- [x] nop.rom validée
- [x] halt.rom validée
- [x] invalid.rom validée

## Documentation

- [x] Documentation complète

## Qualité

- [x] Build Debug validé
- [x] Build Release validé

- [x] Validation warnings MSVC (Debug)
- [x] Validation warnings MSVC (Release)

## Tests

- [x] Premiers tests automatisés

---

# Résultat final

```txt
Lot A ✅
Lot B ✅
Lot C ✅
Lot D ✅
Lot E ✅
Lot F ✅
Lot G ✅
Lot H ✅
```

---

# État final de la version

```txt
Projet      : AzureEngine

Version     : v0.0.2-alpha

CPU         : 8 bits
PC          : 16 bits
SP          : 16 bits
FLAGS       : 8 bits

RAM         : 64 Ko

Progression : 100 %

Build Debug   ✅
Build Release ✅

0 erreur      ✅
0 warning     ✅

Tests auto    ✅
Documentation ✅
ROMs          ✅
```

---

# Clôture de la v0.0.2

La version **v0.0.2-alpha** est considérée comme terminée.

Commande de publication recommandée :

```bash
git add .
git commit -m "Release v0.0.2-alpha"

git tag v0.0.2-alpha

git push
git push --tags
```

---

# Prochaine étape

Version suivante :

```txt
AzureEngine v0.0.3
```

Objectifs principaux :

```asm
MOV
LOAD
STORE
```

Puis :

```asm
PUSH
POP

CALL
RET
```

Puis :

```asm
INC
DEC

ADD
SUB

CMP
JZ
JNZ
```

---

**Fin de roadmap v0.0.2-alpha**