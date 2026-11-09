# Documentation FLAGS

Version : v0.0.2-alpha

---

# Présentation

Le registre FLAGS est utilisé par le processeur Azure-8 pour mémoriser l'état du résultat de certaines opérations.

Les FLAGS permettent au CPU de savoir si une opération a :

```txt
- produit zéro
- produit une valeur négative
- généré une retenue
- généré un dépassement signé
```

Le système FLAGS constitue la base des futures instructions conditionnelles prévues pour Azure-8.

---

# Caractéristiques

## Taille

```txt
8 bits
```

Le registre FLAGS est stocké dans le CPU comme un registre utilisateur dédié.

Déclaration actuelle :

```cpp
u8 FLAGS = 0;
```

---

# Organisation

Le registre FLAGS utilise actuellement les quatre premiers bits.

```txt
Bit 0 : Zero Flag     (Z)
Bit 1 : Carry Flag    (C)
Bit 2 : Negative Flag (N)
Bit 3 : Overflow Flag (V)

Bits 4 à 7 : Réservés
```

Représentation :

```txt
7 6 5 4 3 2 1 0

- - - - V N C Z
```

---

# Constantes

Les FLAGS sont définis comme suit :

```cpp
constexpr u8 FLAG_ZERO     = (1 << 0);
constexpr u8 FLAG_CARRY    = (1 << 1);
constexpr u8 FLAG_NEGATIVE = (1 << 2);
constexpr u8 FLAG_OVERFLOW = (1 << 3);
```

Valeurs binaires :

```txt
FLAG_ZERO     = 00000001b
FLAG_CARRY    = 00000010b
FLAG_NEGATIVE = 00000100b
FLAG_OVERFLOW = 00001000b
```

Valeurs hexadécimales :

```txt
FLAG_ZERO     = 01h
FLAG_CARRY    = 02h
FLAG_NEGATIVE = 04h
FLAG_OVERFLOW = 08h
```

---

# Initialisation

Lors d'un Reset CPU :

```cpp
FLAGS = 0;
```

État initial :

```txt
00000000b
```

ou :

```txt
00h
```

Aucun indicateur n'est actif.

---

# Zero Flag

## Description

Le Zero Flag indique qu'une opération a produit une valeur nulle.

Bit :

```txt
Bit 0
```

---

## Activation

Le flag est activé lorsque :

```txt
Résultat = 0
```

Exemple :

```txt
00h
```

---

## Désactivation

Le flag est désactivé lorsque :

```txt
Résultat ≠ 0
```

Exemple :

```txt
01h
05h
80h
FFh
```

---

## Fonction associée

```cpp
UpdateZeroFlag()
```

Exemple :

```cpp
UpdateZeroFlag(0);
```

Résultat :

```txt
Z = 1
```

---

# Carry Flag

## Description

Le Carry Flag indique qu'une opération a généré une retenue.

Bit :

```txt
Bit 1
```

---

## Utilisation actuelle

Le système est implémenté mais n'est pas encore utilisé par les instructions.

---

## Utilisation future

Prévu pour :

```asm
ADD
SUB
ADC
SBC
```

---

## Fonction associée

```cpp
UpdateCarryFlag()
```

Exemple :

```cpp
UpdateCarryFlag(true);
```

Résultat :

```txt
C = 1
```

---

# Negative Flag

## Description

Le Negative Flag indique qu'une valeur possède son bit de signe activé.

Bit :

```txt
Bit 2
```

---

## Activation

Le flag est activé lorsque :

```txt
Bit 7 = 1
```

Exemples :

```txt
80h
A0h
FFh
```

---

## Désactivation

Le flag est désactivé lorsque :

```txt
Bit 7 = 0
```

Exemples :

```txt
00h
01h
7Fh
```

---

## Fonction associée

```cpp
UpdateNegativeFlag()
```

Exemple :

```cpp
UpdateNegativeFlag(0x80);
```

Résultat :

```txt
N = 1
```

---

# Overflow Flag

## Description

Le Overflow Flag indique un dépassement lors d'une opération signée.

