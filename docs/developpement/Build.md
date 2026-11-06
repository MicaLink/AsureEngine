# Build.md

# AzureEngine v0.0.1

Guide de compilation officiel.

---

# Présentation

AzureEngine est actuellement développé et testé sur :

- Windows 10
- Windows 11

Le support Linux arrivera dans une version ultérieure.

La version v0.0.1 ne nécessite aucune bibliothèque externe.

---

# Prérequis

## Outils requis

### Visual Studio Build Tools

Installer :

- MSVC
- Windows SDK

ou

### Visual Studio Community

Avec :

- Développement Desktop C++

---

# Vérification

Dans un terminal :

```cmd
cl
```

Vous devez obtenir :

```text
Microsoft (R) C/C++ Optimizing Compiler
```

---

# Structure du projet

```text
AzureEngine
│
├── .vscode
│
├── build
│   └── obj
│
├── docs
│
├── roms
│
├── src
│   ├── Azure8
│   └── main.cpp
│
└── tests
```

---

# Compilation manuelle

Depuis la racine du projet :

```cmd
cl /EHsc ^
src\\main.cpp ^
src\\Azure8\\CPU.cpp ^
src\\Azure8\\Memory.cpp ^
src\\Azure8\\Emulator.cpp ^
/Fobuild\\obj\\ ^
/Febuild\\AzureEngine.exe
```

---

# Compilation via VS Code

Le projet est configuré pour utiliser :

```text
.vscode/tasks.json
```

Compiler :

```text
Ctrl + Shift + B
```

Le résultat est généré dans :

```text
build/
```

Exécutable :

```text
build/AzureEngine.exe
```

Fichiers objets :

```text
build/obj/
```

---

# Lancement

Depuis un terminal :

```cmd
build\\AzureEngine.exe
```

Exemple :

```cmd
build\\AzureEngine.exe roms\\test.rom
```

---

# Nettoyage

Supprimer :

```text
build/
```

ou uniquement :

```text
build/obj/
```

pour forcer une recompilation complète.

---

# Mode Debug

Pour le moment le mode Debug s'effectue via :

```cpp
printf()
```

et

```cpp
std::cout
```

Exemple :

```cpp
printf(
    "PC=%04X OPCODE=%02X\n",
    cpu.PC,
    opcode);
```

---

# Tests

Les tests unitaires seront placés dans :

```text
tests/
```

Structure prévue :

```text
tests
├── CPU
├── Memory
└── Emulator
```

---

# Conventions de compilation

Le projet doit compiler :

- sans warning critique ;
- sans dépendances tierces ;
- avec MSVC.

La version v0.0.1 utilise uniquement :

- C++
- Bibliothèque standard

Aucune dépendance externe n'est autorisée.

---

# Dépannage

## erreur : cl non reconnu

Ouvrir :

```text
Developer Command Prompt for Visual Studio
```

ou lancer :

```cmd
vcvars64.bat
```

avant compilation.

---

## build/obj introuvable

Créer :

```text
build
└── obj
```

manuellement.

---

# Version actuelle

Projet :

AzureEngine

Version :

0.0.1 Alpha

Plateforme :

Windows

Machine virtuelle :

Azure-8

Statut :

Développement initial