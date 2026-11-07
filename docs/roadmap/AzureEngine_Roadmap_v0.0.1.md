# AzureEngine Roadmap v0.0.1

> Version : **v0.0.1-alpha**
>
> Statut : **Publié**
>
> Tag Git : **v0.0.1-alpha**

---

# Présentation

La version v0.0.1-alpha représente le premier jalon public du projet AzureEngine.

Elle valide la création du premier prototype fonctionnel de Azure-8 et établit les bases techniques nécessaires à l'évolution du projet.

Cette version marque officiellement la naissance de Azure-8.

---

# Objectif de la version

L'objectif était de démontrer qu'Azure-8 est capable de :

- Charger une ROM binaire ;
- Lire des instructions ;
- Décoder des instructions ;
- Exécuter des instructions ;
- Arrêter correctement le processeur.

---

# Fonctionnalités validées

## Infrastructure

- [x] Dépôt Git
- [x] Structure du projet
- [x] Configuration Visual Studio Code
- [x] Configuration MSVC
- [x] Configuration Debug

### Statut

✅ Terminé

---

## Documentation

- [x] README.md
- [x] Technical Specification
- [x] Build.md
- [x] CodingStyle.md
- [x] Contributing.md

### Statut

✅ Terminé

---

## CPU

### Registres

- [x] A
- [x] B
- [x] C
- [x] D
- [x] PC
- [x] SP
- [x] FLAGS

### Fonctions

- [x] Reset()
- [x] Step()
- [x] Run()

### Statut

✅ Terminé

---

## Mémoire

- [x] RAM 64 Ko
- [x] Read8()
- [x] Write8()

### Statut

✅ Terminé

---

## Cycle CPU

- [x] Fetch
- [x] Decode
- [x] Execute

### Statut

✅ Terminé

---

## Jeu d'instructions

| Opcode | Instruction |
|----------|----------|
| 0x00 | NOP |
| 0xFF | HLT |

### Statut

✅ Terminé

---

## ROM

- [x] Chargement ROM
- [x] Lecture binaire
- [x] Chargement mémoire
- [x] Validation Hex Editor

### Statut

✅ Terminé

---

## Debug

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Gestion opcode inconnu
- [x] CPU HALTED

### Statut

✅ Terminé

---

# Validation officielle

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

PC=0000 OPCODE=00
PC=0001 OPCODE=00
PC=0002 OPCODE=00
PC=0003 OPCODE=FF

CPU HALTED

Execution Completed
```

✅ Validation réussie

---

# État final de la release

La version v0.0.1-alpha a été publiée avec succès.

Validation obtenue :

- [x] Compilation fonctionnelle
- [x] Chargement ROM
- [x] Exécution NOP
- [x] Exécution HLT
- [x] Débogage CPU
- [x] Documentation initiale
- [x] Premier tag Git

---

# Jalon historique

La version v0.0.1-alpha représente :

- La naissance officielle de Azure-8
- La première ROM exécutable
- Le premier CPU fonctionnel
- Le premier système de chargement de ROM
- Le premier tag Git officiel
- Le premier jalon public d'AzureEngine

---

# Statut

```txt
Version : v0.0.1-alpha

État : Publié

Développement : Clôturé
```