# AzureEngine Roadmap v0.0.1

> Version : **v0.0.1-alpha**  
> Statut : **Publié**  
> Tag Git : **v0.0.1-alpha**  
> Plateforme : **Windows**  
> Dernière mise à jour : Après publication du premier jalon officiel

---

# Présentation

AzureEngine est un projet open source visant à construire progressivement un écosystème complet de développement rétro.

Le projet est articulé autour de plusieurs composants :

- Azure-8 (première machine virtuelle)
- AzureASM (assembleur dédié)
- Azure Studio (IDE dédié)
- Marketplace et système de modules
- Futures plateformes Azure-16 et suivantes
- Matériel réel compatible (objectif long terme)

La version **v0.0.1-alpha** représente le premier jalon public du projet.

---

# Objectif de la version

L'objectif de la version **v0.0.1-alpha** était de valider le noyau minimal de **Azure-8**.

Cette version permet :

- Le chargement d'une ROM binaire
- L'exécution d'instructions simples
- Le débogage du processeur
- La validation de l'architecture du projet
- La mise en place de la documentation fondatrice

Aucune fonctionnalité graphique n'est prévue dans cette version.

---

# État du projet

## Progression

**100 %**

✅ Version publiée

✅ Premier tag Git créé

✅ Premier prototype Azure-8 validé

✅ Documentation initiale disponible

---

# Lot A - Infrastructure

## Objectif

Mettre en place l'environnement de développement du projet.

### Tâches

- [x] Création du dépôt Git
- [x] Réorganisation du projet
- [x] Structure Azure8
- [x] Configuration VS Code
- [x] Configuration compilation MSVC
- [x] Configuration Debug
- [x] Premier tag Git officiel

### Statut

✅ Terminé

---

# Lot B - Documentation

## Objectif

Créer la documentation de référence du projet.

### Tâches

- [x] Azure-8 Technical Specification v0.0.1
- [x] Roadmap v0.0.1
- [x] Build.md
- [x] CodingStyle.md
- [x] Contributing.md
- [x] README.md

### Statut

✅ Terminé

---

# Lot C - CPU

## Objectif

Créer le premier processeur fonctionnel Azure-8.

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

# Lot D - Mémoire

## Objectif

Créer le système mémoire de base.

### Tâches

- [x] RAM 64 Ko
- [x] Read8()
- [x] Write8()

### Statut

✅ Terminé

---

# Lot E - Fetch / Decode / Execute

## Objectif

Permettre l'exécution d'instructions.

### Tâches

- [x] Lecture opcode
- [x] Décodage opcode
- [x] Exécution opcode
- [x] Gestion opcode inconnu

### Statut

✅ Terminé

---

# Lot F - Jeu d'instructions

## Objectif

Créer le premier ensemble d'instructions Azure-8.

### Instructions supportées

| Opcode | Instruction | État |
|----------|----------|----------|
| `00h` | NOP | ✅ |
| `FFh` | HLT | ✅ |

### Statut

✅ Terminé

---

# Lot G - ROM

## Objectif

Permettre le chargement de programmes binaires.

### Tâches

- [x] Chargement ROM
- [x] Lecture binaire
- [x] Chargement mémoire
- [x] ROM de test fonctionnelle
- [x] Validation avec Hex Editor
- [x] Exécution depuis ROM

### Statut

✅ Terminé

---

# Lot H - Debug

## Objectif

Afficher les informations nécessaires au débogage.

### Tâches

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage erreurs
- [x] Message CPU HALTED
- [x] Message Execution Completed

### Statut

✅ Terminé

---

# Tests validés

## ROM de test

### Contenu

```hex
00 00 00 FF
```

### Programme

```asm
NOP
NOP
NOP
HLT
```

### Résultat obtenu

```txt
ROM Loaded

PC=0000 OPCODE=00
PC=0001 OPCODE=00
PC=0002 OPCODE=00
PC=0003 OPCODE=FF

CPU HALTED

Execution Completed
```

### Validation

✅ Réussie

---

# Contenu de la release v0.0.1-alpha

La release contient :

- Azure-8 CPU
- RAM 64 Ko
- ROM Loader
- Console de débogage
- Documentation initiale
- ROM de test
- Configuration VS Code
- Premier tag Git officiel

---

# Travaux restants après release

## Documentation

- [ ] LICENSE
- [ ] Architecture.md

## ROM de validation

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

## Qualité

- [ ] Vérifier les warnings MSVC
- [ ] Nettoyage final du dépôt
- [ ] Création des premiers tests automatisés

---

# Hors périmètre de la v0.0.1

Les éléments suivants sont reportés aux versions futures :

- GPU
- Audio
- BIOS
- Stack
- Read16()
- Write16()
- AzureASM
- Azure Studio
- Marketplace
- Azure-16
- Jeux
- Matériel réel

---

# Objectifs de la v0.0.2

## Mémoire avancée

- [ ] Read16()
- [ ] Write16()

## Stack

- [ ] Push8()
- [ ] Pop8()
- [ ] Push16()
- [ ] Pop16()

## CPU

- [ ] Gestion complète du Stack Pointer
- [ ] Gestion des FLAGS

## Préparation du futur ISA

- [ ] CALL
- [ ] RET
- [ ] PUSH
- [ ] POP

## ROMs de validation

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom
- [ ] memory.rom

---

# Jalon historique

La version **v0.0.1-alpha** marque :

- La naissance officielle d'Azure-8
- La première ROM exécutable
- Le premier CPU fonctionnel
- Le premier système de chargement de ROM
- Le premier tag Git officiel
- Le premier jalon public d'AzureEngine

---

# État de la release

La version **v0.0.1-alpha** a été publiée avec succès.

Validation obtenue :

- [x] Compilation fonctionnelle
- [x] Chargement ROM
- [x] Exécution NOP
- [x] Exécution HLT
- [x] Débogage CPU
- [x] Documentation initiale
- [x] Premier tag Git créé

Cette version clôture officiellement le premier jalon Azure-8.

---

# Statut actuel

**Projet :** AzureEngine

**Version actuelle :** v0.0.1-alpha

**État :** Publié

**Prochaine version :** v0.0.2

**Objectif principal :**

- Read16()
- Write16()
- Stack
- PUSH
- POP
- CALL
- RET

---

**Premier jalon officiellement terminé. 🚀**