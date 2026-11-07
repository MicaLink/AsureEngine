# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **75 %**

---

# Présentation

La version **v0.0.2-alpha** poursuit la consolidation des fondations techniques de Azure-8.

Après la validation du premier processeur capable de charger et exécuter une ROM binaire, cette version est consacrée à l'infrastructure interne du système :

- mémoire 16 bits ;
- pile (Stack) ;
- Stack Pointer ;
- gestion des FLAGS ;
- outils de validation ;
- outils de débogage.

L'objectif est de disposer d'un processeur 8 bits stable avant l'introduction du premier véritable jeu d'instructions manipulant des données.

---

# Architecture officielle Azure-8

Azure-8 est un processeur **8 bits**.

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

0000h -> FFFFh
```

## Philosophie

Azure-8 travaille exclusivement sur :

```txt
des données 8 bits
```

et utilise :

```txt
un adressage mémoire 16 bits
```

pour permettre :

- l'accès à 64 Ko de mémoire ;
- l'utilisation d'une pile ;
- les futurs appels de fonctions ;
- les futures extensions du système.

Cette architecture est proche de celles utilisées par :

- MOS 6502
- Z80
- Motorola 6809

---

# Objectif principal

Finaliser toute l'infrastructure mémoire et système nécessaire avant l'arrivée des premières instructions de manipulation de données.

À la fin de cette version, Azure-8 devra disposer :

- d'une mémoire stable ;
- d'une pile robuste ;
- d'un Stack Pointer sécurisé ;
- d'un système de FLAGS défini ;
- d'un environnement de validation complet.

---

# État d'avancement

## Fonctionnalités terminées

### Mémoire

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()
- [x] Validation Little Endian

### CPU

- [x] Fetch
- [x] Decode
- [x] Execute

### Stack

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

### Stack Pointer

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Initialisation au Reset
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow

### Architecture

- [x] Refactorisation CPU
- [x] Refactorisation Memory

---

# Lot A - Mémoire

## Objectif

Finaliser la couche mémoire.

### Tâches

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()

### Statut

✅ Terminé

---

# Lot B - Stack

## Objectif

Créer une pile fonctionnelle.

### Tâches

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

### Statut

✅ Terminé

---

# Lot C - Stack Pointer

## Objectif

Sécuriser totalement la pile.

### Tâches

- [x] Définition STACK_TOP
- [x] Définition STACK_BOTTOM
- [x] Validation du Reset
- [x] Stack Overflow Detection
- [x] Stack Underflow Detection
- [x] Messages d'erreur dédiés

### À faire

- [ ] ROMs de validation
- [ ] Tests de charge

### Statut

✅ Fonctionnel

---

# Lot D - FLAGS

## Objectif

Préparer les futures opérations CPU.

### FLAGS prévus

```txt
Bit 0 : Zero
Bit 1 : Carry
Bit 2 : Negative
Bit 3 : Overflow
```

### Tâches

- [ ] Définition officielle
- [ ] Helpers CPU
- [ ] Documentation
- [ ] Première implémentation

### Statut

🟨 Priorité actuelle

---

# Lot E - Debug

## Objectif

Améliorer les outils de diagnostic.

### Déjà réalisés

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP

### À faire

- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump pile
- [ ] Dump registres

### Exemple cible

```txt
PC=0005
SP=FFFC

A=00
B=00
C=00
D=00

FLAGS=00
```

### Statut

🟨 En cours

---

# Lot F - ROMs de validation

## Objectif

Créer une batterie de ROMs de test permanente.

### Tâches

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

### Mémoire

- [ ] memory16.rom

### Stack

- [ ] stack8.rom
- [ ] stack16.rom

### Sécurité

- [ ] overflow.rom
- [ ] underflow.rom

### Statut

⬜ Non commencé

---

# Lot G - Documentation

## Objectif

Maintenir les spécifications à jour.

### Tâches

- [ ] LICENSE
- [ ] Architecture.md
- [ ] Documentation Stack
- [ ] Documentation SP
- [ ] Documentation FLAGS
- [ ] Mise à jour Azure-8 Technical Specification

### Statut

⬜ Non commencé

---

# Lot H - Qualité

## Objectif

Préparer AzureEngine pour les futures versions.

### Tâches

- [ ] Vérifier les warnings MSVC
- [ ] Nettoyer le dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Critères de validation

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [x] Stack sécurisée
- [ ] FLAGS implémentés
- [ ] ROMs de validation terminées
- [ ] Documentation terminée
- [ ] Tests automatisés disponibles

---

# Objectif de la v0.0.3

La version v0.0.3 introduira les premières véritables instructions de manipulation de données :

```asm
MOV
LOAD
STORE
```

Puis :

```asm
INC
DEC

ADD
SUB
```

Ces instructions manipuleront exclusivement les registres :

```txt
A
B
C
D
```

sur 8 bits.

---

# Prochaine tâche prioritaire

Implémentation du système FLAGS :

```txt
Zero Flag
Carry Flag
Negative Flag
Overflow Flag
```

Cette étape est nécessaire avant :

```asm
INC
DEC
ADD
SUB
CMP
```

---

# État actuel

```txt
Projet : AzureEngine

Version actuelle : v0.0.2-alpha

Architecture :

CPU           8 bits
PC            16 bits
SP            16 bits
RAM           64 Ko

Progression : ~75 %

Prochaine étape :
Implémentation des FLAGS
```

---

**Objectif du jalon : terminer toute l'infrastructure système avant l'arrivée du premier véritable jeu d'instructions Azure-8.**