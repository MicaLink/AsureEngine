# Documentation Stack Pointer

Version : v0.0.2-alpha

---

# Présentation

Le Stack Pointer (SP) est le registre système chargé de gérer la position actuelle de la pile (Stack).

Il permet au processeur Azure-8 de :

```txt
- Localiser le sommet de la pile
- Empiler des données
- Dépiler des données
- Détecter les erreurs de pile
- Préparer les futurs appels de fonctions
```

Le Stack Pointer est une composante fondamentale de l'architecture Azure-8.

---

# Caractéristiques

## Taille

```txt
16 bits
```

Le registre SP est capable d'adresser l'ensemble de l'espace mémoire :

```txt
0000h
↓
FFFFh
```

---

## Registre système

Azure-8 possède deux registres système :

```txt
PC  Program Counter
SP  Stack Pointer
```

Le registre SP est réservé à la gestion de la pile.

---

# Organisation de la pile

La pile est située dans la partie supérieure de la mémoire.

Configuration actuelle :

```txt
STACK_BOTTOM = FE00h
STACK_TOP    = FFFFh
```

Zone mémoire réservée :

```txt
FFFFh  ← Sommet initial

│
│
│

FE00h  ← Limite basse
```

Taille totale :

```txt
512 octets
```

Calcul :

```txt
FFFFh - FE00h + 1
=
0200h
=
512 octets
```

---

# Initialisation

Lors d'un Reset CPU :

```cpp
SP = STACK_TOP;
```

Valeur initiale :

```txt
FFFFh
```

Cette valeur indique :

```txt
Pile vide
```

---

# Fonctionnement

Azure-8 utilise une pile descendante.

Lors d'un PUSH :

```txt
Écriture mémoire
↓
SP--
```

Lors d'un POP :

```txt
SP++
↓
Lecture mémoire
```

---

# Exemple

État initial :

```txt
SP = FFFFh
```

---

Après :

```cpp
Push8(memory, 12h);
```

Résultat :

```txt
Mémoire :

FFFFh = 12h

SP = FFFEh
```

---

Après :

```cpp
Push8(memory, 34h);
```

Résultat :

```txt
Mémoire :

FFFFh = 12h
FFFEh = 34h

SP = FFFDh
```

---

Après :

```cpp
Pop8(memory);
```

Résultat :

```txt
Valeur retournée : 34h

SP = FFFEh
```

---

# Lecture du Stack Pointer

Prototype :

```cpp
u16 GetSP() const;
```

Objectif :

```txt
Lire la position actuelle de la pile.
```

Exemple :

```cpp
printf(
    "SP = %04X\n",
    cpu.GetSP());
```

Résultat :

```txt
SP = FFFC
```

---

# Relation avec Push8()

Lors d'un Push8() :

```cpp
memory.Write8(
    SP,
    value);

SP--;
```

Le Stack Pointer est décrémenté après l'écriture.

---

# Relation avec Pop8()

Lors d'un Pop8() :

```cpp
SP++;

return memory.Read8(
    SP);
```

Le Stack Pointer est incrémenté avant la lecture.

---

# Relation avec Push16()

Une valeur 16 bits est décomposée en :

```txt
High Byte
Low Byte
```

Puis empilée en deux opérations 8 bits.

Le Stack Pointer est décrémenté deux fois.

---

# Relation avec Pop16()

Une valeur 16 bits est reconstruite à partir de :

```txt
Low Byte
High Byte
```

Le Stack Pointer est incrémenté deux fois.

---

# Protection contre les erreurs

Le Stack Pointer participe directement à la détection :

```txt
Stack Overflow
Stack Underflow
```

---

# Overflow

Condition :

```txt
SP < STACK_BOTTOM
```

Conséquence :

```txt
STACK OVERFLOW
```

Actions :

```txt
m_StackOverflow = true
m_Halted = true
```

Le processeur est arrêté.

---

# Underflow

Condition :

```txt
SP >= STACK_TOP
```

Conséquence :

```txt
STACK UNDERFLOW
```

Actions :

```txt
m_StackUnderflow = true
m_Halted = true
```

Le processeur est arrêté.

---

# Débogage

Le Stack Pointer apparaît dans les informations de debug.

Exemple :

```txt
PC=0004 SP=FFFD FLAGS=00 OPCODE=00
```

---

## DumpRegister()

```cpp
cpu.DumpRegister();
```

Exemple :

```txt
========== REGISTERS ==========

A     = 00
B     = 00
C     = 00
D     = 00

PC    = 0000
SP    = FFFF

FLAGS = 00

===============================
```

---

## DumpStack()

```cpp
cpu.DumpStack(memory);
```

Exemple :

```txt
========== STACK ==========

SP = FFFD

FFFE : 22 <- TOP
FFFF : 11

===========================
```

---

# Validation réalisée

Tests validés dans la version v0.0.2 :

```txt
✓ Initialisation du SP

✓ Lecture GetSP()

✓ Push8()
✓ Pop8()

✓ Push16()
✓ Pop16()

✓ Décrémentation automatique

✓ Incrémentation automatique

✓ Détection Overflow

✓ Détection Underflow

✓ Affichage Debug
```

---

# Utilisation future

Le registre SP constitue la base des futures instructions :

```asm
PUSH
POP

CALL
RET
```

prévues pour :

```txt
Azure-8 v0.0.3
```

---

# Résumé

```txt
Composant : Stack Pointer

Registre : SP

Taille : 16 bits

Valeur initiale :

FFFFh

Zone de pile :

FE00h → FFFFh

Fonctions associées :

✓ GetSP()

✓ Push8()
✓ Pop8()

✓ Push16()
✓ Pop16()

Protection :

✓ Stack Overflow
✓ Stack Underflow
```

---

Fin du document.