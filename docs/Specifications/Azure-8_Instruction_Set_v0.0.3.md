# Azure-8 Instruction Set Specification v0.0.3

Version : v0.0.3-alpha

Statut : Draft

---

# Présentation

Ce document définit la première version du jeu d'instructions programmable d'Azure-8.

L'objectif est de permettre :

```txt
Manipulation de données

Accès mémoire

Gestion de la pile

Calculs arithmétiques

Branchements conditionnels
```

La v0.0.3 constitue la première étape vers un processeur capable d'exécuter des programmes complets.

---

# Registres disponibles

## Registres généraux

```txt
A
B
C
D
```

Taille :

```txt
8 bits
```

---

## Registres système

```txt
PC
SP
FLAGS
```

---

# Conventions d'encodage

## Registres

```txt
00h = A

01h = B

02h = C

03h = D
```

---

## Adresses mémoire

Toutes les adresses mémoire sont codées sur :

```txt
16 bits
```

Format :

```txt
Low Byte
High Byte
```

(Little Endian)

---

# Jeu d'instructions v0.0.3

---

# Contrôle CPU

## NOP

Opcode :

```txt
00h
```

Description :

```txt
Aucune opération.
```

Taille :

```txt
1 octet
```

---

## HLT

Opcode :

```txt
FFh
```

Description :

```txt
Arrêt du processeur.
```

Taille :

```txt
1 octet
```

---

# Instructions de données

---

## MOV

### Description

Copie le contenu d'un registre vers un autre.

---

### Format

```asm
MOV destination, source
```

---

### Exemple

```asm
MOV A, B
```

Résultat :

```txt
A = B
```

---

### Encodage

```txt
10h

Byte 0 : Opcode

Byte 1 : Destination

Byte 2 : Source
```

---

### Taille

```txt
3 octets
```

---

## LOAD

### Description

Charge une valeur mémoire dans un registre.

---

### Format

```asm
LOAD Registre, Adresse
```

---

### Exemple

```asm
LOAD A, 1000h
```

Résultat :

```txt
A = mémoire[1000h]
```

---

### Encodage

```txt
11h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

---

### Taille

```txt
4 octets
```

---

## STORE

### Description

Écrit un registre en mémoire.

---

### Format

```asm
STORE Registre, Adresse
```

---

### Exemple

```asm
STORE A, 1000h
```

Résultat :

```txt
mémoire[1000h] = A
```

---

### Encodage

```txt
12h

Byte 0 : Opcode

Byte 1 : Registre

Byte 2 : Adresse Low

Byte 3 : Adresse High
```

---

### Taille

```txt
4 octets
```

---

# Gestion de pile

---

## PUSH

### Description

Empile un registre.

---

### Format

```asm
PUSH A
```

---

### Encodage

```txt
20h

Byte 0 : Opcode

Byte 1 : Registre
```

---

### Taille

```txt
2 octets
```

---

## POP

### Description

Dépile dans un registre.

---

### Format

```asm
POP A
```

---

### Encodage

```txt
21h

Byte 0 : Opcode

Byte 1 : Registre
```

---

### Taille

```txt
2 octets
```

---

## CALL

### Description

Appel de sous-routine.

---

### Format

```asm
CALL Adresse
```

---

### Encodage

```txt
22h

Byte 0 : Opcode

Byte 1 : Adresse Low

Byte 2 : Adresse High
```

---

### Taille

```txt
3 octets
```

---

## RET

### Description

Retour de sous-routine.

---

### Encodage

```txt
23h
```

---

### Taille

```txt
1 octet
```

---

# Arithmétique

---

## INC

### Description

Incrémente un registre.

---

### Format

```asm
INC A
```

---

### Encodage

```txt
30h

Byte 0 : Opcode

Byte 1 : Registre
```

---

### Taille

```txt
2 octets
```

---

### FLAGS affectés

```txt
ZERO
NEGATIVE
OVERFLOW
```

---

## DEC

### Description

Décrémente un registre.

---

### Format

```asm
DEC A
```

---

### Encodage

```txt
31h

Byte 0 : Opcode

Byte 1 : Registre
```

---

### Taille

```txt
2 octets
```

---

### FLAGS affectés

```txt
ZERO
NEGATIVE
OVERFLOW
```

---

## ADD

### Description

Addition de deux registres.

---

### Format

```asm
ADD A, B
```

---

### Encodage

```txt
32h

Byte 0 : Opcode

Byte 1 : Destination

Byte 2 : Source
```

---

### Taille

```txt
3 octets
```

---

### FLAGS affectés

```txt
ZERO

CARRY

NEGATIVE

OVERFLOW
```

---

## SUB

### Description

Soustraction de deux registres.

---

### Format

```asm
SUB A, B
```

---

### Encodage

```txt
33h

Byte 0 : Opcode

Byte 1 : Destination

Byte 2 : Source
```

---

### Taille

```txt
3 octets
```

---

### FLAGS affectés

```txt
ZERO

CARRY

NEGATIVE

OVERFLOW
```

---

# Comparaisons et branchements

---

## CMP

### Description

Compare deux registres.

---

### Format

```asm
CMP A, B
```

---

### Encodage

```txt
40h

Byte 0 : Opcode

Byte 1 : Registre A

Byte 2 : Registre B
```

---

### Taille

```txt
3 octets
```

---

### FLAGS affectés

```txt
ZERO

NEGATIVE

CARRY
```

---

## JMP

### Description

Saut inconditionnel.

---

### Format

```asm
JMP Adresse
```

---

### Encodage

```txt
41h

Byte 0 : Opcode

Byte 1 : Adresse Low

Byte 2 : Adresse High
```

---

### Taille

```txt
3 octets
```

---

## JZ

### Description

Saut si Zero Flag activé.

---

### Format

```asm
JZ Adresse
```

---

### Encodage

```txt
42h

Byte 0 : Opcode

Byte 1 : Adresse Low

Byte 2 : Adresse High
```

---

### Taille

```txt
3 octets
```

---

## JNZ

### Description

Saut si Zero Flag désactivé.

---

### Format

```asm
JNZ Adresse
```

---

### Encodage

```txt
43h

Byte 0 : Opcode

Byte 1 : Adresse Low

Byte 2 : Adresse High
```

---

### Taille

```txt
3 octets
```

---

# Tableau des opcodes

| Opcode | Instruction |
|----------|----------|
| 00h | NOP |
| 10h | MOV |
| 11h | LOAD |
| 12h | STORE |
| 20h | PUSH |
| 21h | POP |
| 22h | CALL |
| 23h | RET |
| 30h | INC |
| 31h | DEC |
| 32h | ADD |
| 33h | SUB |
| 40h | CMP |
| 41h | JMP |
| 42h | JZ |
| 43h | JNZ |
| FFh | HLT |

---

# Priorité d'implémentation

Ordre recommandé :

```txt
1. MOV

2. LOAD
   STORE

3. PUSH
   POP

4. CALL
   RET

5. INC
   DEC

6. ADD
   SUB

7. CMP

8. JMP
   JZ
   JNZ
```

---

# Objectif de la v0.0.3

À la fin de la v0.0.3, Azure-8 devra être capable d'exécuter :

```asm
LOAD A, 1000h

LOAD B, 1001h

ADD A, B

STORE A, 2000h

HLT
```

Ce programme représente le premier objectif minimal d'une architecture Azure-8 réellement programmable.