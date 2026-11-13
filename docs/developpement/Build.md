# Compilation, tests et exécution — AzureEngine

**Aucune compilation, suite de tests, ROM ou session de débogage n'a été exécutée pour cette révision.** Les éléments ci-dessous décrivent les fichiers remis et leurs préconditions, pas une procédure validée.

## Configuration fournie

`.vscode/tasks.json` contient les tâches `Build Debug`, `Build Release` et `Build Tests`, toutes appelant `cl` avec `/std:c++17`; `c_cpp_properties.json` configure IntelliSense MSVC (`cl.exe`, profil nommé `Win32`, mode `windows-msvc-x64`); `launch.json` vise `build\AzureEngine.exe` via `cppvsdbg`. Le lancement ne déclare pas de `preLaunchTask`. Ces valeurs ne prouvent pas la disponibilité de MSVC ou l'existence des chemins.

Les tâches attendent une arborescence comme `src/main.cpp`, `src/Azure8/{CPU,Memory,Emulator}.cpp`, `src/Core/Type.h` et `tests/main.cpp` avec les fichiers `tests/Test*.cpp`. Les pièces remises sont aplaties : `main.cpp`, `main(1).cpp`, les sources et `Type.h` sont à la racine du lot. Les headers incluent `../Core/Type.h`; résolution des inclusions non vérifiée. `main(1).cpp` n'est pas à lui seul la preuve d'une correspondance au `tests/main.cpp` attendu.

Les options de sortie des tâches visent `build\obj\` et `build\...exe`; les tâches ne créent pas visiblement les dossiers nécessaires. Prérequis à confirmer.

## Contraintes visibles

Le guide de configuration cible Windows/MSVC. `Emulator.cpp` utilise `fopen_s`; la portabilité hors MSVC n'est pas établie. `main.cpp` utilise `roms/dec.rom`; le lancement réel dépend du répertoire courant et de la présence de cette ROM. Aucun système de build autre que ces tâches fournies n'est constaté.

## Tests présents

Le harness livré appelle les tests de mémoire 8/16 bits, pile 8/16 bits, quatre helpers FLAGS, MOV/LOAD/STORE/PUSH/POP/CALL/RET/INC/DEC/ADD et Reset. Les fichiers source ne sont pas des résultats d'exécution. Ne pas prendre le texte final du harness pour une trace de réussite produite pendant cette révision.

Pour valider réellement : restaurer l'arborescence, les dépendances et chemins attendus, créer les répertoires de sortie, vérifier l'environnement MSVC, construire séparément application et harness, exécuter les tests avec assertions actives, puis archiver commande, code de retour et sortie. Ajouter les cas frontières décrits dans la documentation pile/FLAGS.