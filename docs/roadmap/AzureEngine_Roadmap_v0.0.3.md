# AzureEngine Roadmap v0.0.3

> Version : **v0.0.3-alpha**
>
> Statut : **Préparation Release**
>
> Version précédente : **v0.0.2-alpha**
>
> Architecture : **CPU 8 bits / Adressage mémoire 16 bits**
>
> Progression : **95 %**
>
> État fonctionnel : **Terminé**
>
> État release : **En cours de validation**
>
> Objectif : **Préparer le tag Git v0.0.3-alpha**

---

# Présentation

La version v0.0.3-alpha marque l'achèvement fonctionnel du premier processeur programmable Azure‑8.

Tous les objectifs du jeu d'instructions ont été atteints et validés par tests automatisés et ROMs dédiées.

Cependant, avant de publier officiellement la release et de créer le tag Git correspondant, une phase finale de validation doit être réalisée :

```txt
Validation des ROMs héritées de la v0.0.2

Audit complet du code source

Audit complet de la documentation

Validation du dépôt

Validation Debug

Validation Release
```

---

# Objectifs atteints

## CPU

```txt
✅ Architecture CPU opérationnelle

✅ Fetch

✅ Decode

✅ Execute

✅ Jeu d'instructions v0.0.3 complet
```

---

## Registres utilisateur

```txt
✅ A

✅ B

✅ C

✅ D
```

---

## Registres système

```txt
✅ PC

✅ SP

✅ FLAGS
```

---

## Mémoire

```txt
✅ RAM 64 Ko

✅ Read8()

✅ Write8()

✅ Read16()

✅ Write16()

✅ Little Endian
```

---

## Stack

```txt
✅ Push8()

✅ Pop8()

✅ Push16()

✅ Pop16()

✅ Gestion du Stack Pointer
```

---

## FLAGS

```txt
✅ FLAG_ZERO

✅ FLAG_CARRY

✅ FLAG_NEGATIVE

✅ FLAG_OVERFLOW
```

---

# Jeu d'instructions Azure‑8 v0.0.3

## Contrôle CPU

```txt
✅ NOP (00h)

✅ HLT (FFh)
```

---

## Données

```txt
✅ MOV   (10h)

✅ LOAD  (11h)

✅ STORE (12h)
```

---

## Pile

```txt
✅ PUSH (20h)

✅ POP  (21h)

✅ CALL (22h)

✅ RET  (23h)
```

---

## Arithmétique

```txt
✅ INC (30h)

✅ DEC (31h)

✅ ADD (32h)

✅ SUB (33h)
```

---

## Comparaisons

```txt
✅ CMP (40h)
```

---

## Branchements

```txt
✅ JMP (41h)

✅ JZ  (42h)

✅ JNZ (43h)
```

---

# Lot A - Instructions de données

```txt
✅ MOV

✅ LOAD

✅ STORE
```

Validation :

```txt
✅ mov.rom

✅ load.rom

✅ store.rom
```

Statut :

```txt
✅ TERMINÉ
```

---

# Lot B - Pile avancée

```txt
✅ PUSH

✅ POP

✅ CALL

✅ RET
```

Validation :

```txt
✅ push.rom

✅ pop.rom

✅ call.rom

✅ ret.rom
```

Statut :

```txt
✅ TERMINÉ
```

---

# Lot C - Arithmétique

```txt
✅ INC

✅ DEC

✅ ADD

✅ SUB
```

Validation :

```txt
✅ inc.rom

✅ dec.rom

✅ add.rom

✅ sub.rom
```

Statut :

```txt
✅ TERMINÉ
```

---

# Lot D - Comparaisons et branchements

```txt
✅ CMP

✅ JMP

✅ JZ

✅ JNZ
```

Validation :

```txt
✅ cmp.rom

✅ jmp.rom

✅ jz.rom

✅ jnz.rom
```

Statut :

```txt
✅ TERMINÉ
```

---

# ROMs validées

## ROMs fondamentales

```txt
✅ nop.rom

✅ halt.rom

✅ invalid.rom
```

---

## ROMs d'instructions

```txt
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

✅ sub.rom

✅ cmp.rom

✅ jmp.rom

✅ jz.rom

✅ jnz.rom
```

---

# ROMs à valider avant publication

Ces ROMs ont été créées durant la v0.0.2 mais n'ont jamais bénéficié d'une validation ROM documentée.

## Lot E1 - ROMs d'infrastructure

```txt
⬜ memory16.rom

⬜ stack8.rom

⬜ stack16.rom

⬜ overflow.rom

⬜ underflow.rom
```

