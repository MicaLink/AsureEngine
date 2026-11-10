# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **Validation finale**
>
> Version précédente : **v0.0.1-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **99.5 %**
>
> Priorité actuelle : **Finalisation du Lot H - Qualité**

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
- la documentation technique complète.

L'objectif principal de cette version est de stabiliser définitivement Azure-8 avant le démarrage du développement des premières instructions de manipulation de données prévues pour la v0.0.3.

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

- [x] Validation complète

- [x] Overflow
- [x] Underflow

- [x] Tests de charge

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

## Objectif

Préparer la release officielle v0.0.2-alpha.

---

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

## Tests automatisés

### Objectif

Mettre en place les premiers tests automatisés du projet.

### Prévus

- [ ] TestMemory
- [ ] TestRead16
- [ ] TestWrite16
- [ ] TestStack
- [ ] TestFlags
- [ ] TestReset

### Statut

⬜ NON COMMENCÉ

---

## Statut

🟨 EN COURS

---

# Ordre de développement

## Étape actuelle

```txt
Premiers tests automatisés
```

---

## Puis

```txt
Release

v0.0.2-alpha
```

---

## Ensuite

```txt
AzureEngine v0.0.3
```

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

- [ ] Premiers tests automatisés

## Release

- [ ] Tag Git v0.0.2-alpha

---

# Objectif de la v0.0.3

Premières instructions de manipulation de données :

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

# État actuel

```txt
Projet      : AzureEngine

Version     : v0.0.2-alpha

CPU         : 8 bits
PC          : 16 bits
SP          : 16 bits
FLAGS       : 8 bits

RAM         : 64 Ko

Progression : ~99.5 %

Lot A       : ✅ Terminé
Lot B       : ✅ Terminé
Lot C       : ✅ Terminé
Lot D       : ✅ Terminé
Lot E       : ✅ Terminé
Lot F       : ✅ Terminé
Lot G       : ✅ Terminé

Lot H       : 🟨 En cours

Priorité :

Premiers tests automatisés
↓
Tag Git v0.0.2-alpha
```

---

# Résumé

Azure-8 v0.0.2 est désormais fonctionnellement complet.

Les fondations de l'architecture sont validées :

```txt
✓ Mémoire 16 bits
✓ Stack
✓ Stack Pointer
✓ FLAGS
✓ Debug avancé

✓ ROMs fondamentales validées

✓ Documentation complète

✓ Build Debug
✓ Build Release

✓ 0 erreur
✓ 0 warning
```

Le dernier élément bloquant avant la publication officielle est la mise en place des premiers tests automatisés prévus dans le Lot H.

Une fois ces tests ajoutés et validés, le projet pourra être publié sous le tag :

```txt
v0.0.2-alpha
```

avant le démarrage du développement de :

```txt
AzureEngine v0.0.3
```