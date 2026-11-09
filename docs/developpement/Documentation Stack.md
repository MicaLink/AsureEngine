# Documentation Stack

Version : v0.0.2-alpha

---

# Présentation

Azure-8 dispose d'un système de pile (Stack) permettant le stockage temporaire de données durant l'exécution d'un programme.

La pile est utilisée pour :

```txt
- Stocker des données temporaires
- Sauvegarder des registres
- Préparer les futurs appels de fonctions
- Préparer les futures instructions PUSH
- Préparer les futures instructions POP
- Préparer les futures instructions CALL
- Préparer les futures instructions RET
```

Le système de pile est entièrement implémenté et validé dans la version v0.0.2.

---

# Organisation mémoire

La pile est située en haut de l'espace mémoire.

Configuration actuelle :

```txt
STACK_BOTTOM = FE00h
STACK_TOP    = FFFFh
```

Zone réservée :

```txt
Adresse

FFFFh  <- Sommet de pile initial

│
│
│

FE00h  <- Limite basse

FDFFh  <- Overflow
```

---

# Principe de fonctionnement

Azure-8 utilise une pile descendante.

Chaque opération PUSH :

```txt
Stocke une valeur
Puis décrémente SP
```

Chaque opération POP :

```txt
Incrémente SP
Puis récupère la valeur
```

Représentation :

```txt
PUSH

SP = FFFF

Écriture
↓
FFFF

SP = FFFE
```

```txt
POP

SP = FFFE

SP = FFFF
↓
Lecture
```

---

# Stack Pointer

Le Stack Pointer est enregistré dans :

```txt
SP
```

Caractéristiques :

```txt
Taille : 16 bits
```

Valeur après Reset :

```txt
FFFFh
```

Initialisation :

```cpp
SP = STACK_TOP;
```

---

# Opérations disponibles

Azure-8 supporte actuellement :

```cpp
Push8()
Pop8()

Push16()
Pop16()
```

---

# Push8

Prototype :

```cpp
void Push8(
    Memory& memory,
    u8 value);
```

Objectif :

```txt
Empiler une valeur de 8 bits.
```

Fonctionnement :

```txt
1. Vérification overflow
2. Écriture mémoire
3. Décrémentation du SP
```

Exemple :

```txt
SP = FFFF

Push8(12h)

Mémoire :

FFFF = 12h

SP = FFFEh
```

---

# Pop8

Prototype :

```cpp
u8 Pop8(
    Memory& memory);
```

Objectif :

```txt
Récupérer une valeur de 8 bits depuis la pile.
```

Fonctionnement :

```txt
1. Vérification underflow
2. Incrémentation du SP
3. Lecture mémoire
```

Exemple :

```txt
SP = FFFEh

Pop8()

SP = FFFFh

Retour :

12h
```

---

# Push16

Prototype :

```cpp
void Push16(
    Memory& memory,
    u16 value);
```

Objectif :

```txt
Empiler une valeur de 16 bits.
```

Le stockage est réalisé en deux opérations Push8().

---

## Exemple

Valeur :

```txt
1234h
```

Décomposition :

```txt
High = 12h
Low  = 34h
```

Empilage :

```txt
Push8(12h)
Push8(34h)
```

Mémoire :

```txt
FFFF = 12h
FFFE = 34h
```

---

# Pop16

Prototype :

```cpp
u16 Pop16(
    Memory& memory);
```

Objectif :

```txt
Récupérer une valeur de 16 bits.
```

Le résultat est reconstruit à partir de deux lectures 8 bits.

---

## Exemple

Pile :

```txt
FFFF = 12h
FFFE = 34h
```

Lecture :

```txt
Low  = 34h
High = 12h
```

Résultat :

```txt
1234h
```

---

# Gestion des erreurs

Le système de pile protège contre :

```txt
Stack Overflow
Stack Underflow
```

---

# Stack Overflow

Condition :

```txt
SP < STACK_BOTTOM
```

Résultat :

```txt
STACK OVERFLOW
```

Actions :

```txt
m_StackOverflow = true
m_Halted = true
```

Le processeur est immédiatement arrêté.

---

# Stack Underflow

Condition :

```txt
SP >= STACK_TOP
```

Résultat :

```txt
STACK UNDERFLOW
```

Actions :

```txt
m_StackUnderflow = true
m_Halted = true
```

Le processeur est immédiatement arrêté.

---

# Fonctions de diagnostic

La fonction :

```cpp
DumpStack()
```

permet d'inspecter le contenu actuel de la pile.

Prototype :

```cpp
void DumpStack(
    const Memory& memory,
    u16 count = 16) const;
```

---

## Exemple de sortie

```txt
========== STACK ==========

SP = FFFC

FFFD : 33 <- TOP
FFFE : 22
FFFF : 11

===========================
```

---

# Validation réalisée

Tests validés dans la v0.0.2 :

```txt
✓ Push8()
✓ Pop8()

✓ Push16()
✓ Pop16()

✓ Stack Overflow
✓ Stack Underflow

✓ DumpStack()

✓ Validation limites mémoire

✓ Tests de charge
```

---

# Utilisation future

Le système de pile servira de base pour les futures instructions :

```asm
PUSH
POP

CALL
RET
```

prévues pour la version :

```txt
v0.0.3
```

---

# Statut

```txt
Composant : Stack

Version : v0.0.2-alpha

État : Validé

Fonctions :

✓ Push8()
✓ Pop8()

✓ Push16()
✓ Pop16()

✓ Overflow
✓ Underflow

✓ DumpStack()
```

---

Fin du document.