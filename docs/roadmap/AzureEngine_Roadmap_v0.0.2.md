# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **En développement**  
> Version précédente : **v0.0.1-alpha**  
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**  
> Progression estimée : **80 %**  
> Priorité actuelle : **Finalisation du Lot C - Stack Pointer**

---

# Présentation

La version **v0.0.2-alpha** est consacrée à la consolidation de l'infrastructure interne d'Azure-8.

Après la validation du premier cycle complet :

```txt
ROM
↓
Fetch
↓
Decode
↓
Execute
↓
HALT
```

l'objectif est désormais de terminer toutes les fondations nécessaires avant l'arrivée des premières véritables instructions de manipulation de données.

Cette version se concentre sur :

- la mémoire 16 bits ;
- la pile (Stack) ;
- le Stack Pointer ;
- les outils de diagnostic ;
- les tests de validation ;
- la préparation du système FLAGS.

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

0000h → FFFFh
```

## Philosophie

Azure-8 manipule exclusivement :

```txt
des données sur 8 bits
```

Les registres 16 bits servent uniquement à :

```txt
- l'adressage mémoire ;
- la pile ;
- le Program Counter ;
- les futurs appels de fonctions.
```

Azure-8 reste donc un véritable processeur 8 bits.

---

# Objectif principal

Finaliser complètement le système de pile Azure-8.

À la fin de la v0.0.2, Azure-8 devra disposer :

- d'une mémoire stable ;
- d'une pile fiable ;
- d'un Stack Pointer sécurisé ;
- d'outils de debug adaptés ;
- d'un environnement prêt pour le futur ISA.

---

# État d'avancement

## Fonctionnalités validées

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
- [x] Initialisation du SP
- [x] GetSP()
- [x] Validation Reset()
- [x] Validation Push8()
- [x] Validation Pop8()
- [x] Validation Push16()
- [x] Validation Pop16()
- [x] Détection Stack Overflow
- [x] Détection Stack Underflow

### Architecture

- [x] Refactorisation CPU
- [x] Refactorisation Memory

---

# Lot A - Mémoire

## Objectif

Construire la couche mémoire officielle d'Azure-8.

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

# Lot C - Stack Pointer (PRIORITÉ ABSOLUE)

## Objectif

Valider définitivement le fonctionnement du registre SP et de la pile.

### Fonctionnalités validées

- [x] STACK_TOP
- [x] STACK_BOTTOM
- [x] Initialisation du SP
- [x] Validation du Reset
- [x] Validation Push8()
- [x] Validation Pop8()
- [x] Validation Push16()
- [x] Validation Pop16()
- [x] Affichage du SP
- [x] Détection Overflow
- [x] Détection Underflow

---

## Travail restant

### Debug

- [ ] Dump Stack

### Robustesse

- [ ] Tests de charge
- [ ] Validation des limites mémoire

### Documentation

- [ ] Documentation Stack Pointer
- [ ] Documentation architecture Stack

---

## Critères de clôture

Le Lot C sera terminé lorsque :

- [x] SP validé
- [x] Overflow détecté
- [x] Underflow détecté
- [x] Affichage du SP opérationnel

et lorsque :

- [ ] Dump Stack opérationnel
- [ ] Tests de charge terminés
- [ ] Documentation Stack terminée

### Statut

🟨 En cours (≈ 90 %)

---

# Lot D - FLAGS

## Dépendance

⚠️ Ne commence qu'après clôture officielle du Lot C.

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

⬜ En attente

---

# Lot E - Debug

## Objectif

Améliorer les outils de diagnostic.

### Réalisé

- [x] Affichage PC
- [x] Affichage Opcode
- [x] Affichage SP

### À faire

- [ ] Dump Stack
- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump registres

### Statut

🟨 En cours

---

# Lot F - ROMs de validation

## Objectif

Créer une bibliothèque permanente de ROMs de validation pour Azure-8.

### ROMs fondamentales

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom

### ROMs mémoire

- [ ] memory16.rom

### ROMs Stack

- [x] stack8.rom
- [x] stack16.rom

### ROMs sécurité

- [x] overflow.rom
- [x] underflow.rom

### Note

Les ROMs :

```txt
stack8.rom
stack16.rom
overflow.rom
underflow.rom
```

sont déjà présentes dans le dépôt.

Leur validation effective est reportée à la v0.0.3 car elle dépend de futures instructions du processeur :

```asm
PUSH
POP
CALL
RET
```

### Statut

🟨 Partiellement terminé

---

# Lot G - Documentation

## Objectif

Maintenir les spécifications synchronisées avec le code.

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

# Ordre de développement

## Étape actuelle

```txt
LOT C

Dump Stack
↓
Tests de charge
↓
Documentation Stack
↓
Validation finale
```

## Étape suivante

```txt
LOT D

FLAGS
```

## Puis

```txt
LOT E

Debug avancé
```

## Puis

```txt
v0.0.3

MOV
LOAD
STORE

PUSH
POP

CALL
RET
```

---

# Critères de validation de la v0.0.2

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [x] Validation SP terminée
- [ ] Dump Stack terminé
- [ ] Documentation mise à jour
- [ ] Tests automatisés disponibles

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

Progression : ~80 %

Priorité :

Finalisation du Lot C
```

---

# Objectif de la v0.0.3

La version v0.0.3 introduira les premières vraies instructions manipulant les données :

```asm
MOV
LOAD
STORE

PUSH
POP

CALL
RET
```

Les ROMs :

```txt
stack8.rom
stack16.rom
overflow.rom
underflow.rom
```

pourront alors être exécutées et validées officiellement.

---

**Objectif immédiat : terminer Dump Stack, finaliser la documentation de la pile et clôturer définitivement le Lot C.**