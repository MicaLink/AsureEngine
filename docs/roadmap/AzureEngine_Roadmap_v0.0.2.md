# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **En développement**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression estimée : **75 %**

---

# Priorité actuelle

⚠️ Le développement du Lot D (FLAGS) est suspendu.

La priorité absolue est la finalisation du **Lot C - Stack Pointer**.

Aucune nouvelle fonctionnalité CPU ne sera ajoutée avant la validation complète de la pile.

---

# Présentation

La version v0.0.2 est consacrée à l'infrastructure mémoire et système du processeur Azure-8.

Les objectifs sont :

- stabiliser la mémoire ;
- finaliser la pile ;
- sécuriser le registre SP ;
- construire les outils de validation ;
- préparer les futures instructions du processeur.

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
64 Ko

0000h -> FFFFh
```

Azure-8 demeure strictement un processeur 8 bits.

Les registres 16 bits servent uniquement à :

- l'adressage mémoire ;
- la pile ;
- les futurs appels de fonctions.

---

# Lot A - Mémoire

## Statut

✅ Terminé

### Fonctionnalités validées

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()
- [x] Little Endian

---

# Lot B - Stack

## Statut

✅ Terminé

### Fonctionnalités validées

- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()

---

# Lot C - Stack Pointer (PRIORITÉ ACTUELLE)

## Objectif

Valider complètement la pile Azure-8.

### Fonctionnalités validées

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Initialisation SP
- [x] Push8()
- [x] Pop8()
- [x] Push16()
- [x] Pop16()
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow
- [x] Messages d'erreur

### Travail restant

#### Validation

- [ ] Validation complète du SP
- [ ] Validation après Push8()
- [ ] Validation après Pop8()
- [ ] Validation après Push16()
- [ ] Validation après Pop16()

#### ROMs de test

- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

#### Debug

- [ ] Affichage permanent du SP
- [ ] Dump Stack

#### Robustesse

- [ ] Tests de charge
- [ ] Validation limites mémoire

### Critère de sortie

Le Lot C est terminé lorsque :

- toutes les ROMs Stack fonctionnent ;
- Overflow est détecté ;
- Underflow est détecté ;
- SP est validé dans tous les scénarios ;
- les outils Debug Stack sont opérationnels.

### Statut

🟨 En cours

---

# Lot D - FLAGS

## Dépendance

⚠️ Ce lot ne commencera qu'après validation complète du Lot C.

### Tâches prévues

- [ ] Zero Flag
- [ ] Carry Flag
- [ ] Negative Flag
- [ ] Overflow Flag

### Statut

⬜ En attente

---

# Lot E - Debug

## Tâches

- [x] Affichage PC
- [x] Affichage Opcode

### En attente du Lot C

- [ ] Affichage SP
- [ ] Dump Stack

### En attente du Lot D

- [ ] Affichage FLAGS

### Statut

🟨 En cours

---

# Lot F - ROMs de validation

## Objectif

Créer une bibliothèque permanente de ROMs de test.

### ROMs générales

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

### ROMs mémoire

- [ ] memory16.rom

### ROMs pile

- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

### Statut

⬜ Non commencé

---

# Lot G - Documentation

## Tâches

- [ ] LICENSE
- [ ] Architecture.md
- [ ] Documentation Stack
- [ ] Documentation SP

### Statut

⬜ Non commencé

---

# Lot H - Qualité

## Tâches

- [ ] Vérification warnings MSVC
- [ ] Nettoyage dépôt Git
- [ ] Premiers tests automatisés

### Statut

⬜ Non commencé

---

# Ordre de développement

## Étape actuelle

```txt
LOT C

Stack Pointer
↓
ROMs Stack
↓
Validation complète
```

## Étape suivante

```txt
LOT D

FLAGS
```

## Puis

```txt
v0.0.3

MOV
LOAD
STORE
```

---

# État actuel

```txt
Projet : AzureEngine

Version : v0.0.2-alpha

Architecture :

CPU       8 bits
PC        16 bits
SP        16 bits
RAM       64 Ko

Progression : ~75 %

Priorité :
Finalisation complète du Stack Pointer
```

---

**Objectif immédiat : clôturer définitivement le Lot C avant d'entamer le système de FLAGS.**