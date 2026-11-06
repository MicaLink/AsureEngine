# AzureEngine Roadmap v0.0.2

> Version cible : **v0.0.2-alpha**  
> Statut : **Planifiée**  
> Version précédente : **v0.0.1-alpha**  
> Début prévu : Immédiatement après la publication de v0.0.1-alpha

---

# Présentation

La version **v0.0.2-alpha** a pour objectif de faire évoluer Azure-8 d'un simple processeur capable d'exécuter `NOP` et `HLT` vers un véritable système capable de manipuler des données en mémoire.

Cette version introduit :

- la gestion des valeurs 16 bits ;
- la pile (Stack) ;
- les premières opérations mémoire avancées ;
- les bases nécessaires aux sous-programmes.

À la fin de cette version, Azure-8 sera capable de préparer l'implémentation de :

```asm
CALL
RET
PUSH
POP
```

---

# Objectif de la version

Valider les fondations nécessaires pour les futures instructions complexes du processeur.

Cette version doit permettre :

- la lecture 16 bits ;
- l'écriture 16 bits ;
- la gestion complète de la stack ;
- la manipulation du Stack Pointer ;
- les premiers tests mémoire avancés.

---

# État d'avancement

**Progression estimée : 0 %**

---

# Lot A - Mémoire 16 bits

## Objectif

Permettre la manipulation de valeurs sur 16 bits.

### Tâches

- [ ] Implémenter Read16()
- [ ] Implémenter Write16()
- [ ] Validation Little Endian
- [ ] Tests unitaires mémoire

### Validation

Exemple :

```cpp
memory.Write16(
    0x1000,
    0x1234);
```

Résultat attendu :

```txt
RAM[1000] = 34
RAM[1001] = 12
```

### Statut

⬜ Non commencé

---

# Lot B - Stack

## Objectif

Ajouter la gestion complète de la pile.

### Tâches

- [ ] Définir le comportement officiel de la Stack
- [ ] Initialisation correcte du SP
- [ ] Implémenter Push8()
- [ ] Implémenter Pop8()
- [ ] Implémenter Push16()
- [ ] Implémenter Pop16()

### Validation

Exemple :

```cpp
Push8(0x42);
```

Puis :

```cpp
Pop8();
```

Résultat attendu :

```txt
42
```

### Statut

⬜ Non commencé

---

# Lot C - Registre SP

## Objectif

Valider le fonctionnement du Stack Pointer.

### Tâches

- [ ] Décrément automatique sur Push
- [ ] Incrément automatique sur Pop
- [ ] Vérification dépassement mémoire
- [ ] Vérification sous-dépassement mémoire

### Statut

⬜ Non commencé

---

# Lot D - Drapeaux CPU

## Objectif

Préparer la gestion avancée des instructions.

### Tâches

- [ ] Documenter FLAGS
- [ ] Initialisation FLAGS
- [ ] Définir Zero Flag
- [ ] Définir Carry Flag
- [ ] Définir Negative Flag
- [ ] Définir Overflow Flag

### Statut

⬜ Non commencé

---

# Lot E - Instructions mémoire

## Objectif

Préparer l'arrivée des futures instructions CPU.

### Étude préliminaire

- [ ] MOV
- [ ] LOAD
- [ ] STORE

### Documentation

- [ ] Définir les opcodes
- [ ] Définir les formats d'instructions
- [ ] Définir les modes d'adressage simples

### Statut

⬜ Non commencé

---

# Lot F - ROM de validation

## Objectif

Créer un ensemble de ROM permettant de valider le processeur.

### Tâches

- [ ] nop.rom
- [ ] halt.rom
- [ ] invalid.rom
- [ ] stack8.rom
- [ ] stack16.rom
- [ ] memory16.rom

### Statut

⬜ Non commencé

---

# Lot G - Debug

## Objectif

Améliorer les informations affichées.

### Tâches

- [ ] Affichage SP
- [ ] Affichage FLAGS
- [ ] Affichage mémoire stack
- [ ] Dump mémoire

### Exemple attendu

```txt
PC=0003
SP=FFFE
OPCODE=XX

A=00
B=00
C=00
D=00
```

### Statut

⬜ Non commencé

---

# Lot H - Documentation

## Objectif

Maintenir la documentation à jour.

### Tâches

- [ ] Mettre à jour Azure-8 Technical Specification
- [ ] Documenter la Stack
- [ ] Documenter Read16()
- [ ] Documenter Write16()
- [ ] Documenter les FLAGS

### Statut

⬜ Non commencé

---

# Architecture cible

À la fin de la version v0.0.2 :

```txt
AzureEngine
│
├── Azure8
│   │
│   ├── CPU
│   │   ├── Fetch
│   │   ├── Decode
│   │   ├── Execute
│   │   ├── Stack
│   │   └── Flags
│   │
│   ├── Memory
│   │   ├── Read8
│   │   ├── Write8
│   │   ├── Read16
│   │   └── Write16
│   │
│   └── Emulator
│
├── docs
│
├── roms
│
└── tests
```

---

# Critères de validation

La version v0.0.2-alpha sera considérée comme terminée lorsque :

- [ ] Read16 fonctionne
- [ ] Write16 fonctionne
- [ ] Push8 fonctionne
- [ ] Pop8 fonctionne
- [ ] Push16 fonctionne
- [ ] Pop16 fonctionne
- [ ] SP est correctement géré
- [ ] Toutes les ROM de test passent
- [ ] Documentation mise à jour

---

# Hors périmètre de la v0.0.2

Les éléments suivants restent exclus :

- GPU
- Audio
- BIOS
- AzureASM
- Azure Studio
- Marketplace
- Azure-16
- Jeux
- Matériel réel

---

# Objectif de la version suivante

## AzureEngine v0.0.3

Objectif :

Introduire les premières véritables instructions manipulant les données :

```asm
MOV
LOAD
STORE
INC
DEC
ADD
SUB
```

Cette version marquera le passage d'un processeur de démonstration à un processeur programmable.

---

# Résultat attendu

À la fin de la v0.0.2, Azure-8 doit être capable de :

```txt
Lire la mémoire 16 bits
Gérer une pile
Manipuler le Stack Pointer
Préparer les sous-programmes
Préparer les futures instructions de calcul
```

---

**Prochaine étape du projet : rendre Azure-8 capable de stocker et manipuler ses premières données.**