# Azure-8 — inventaire statique ROM, VS Code et Type.h

**Périmètre :** inspection de 17 fichiers `*.rom`, `c_cpp_properties.json`, `launch.json`, `tasks.json`, `Type.h` et recoupement avec les sources déjà transmises. Les configurations ont été parsées comme JSON; aucun build, test, ROM ou lancement débogueur n'a été effectué. Les conclusions de décodage ci-dessous sont statiques.

## ROMs examinées

Les adresses LOAD/STORE/CALL sont low puis high; codes registres 00=A, 01=B. « Attendu » reste une déduction du code/octet, non un résultat exécuté.

| Fichier | Octets hex | Lecture statique |
|---|---|---|
| `nop.rom` | `00 00 00 00 FF` | quatre NOP puis HLT |
| `halt.rom` | `FF` | HLT |
| `invalid.rom` | `42` | opcode absent du switch; chemin défaut UNKNOWN OPCODE/halt |
| `mov.rom` | `10 00 01 FF` | MOV A,B puis HLT; après reset, transfert de zéro ne démontre pas un transfert non nul |
| `load.rom` | `11 00 00 10 FF` | LOAD A,[1000h] puis HLT; image seule ne vérifie pas le résultat |
| `store.rom` | `12 00 00 10 FF` | STORE A,[1000h] puis HLT; aucun readback/contrôle dans l'image |
| `push.rom` | `20 00 FF` | PUSH A puis HLT; aucun contrôle encodé |
| `pop.rom` | `21 01 FF` | POP B puis HLT; dans le flux Reset→LoadROM→Run fourni, pop à pile vide déclenche underflow/halt avant HLT |
| `call.rom` | `22 04 00 FF FF` | CALL 0004h; cible = HLT; pas de RET |
| `ret.rom` | `22 04 00 FF 23` | CALL 0004h; cible RET; retour attendu 0003h où se trouve HLT |
| `inc.rom` | `30 00 FF` | INC A puis HLT; après reset, valeur attendue par inspection = 1 |
| `dec.rom` | `31 00 FF` | DEC A puis HLT; après reset, valeur attendue = FFh; `main.cpp` prépare plutôt A=42 avant Run |
| `memory16.rom` | `FF` | HLT uniquement, pas d'accès mémoire 16 bits |
| `stack8.rom` | `FF` | HLT uniquement, pas d'opération de pile |
| `stack16.rom` | `FF` | HLT uniquement, pas de scénario PUSH16/POP16 |
| `overflow.rom` | `FF` | HLT uniquement, pas de débordement déclenché |
| `underflow.rom` | `FF` | HLT uniquement, pas de sous-flux déclenché |

`halt.rom`, `memory16.rom`, `overflow.rom`, `stack16.rom`, `stack8.rom` et `underflow.rom` ont tous le seul octet FFh. Le nom de fichier n'est pas preuve d'un scénario de test.

## Configurations VS Code

- `c_cpp_properties.json`: profil IntelliSense nommé `Win32`, `cl.exe`, mode `windows-msvc-x64`, standards C17/C++17, includes sous `${workspaceFolder}/src`, `src/Core`, `src/Azure8`.
- `tasks.json`: tâches Build Debug, Build Release, Build Tests; appel MSVC `cl`, C++17. Les fichiers attendus sont sous `src/` et `tests/`; sorties `build\obj\` et `build\...exe`. Les tâches ne semblent pas créer les dossiers de sortie.
- `launch.json`: profil `cppvsdbg` « Debug AzureEngine », exécutable attendu `${workspaceFolder}\build\AzureEngine.exe`, sans `preLaunchTask`; suppose un binaire déjà construit et environnement compatible.

Les trois fichiers ont été lus par `json.loads` et sont syntaxiquement valides. Cela ne valide pas l'existence des chemins, `cl.exe`, le débogueur, la compilation ou l'exécution.

## Type.h et structure

Le fichier fourni (169 octets) inclut `<cstdint>` et définit `u8=uint8_t`, `u16=uint16_t`, `u32=uint32_t`, `s8=int8_t`, `s16=int16_t`, `s32=int32_t`. Il est présent dans le lot; l'affirmation antérieure qu'il manquait est corrigée. Cependant, les fichiers remis sont aplatis et le fichier se trouve à la racine de ce lot, alors que les headers incluent `../Core/Type.h`. Présence du contenu confirmée, résolution du chemin dans l'arborescence projet non établie.

Le harness reçu est `main(1).cpp`; la tâche de test attend `tests\main.cpp`. Ne pas inférer que les deux sont mêmes fichiers ou que les chemins projet existent. Voir [Build](Build.md).

## Conclusion de preuve

Les ROMs sont des données statiquement examinées, non exécutées. Les configurations sont syntaxiquement valides mais restent des hypothèses d'environnement et d'arborescence. Cela ne modifie pas l'absence de preuve de build, tests et exécution.
