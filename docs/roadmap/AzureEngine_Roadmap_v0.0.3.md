# AzureEngine Roadmap v0.0.3

> Version cible : **v0.0.3-alpha**
>
> Statut : **En développement**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **75 %**
>
> Priorité actuelle : **SUB (0x33)**
>
> Lot actif : **Lot C - Arithmétique**

---

# Présentation

La version v0.0.3-alpha poursuit la transformation d'Azure‑8 en un processeur programmable complet.

Les fondations majeures sont maintenant terminées :

```txt
✅ Registres

✅ Mémoire

✅ Pile

✅ Sous-routines

✅ Arithmétique élémentaire

✅ Chargement ROM

✅ Tests automatisés
```

Azure‑8 peut désormais :

```txt
Lire la mémoire

↓

Manipuler des données

↓

Utiliser la pile

↓

Exécuter des sous-routines

↓

Effectuer des opérations arithmétiques
```

---

# Jeu d'instructions validé

## Système

```txt
00h NOP

FFh HLT
```

---

## Données

```txt
10h MOV

11h LOAD

12h STORE
```

---

## Pile

```txt
20h PUSH

21h POP

22h CALL

23h RET
```

---

## Arithmétique

```txt
30h INC

31h DEC

32h ADD
```

---

# Infrastructure validée

```txt
✅ RAM 64 Ko

✅ Read8()
✅ Write8()

✅ Read16()
✅ Write16()

✅ Push8()
✅ Pop8()

✅ Push16()
✅ Pop16()

✅ Stack Pointer

✅ Program Counter

✅ FLAGS

✅ ROM Loader

✅ Debug

✅ Tests automatisés
```

---

# État des lots

```txt
✅ Lot A - Instructions de données

✅ Lot B - Pile avancée

🟨 Lot C - Arithmétique

⬜ Lot D - Comparaisons et branchements

⬜ Lot E - Documentation

⬜ Lot F - Finalisation v0.0.3
```

---

# Lot A - Instructions de données

## Validation

```txt
✅ MOV

✅ LOAD

✅ STORE
```

## ROMs validées

```txt
✅ mov.rom

✅ load.rom

✅ store.rom
```

## Statut

```txt
✅ TERMINÉ
```

---

# Lot B - Pile avancée

## Validation

```txt
✅ PUSH

✅ POP

✅ CALL

✅ RET
```

## ROMs validées

```txt
✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom
```

## Validation obtenue

```txt
✅ Push8()

✅ Pop8()

✅ Push16()

✅ Pop16()

✅ Sous-routines

✅ Sauvegarde adresse de retour

✅ Retour à l'appelant
```

## Statut

```txt
✅ TERMINÉ
```

---

# Lot C - Arithmétique

## Objectif

Ajouter les capacités de calcul fondamentales.

---

## INC

### Opcode

```txt
30h
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ FLAGS

✅ TestINC

✅ inc.rom
```

### Statut

```txt
✅ TERMINÉ
```

---

## DEC

### Opcode

```txt
31h
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ FLAGS

✅ TestDEC

✅ dec.rom
```

### Statut

```txt
✅ TERMINÉ
```

---

## ADD

### Opcode

```txt
32h
```

### Fonction

```asm
ADD A, B
```

### Validation

```txt
✅ Opcode

✅ Décodage

✅ Exécution

✅ Lecture source

✅ Lecture destination

✅ Écriture résultat

✅ TestADD

✅ add.rom
```

### Validation ROM

```txt
A = 10

B = 32

↓

ADD A, B

↓

A = 42
```

### Statut

```txt
✅ TERMINÉ
```

---

## SUB

### Opcode

```txt
33h
```

### Fonction

```asm
SUB A, B
```

### Validation

```txt
⬜ Opcode

⬜ Décodage

⬜ Exécution

⬜ FLAG_ZERO

⬜ FLAG_NEGATIVE

⬜ FLAG_CARRY

⬜ FLAG_OVERFLOW

⬜ TestSUB

⬜ sub.rom
```

### Statut

```txt
🟨 PRIORITÉ ACTUELLE
```

---

## État du Lot C

```txt
✅ INC

✅ DEC

✅ ADD

⬜ SUB
```

Progression :

```txt
75 %
```

---

# Lot D - Comparaisons et branchements

## CMP

```txt
⬜ Implémentation

⬜ FLAGS

⬜ TestCMP

⬜ cmp.rom
```

---

## JMP

```txt
⬜ Implémentation

⬜ TestJMP

⬜ jmp.rom
```

---

## JZ

```txt
⬜ Implémentation

⬜ TestJZ

⬜ jz.rom
```

---

## JNZ

```txt
⬜ Implémentation

⬜ TestJNZ

⬜ jnz.rom
```

---

## Statut

```txt
⬜ NON COMMENCÉ
```

---

# ROMs validées

```txt
✅ nop.rom

✅ halt.rom

✅ invalid.rom

✅ mov.rom

✅ load.rom

✅ store.rom

✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom

✅ inc.rom

✅ dec.rom

✅ add.rom
```

---

# ROMs à créer

## Arithmétique

```txt
⬜ sub.rom
```

## Branchements

```txt
⬜ cmp.rom

⬜ jmp.rom

⬜ jz.rom

⬜ jnz.rom
```

---

# Tests automatisés validés

```txt
✅ TestMOV

✅ TestLOAD

✅ TestSTORE

✅ TestPUSH

✅ TestPOP

✅ TestCALL

✅ TestRET

✅ TestINC

✅ TestDEC

✅ TestADD
```

---

# Tests automatisés à réaliser

```txt
⬜ TestSUB

⬜ TestCMP

⬜ TestJMP

⬜ TestJZ

⬜ TestJNZ
```

---

# État actuel

```txt
Projet      : AzureEngine

Version     : v0.0.3-alpha

CPU         : 8 bits

PC          : 16 bits

SP          : 16 bits

FLAGS       : 8 bits

RAM         : 64 Ko

Progression : 75 %
```

---

# Accomplissements v0.0.3

```txt
✅ MOV

✅ LOAD

✅ STORE

✅ PUSH

✅ POP

✅ CALL

✅ RET

✅ INC

✅ DEC

✅ ADD

✅ 10 nouvelles instructions validées

✅ 10 tests automatisés validés

✅ 10 ROMs validées

✅ Gestion mémoire

✅ Gestion pile

✅ Sous-routines

✅ Arithmétique élémentaire
```

---

# Priorité immédiate

```txt
Lot C

1. SUB

2. TestSUB

3. sub.rom

4. Validation ROM
```

---

# Étape suivante

Une fois SUB terminé :

```txt
✅ INC

✅ DEC

✅ ADD

✅ SUB
```

le Lot C sera entièrement terminé.

Nous pourrons alors ouvrir :

```txt
Lot D

CMP

JMP

JZ

JNZ
```

et donner à Azure‑8 son premier véritable mécanisme de décision et de branchement conditionnel.

---

**Fin de roadmap v0.0.3-alpha**