Bit :

```txt
Bit 3
```

---

## Utilisation actuelle

Le système est implémenté mais n'est pas encore utilisé par les instructions.

---

## Utilisation future

Prévu pour :

```asm
ADD
SUB
CMP
```

---

## Fonction associée

```cpp
UpdateOverflowFlag()
```

Exemple :

```cpp
UpdateOverflowFlag(true);
```

Résultat :

```txt
V = 1
```

---

# Manipulation des FLAGS

Le processeur fournit plusieurs fonctions de gestion.

---

## SetFlag()

Prototype :

```cpp
void SetFlag(u8 flag);
```

Objectif :

```txt
Activer un flag.
```

Exemple :

```cpp
SetFlag(FLAG_ZERO);
```

Résultat :

```txt
FLAGS = 01h
```

---

## ClearFlag()

Prototype :

```cpp
void ClearFlag(u8 flag);
```

Objectif :

```txt
Désactiver un flag.
```

Exemple :

```cpp
ClearFlag(FLAG_ZERO);
```

Résultat :

```txt
FLAGS = 00h
```

---

## IsFlagSet()

Prototype :

```cpp
bool IsFlagSet(u8 flag) const;
```

Objectif :

```txt
Vérifier si un flag est actif.
```

Exemple :

```cpp
if (IsFlagSet(FLAG_ZERO))
{
    ...
}
```

---

## GetFlags()

Prototype :

```cpp
u8 GetFlags() const;
```

Objectif :

```txt
Lire l'intégralité du registre FLAGS.
```

Exemple :

```cpp
printf(
    "%02X\n",
    GetFlags());
```

---

# Exemples

## Zero Flag

```cpp
UpdateZeroFlag(0);
```

Résultat :

```txt
FLAGS = 01h
```

---

## Carry Flag

```cpp
UpdateCarryFlag(true);
```

Résultat :

```txt
FLAGS = 02h
```

---

## Negative Flag

```cpp
UpdateNegativeFlag(0x80);
```

Résultat :

```txt
FLAGS = 04h
```

---

## Overflow Flag

```cpp
UpdateOverflowFlag(true);
```

Résultat :

```txt
FLAGS = 08h
```

---

## Combinaison

```cpp
UpdateZeroFlag(0);
UpdateCarryFlag(true);
UpdateNegativeFlag(0x80);
UpdateOverflowFlag(true);
```

Résultat :

```txt
FLAGS = 0Fh
```

Représentation :

```txt
00001111b
```

---

# Débogage

Le registre FLAGS est affiché dans le debug CPU.

Exemple :

```txt
PC=0004 SP=FFFF FLAGS=00 OPCODE=00
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

# Validation réalisée

Tests validés dans la version v0.0.2 :

```txt
✓ FLAG_ZERO
✓ FLAG_CARRY
✓ FLAG_NEGATIVE
✓ FLAG_OVERFLOW

✓ SetFlag()
✓ ClearFlag()

✓ IsFlagSet()
✓ GetFlags()

✓ UpdateZeroFlag()
✓ UpdateCarryFlag()

✓ UpdateNegativeFlag()
✓ UpdateOverflowFlag()

✓ Affichage Debug
```

---

# Utilisation future

Le système FLAGS sera utilisé par les futures instructions :

```asm
ADD
SUB

CMP

JZ
JNZ
```

et plus généralement par toutes les instructions conditionnelles de l'architecture Azure-8.

---

# Résumé

```txt
Composant : FLAGS

Taille : 8 bits

Flags utilisés :

Bit 0 : Zero
Bit 1 : Carry
Bit 2 : Negative
Bit 3 : Overflow

Fonctions :

✓ SetFlag()
✓ ClearFlag()

✓ IsFlagSet()
✓ GetFlags()

✓ UpdateZeroFlag()
✓ UpdateCarryFlag()

✓ UpdateNegativeFlag()
✓ UpdateOverflowFlag()

Debug :

✓ Affichage FLAGS
✓ DumpRegister()
```

---

Fin du document.