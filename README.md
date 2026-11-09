# AzureEngine

AzureEngine est un projet open source visant à construire un écosystème complet de développement rétro.

Le projet s'articule actuellement autour d'**Azure-8**, une architecture virtuelle 8 bits développée comme fondation technique des futurs composants de l'écosystème AzureEngine.

---

# État actuel

Version :

```txt
v0.0.2-alpha
```

Statut :

```txt
Développement actif
```

Plateformes supportées :

```txt
Windows
```

Plateformes prévues :

```txt
Linux
macOS
```

---

# Vision du projet

AzureEngine n'est pas simplement un moteur de jeu.

L'objectif est de construire progressivement :

```txt
AzureEngine
│
├── Azure-8
│
├── AzureASM
│
├── Azure Studio
│
├── Marketplace
│
├── Azure-16
│
└── Matériel réel (long terme)
```

L'objectif final est de proposer un environnement complet permettant :

- le développement de jeux rétro ;
- la création d'émulateurs ;
- la conception de SDK ;
- la distribution d'outils et d'extensions ;
- le support de matériel réel compatible.

---

# Azure-8

Azure-8 est la première plateforme officielle du projet.

Caractéristiques actuelles :

```txt
CPU 8 bits

RAM 64 Ko

ROM binaire

Fetch
Decode
Execute

Pile (Stack)

Stack Pointer

FLAGS

Debug avancé
```

---

# Architecture actuelle

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
64 Ko

0000h → FFFFh
```

---

# Fonctionnalités validées

## Mémoire

```txt
✓ Read8()
✓ Write8()

✓ Read16()
✓ Write16()
```

## Stack

```txt
✓ Push8()
✓ Pop8()

✓ Push16()
✓ Pop16()
```

## FLAGS

```txt
✓ Zero Flag
✓ Carry Flag
✓ Negative Flag
✓ Overflow Flag
```

## Debug

```txt
✓ DumpStack()

✓ DumpRegister()

✓ DumpMemory()

✓ Affichage PC
✓ Affichage SP
✓ Affichage FLAGS
✓ Affichage OPCODE
```

---

# Jeu d'instructions actuel

| Opcode | Instruction |
|----------|----------|
| 00h | NOP |
| FFh | HLT |

---

# Exemple

ROM :

```hex
00 00 00 FF
```

Programme :

```asm
NOP
NOP
NOP
HLT
```

Résultat :

```txt
ROM Loaded

PC=0000 SP=FFFF FLAGS=00 OPCODE=00
PC=0001 SP=FFFF FLAGS=00 OPCODE=00
PC=0002 SP=FFFF FLAGS=00 OPCODE=00
PC=0003 SP=FFFF FLAGS=00 OPCODE=FF

CPU HALTED

Execution Completed
```

---

# ROMs de validation

ROMs disponibles :

```txt
nop.rom
halt.rom
invalid.rom

memory16.rom

stack8.rom
stack16.rom

overflow.rom
underflow.rom
```

ROMs actuellement validées :

```txt
✓ nop.rom
✓ halt.rom
✓ invalid.rom
```

---

# Structure actuelle

```txt
AzureEngine
│
├── docs
│
├── roms
│
├── src
│   │
│   ├── Azure8
│   │   ├── CPU
│   │   ├── Memory
│   │   └── Emulator
│   │
│   ├── Core
│   │
│   └── main.cpp
│
└── build
```

---

# Documentation

## Documentation développeur

```txt
docs/developpement/
```

Contenu :

```txt
Architecture.md

Build.md

CodingStyle.md

Contributing.md

Documentation Stack.md

Documentation Stack Pointer.md

Documentation FLAGS.md
```

---

## Spécifications techniques

```txt
docs/Specifications/
```

Contenu :

```txt
Azure-8_Technical_Specification_v0.0.1.txt

Azure-8_Technical_Specification_v0.0.2.txt
```

---

## Roadmap

```txt
docs/roadmap/
```

Contenu :

```txt
AzureEngine_Roadmap_v0.0.1.md

AzureEngine_Roadmap_v0.0.2.md
```

---

# Roadmap actuelle

Version en cours :

```txt
v0.0.2-alpha
```

Objectif :

```txt
Finaliser les fondations techniques d'Azure-8.
```

Fonctionnalités réalisées :

```txt
✓ Mémoire 16 bits

✓ Stack

✓ Stack Pointer

✓ FLAGS

✓ Debug avancé

✓ ROMs de validation
```

Version suivante :

```txt
v0.0.3
```

Objectifs :

```txt
MOV
LOAD
STORE
```

Puis :

```txt
PUSH
POP

CALL
RET
```

Puis :

```txt
INC
DEC

ADD
SUB

CMP

JZ
JNZ
```

---

# Contribution

Avant toute contribution, merci de consulter :

```txt
docs/developpement/Contributing.md
```

et :

```txt
docs/developpement/CodingStyle.md
```

---

# Licence

AzureEngine est distribué sous licence MIT.

Consulter le fichier :

```txt
LICENSE
```

pour le texte complet de la licence.

---

# Auteur

```txt
Thomas Galliot
```

---

# Philosophie

AzureEngine privilégie :

```txt
Code simple

Documentation complète

Architecture claire

Évolution progressive

Maîtrise du bas niveau
```

Le projet évolue par petits jalons validés.

Chaque fonctionnalité doit être :

```txt
Conçue
Documentée
Testée
Validée
```

avant l'ajout de nouvelles capacités.

---

# État actuel

```txt
Version : v0.0.2-alpha

Architecture :

CPU 8 bits
RAM 64 Ko

Read16()
Write16()

Push8()
Pop8()

Push16()
Pop16()

FLAGS

Debug

Prochaine étape :

Documentation finale
Préparation release v0.0.2-alpha
```