Objectif :

```txt
Validation par exécution réelle

Documentation des résultats

Archivage des preuves
```

---

# Tests automatisés

## Infrastructure

```txt
✅ TestMemory

✅ TestStack

✅ TestFlags

✅ TestCPU
```

---

## Instructions

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

✅ TestSUB

✅ TestCMP

✅ TestJMP

✅ TestJZ

✅ TestJNZ
```

Résultat :

```txt
AzureEngine Test Suite

All tests passed successfully.
```

---

# Lot E - Validation finale de release

## E1 - Validation ROM historique

```txt
⬜ memory16.rom

⬜ stack8.rom

⬜ stack16.rom

⬜ overflow.rom

⬜ underflow.rom
```

---

## E2 - Audit du code source

### Azure8

```txt
⬜ CPU.cpp

⬜ CPU.h

⬜ Memory.cpp

⬜ Memory.h

⬜ Emulator.cpp

⬜ Emulator.h
```

### Tests

```txt
⬜ TestCPU.cpp

⬜ TestFlags.cpp

⬜ TestMemory.cpp

⬜ TestStack.cpp

⬜ Tous les TestInstruction*.cpp
```

Contrôles :

```txt
⬜ St*le

⬜ Cohérence

⬜ Commentaires

⬜*Nommage

⬜ Code mort

⬜ Warnings
`*`

---

## E3 - Audit de la docume*tation

### Développement

```txt
* Architecture.md

⬜ Build.md

⬜ Co*ingStyle.md

⬜ Contributing.md
```*
### Technique

```txt
⬜ Documenta*ion FLAGS.md

⬜ Documentation SP.m*

⬜ Documentation Stack.md
```

##* Spécifications

```txt
⬜ Azure-8_*nstruction_Set_v0.0.3.md

⬜ Azure-*_Technical_Specification_v0.0.2.tx*
```

### Vision

```txt
⬜ Cohéren*e globale
```

---

## E4 - Valida*ion du dépôt

```txt
⬜ README.md

* LICENSE

⬜ .gitignore

⬜ Structur* du dépôt

⬜ ROMs

⬜ Documentation*
⬜ Arborescence
```

---

## E5 - *ompilation finale

### Debug

```t*t
⬜ Build réussi

⬜ 0 erreur

⬜ 0 *arning
```

### Release

```txt
⬜ *uild réussi

⬜ 0 erreur

⬜ 0 warni*g
```

---

## E6 - Publication

C*nditions :

```txt
✅ Jeu d'instruc*ions terminé

✅ Tests validés

⬜ R*Ms historiques validées

⬜ Documen*ation auditée

⬜ Code audité

⬜ Bu*ld Debug validé

⬜ Build Release v*lidé
```

Action finale :

```txt
*it tag v0.0.3-alpha
```

---

# Ét*t actuel

## Fonctionnalités

```t*t
✅ 100 %
```

## Tests

```txt
✅ *00 %
```

## ROMs d'instructions

*``txt
✅ 100 %
```

## Préparation *elease

```txt
🟨 95 %
```

---

#*Accomplissements majeurs

```txt
✅*Jeu d'instructions complet

✅ MOV
*✅ LOAD

✅ STORE

✅ PUSH

✅ POP

✅ *ALL

✅ RET

✅ INC

✅ DEC

✅ ADD

✅*SUB

✅ CMP

✅ JMP

✅ JZ

✅ JNZ

✅ *omparaisons

✅ Branchements condit*onnels

✅ Branchements incondition*els

✅ Sous-routines

✅ Tests auto*atisés complets

✅ Build fonctionn*l
```

---

# Résultat attendu ava*t clôture

Lorsque le Lot E sera t*rminé :

```txt
✅ Toutes les ROMs *alidées

✅ Documentation auditée

* Code source audité

✅ Dépôt valid*

✅ Build Debug

✅ Build Release

* 0 erreur

✅ 0 warning
```

Alors *eulement :

```txt
Statut : Termin*e

Progression : 100 %

Tag*Git : v0.0.3-alpha
``*

pourront être officiellement*appliqués.

---

# Bilan

La v0.0.**est fonctionnellement terminée.

L* processeur Azure‑8 est programmab*e et l'ensemble du jeu d'instructi*ns prévu par la spécification v0.0*3 est implémenté et valid*.

La phase restante concerne*exclusivement :

```txt
Qualité

*alidation

Documentation

Publicat*on*```

afin de produire une release *ropre et durable avant l'ouverture*officielle de la v0.0.4.

---

***in de roadmap v0.0.3-alpha - Statu*** Préparation Release*****