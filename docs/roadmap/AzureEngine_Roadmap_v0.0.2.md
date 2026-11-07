# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**
>
> Statut : **En développement**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**

---

# Présentation

La version v0.0.2 poursuit la construction des fondations techniques d'Azure-8.

L'objectif n'est pas encore d'ajouter des fonctionnalités visibles mais de consolider l'infrastructure interne du processeur.

Cette version est consacrée à :

- la mémoire 16 bits ;
- la pile ;
- le Stack Pointer ;
- les FLAGS ;
- la préparation du futur jeu d'instructions.

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

Azure-8 reste un véritable processeur 8 bits.

Les systèmes 16 bits servent uniquement à l'adressage mémoire, au Program Counter et au Stack Pointer.

---

# État d'avancement

## Progression estimée

**60 %**

---

# Lot A - Mémoire

## Objectif

Finaliser la couche mémoire.

### Tâches

- [x] Read8()
- [x] Write8()
- [x] Read16()
- [x] Write16()
- [x] Validation Little Endian

### Statut

✅ Terminé

---

# Lot B - Stack

## Objectif

Créer une pile complète.

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
- [x] Réinitialisation du SP

### À terminer

- [ ] Validation complète du SP
- [ ] Stack Overflow Detection
- [ ] Stack Underflow Detection
- [ ] ROM de validation

### Statut

🟨 En cours

---

# Lot D - FLAGS

## Objectif

Préparer les opérations arithmétiques.

### FLAGS

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

### Statut

⬜ Non commencé

---

# Lot E - Debug

## Objectif

Améliorer les capacités de diagnostic.

### Tâches

- [ ] Affichage SP
- [ ] Affichage FLAGS
- [ ] Dump mémoire
- [ ] Dump pile
- [ ] Dump registres

### Statut

⬜ Non commencé

---

# Lot F - ROMs de validation

## Objectif

Créer une batterie de tests permanente.

### Tâches

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom
- [ ] memory16.rom
- [ ] stack8.rom
- [ ] stack16.rom
- [ ] overflow.rom
- [ ] underflow.rom

### Statut

⬜ Non commencé

---

# Lot G - Documentation

## Objectif

Compléter la documentation du projet.

### Tâches

- [ ] LICENSE
- [ ] Architecture.md
- [ ] Documentation Stack
- [ ] Documentation FLAGS
- [ ] Documentation SP
- [ ] Mise à jour Technical Specification

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

La version v0.0.2 sera terminée lorsque :

- [x] Read16 fonctionne
- [x] Write16 fonctionne
- [x] Push8 fonctionne
- [x] Pop8 fonctionne
- [x] Push16 fonctionne
- [x] Pop16 fonctionne
- [ ] Stack sécurisée
- [ ] FLAGS documentés
- [ ] ROMs de validation terminées
- [ ] Documentation mise à jour
- [ ] Tests automatisés disponibles

---

# Objectif de la v0.0.3

La version suivante introduira les premières véritables instructions de manipulation de données :

```asm
MOV
LOAD
STORE

INC
DEC

ADD
SUB
```

Ces instructions manipuleront exclusivement les registres 8 bits :

```txt
A
B
C
D
```

---

# Prochaine tâche immédiate

```txt
Stack Overflow Detection
Stack Underflow Detection
Validation complète du Stack Pointer
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

Progression : ~60 %

Prochaine étape :
Sécurisation complète du Stack Pointer
```