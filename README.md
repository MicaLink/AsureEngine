# AzureEngine

AzureEngine est un projet open source visant à créer un écosystème complet de développement rétro.

Le projet s'articule autour de plusieurs composants :

- Azure-8 (première machine virtuelle)
- AzureASM (assembleur dédié)
- Azure Studio (IDE dédié)
- futurs SDK et outils de développement

L'objectif à long terme est de permettre le développement de jeux pour des machines virtuelles et, éventuellement, du matériel réel compatible.

---

# État actuel

Version :

```txt
v0.0.1-alpha
```

Statut :

```txt
Développement actif
```

Plateforme :

```txt
Windows
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

La première étape est de créer Azure-8, une machine virtuelle 8 bits simple et documentée permettant d'exécuter ses premières ROM.

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
```

Instructions actuellement supportées :

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

Résultat :

```txt
ROM Loaded

PC=0000 OPCODE=00
PC=0001 OPCODE=00
PC=0002 OPCODE=00
PC=0003 OPCODE=FF

CPU HALTED

Execution Completed
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
│   └── main.cpp
│
└── tests
```

---

# Compilation

Consulter :

```txt
docs/development/Build.md
```

---

# Documentation

Documentation technique :

```txt
docs/specifications/
```

Documentation développeur :

```txt
docs/development/
```

Roadmap :

```txt
docs/roadmap/
```

---

# Roadmap actuelle

Version en cours :

```txt
v0.0.1
```

Objectif :

```txt
Valider le cœur du processeur Azure-8.
```

Fonctionnalités validées :

```txt
✓ CPU

✓ RAM

✓ ROM Loader

✓ Fetch

✓ Decode

✓ Execute

✓ NOP

✓ HLT

✓ Debug Console
```

Prochaine version :

```txt
v0.0.2
```

Objectifs :

```txt
Read16()

Write16()

Stack

Push8()

Pop8()

Push16()

Pop16()
```

---

# Contribution

Avant toute contribution, merci de lire :

```txt
docs/development/Contributing.md
```

Ainsi que :

```txt
docs/development/CodingStyle.md
```

---

# Licence

Licence à définir.

---

# Auteur

Thomas Galliot

---

# Philosophie

AzureEngine privilégie :

```txt
Code simple
Documentation complète
Architecture claire
Évolution progressive
```

Le projet avance par petits jalons validés plutôt que par de grosses fonctionnalités inachevées.

```
Version actuelle : v0.0.1-alpha
```