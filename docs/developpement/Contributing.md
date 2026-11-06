# Contributing.md

# Contribuer à AzureEngine

Merci de votre intérêt pour AzureEngine.

AzureEngine est un projet open source dont l'objectif est de construire progressivement :

- Azure-8
- AzureASM
- Azure Studio
- de futurs systèmes compatibles

Le projet est actuellement en phase de développement précoce.

---

# Philosophie du projet

AzureEngine privilégie :

- la simplicité ;
- la lisibilité ;
- la documentation ;
- la stabilité.

Nous préférons :

```txt
Du code simple qui fonctionne
```

à :

```txt
Du code complexe difficile à maintenir
```

---

# Avant de contribuer

Merci de lire :

```txt
docs/
├── roadmap/
│   └── AzureEngine_Roadmap_v0.0.1.txt
│
├── specifications/
│   └── Azure-8_Technical_Specification.txt
│
└── development/
    ├── Build.md
    ├── CodingStyle.md
    └── Architecture.md
```

---

# Types de contributions acceptées

Les contributions suivantes sont les bienvenues :

## Documentation

Exemples :

```txt
Corrections
Explications
Diagrammes
Tutoriels
Guides utilisateur
```

---

## Corrections de bugs

Exemples :

```txt
CPU
Memory
ROM Loader
AzureASM
```

---

## Tests

Exemples :

```txt
Tests unitaires
Tests mémoire
Tests CPU
```

---

## Optimisations

Les optimisations sont acceptées uniquement si :

```txt
Le code reste lisible
```

et

```txt
Le comportement reste identique
```

---

# Contributions non acceptées

Durant les premières versions, les contributions suivantes seront généralement refusées :

## Fonctionnalités hors roadmap

Exemple :

```txt
Audio
Réseau
Marketplace
IA
Cloud
```

si elles ne sont pas prévues dans la version en cours.

---

## Réécritures complètes

Exemple :

```txt
Réécrire tout le CPU
Réécrire tout le système mémoire
```

sans discussion préalable.

---

## Dépendances externes

La version v0.0.1 n'accepte aucune dépendance externe.

Non autorisé :

```txt
Boost
Qt
SDL
SFML
OpenGL
DirectX
```

---

# Workflow recommandé

## Étape 1

Créer une branche :

```bash
git checkout -b feature/my-feature
```

---

## Étape 2

Effectuer les modifications.

---

## Étape 3

Compiler le projet.

Aucune erreur ne doit être présente.

---

## Étape 4

Tester les changements.

---

## Étape 5

Créer une Pull Request.

---

# Convention des commits

Format recommandé :

```txt
[CPU] Add FetchByte()

[Memory] Add Read16()

[ROM] Add ROM Loader

[Docs] Update Build Guide

[Test] Add CPU tests
```

---

# Pull Requests

Une Pull Request doit :

- avoir un objectif clair ;
- être limitée à un sujet ;
- compiler sans erreur ;
- respecter CodingStyle.md ;
- être documentée.

---

# Rapporter un bug

Lors d'un rapport de bug, merci d'indiquer :

## Version

Exemple :

```txt
AzureEngine v0.0.1
```

---

## Plateforme

Exemple :

```txt
Windows 11
```

---

## Description

Expliquer :

```txt
Ce qui était attendu
Ce qui s'est produit
```

---

## Reproduction

Fournir :

```txt
Étape 1
Étape 2
Étape 3
```

---

# Proposer une fonctionnalité

Avant toute proposition :

1. Vérifier la roadmap.
2. Vérifier les issues existantes.
3. Expliquer le besoin.
4. Proposer une implémentation.

---

# Documentation

Toute nouvelle fonctionnalité doit être accompagnée de :

- commentaires dans le code ;
- mise à jour de la documentation si nécessaire.

---

# Structure du projet

Chaque module doit avoir une responsabilité unique.

Exemple :

```txt
CPU
    Fetch
    Decode
    Execute

Memory
    Read
    Write

Emulator
    LoadROM
    Run
```

---

# Qualité minimale

Une contribution est considérée acceptable lorsqu'elle :

- compile ;
- respecte CodingStyle.md ;
- ne casse pas les fonctionnalités existantes ;
- est documentée ;
- reste compréhensible.

---

# Licence

En contribuant au projet, vous acceptez que votre code soit distribué sous la licence utilisée par AzureEngine.

---

# Remerciements

Merci à toutes les personnes participant au développement d'AzureEngine.

Chaque contribution, même petite, aide à construire l'écosystème :

```txt
AzureEngine
├── Azure-8
├── AzureASM
├── Azure Studio
└── Versions futures
```

Merci pour votre participation.