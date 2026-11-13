# Architecture AzureEngine / Azure-8

**Base : inspection statique de code et tests transmis. Build/tests : non exécutés.** Cette description ne ratifie pas une spécification architecturale.

## Composants

Les fichiers observés sont `CPU.h/.cpp`, `Memory.h/.cpp` et `Emulator.h/.cpp`. Le CPU détient A–D sur 8 bits, PC et SP sur 16 bits, FLAGS sur 8 bits, un état halted et des indicateurs d'erreur de pile. `Type.h` définit les alias `u8/u16/u32` et `s8/s16/s32` à partir de `<cstdint>`. Les headers CPU et Memory incluent `../Core/Type.h`; toutefois, le fichier Type.h reçu est à la racine du lot aplati et le chemin d'inclusion dans une arborescence restaurée n'est pas établi.

`Step` récupère un octet, avance PC puis décode l'opcode. Les sorties diagnostiques sont émises via `printf`. `Run` continue tant que le CPU n'est pas halted.

## Mémoire et chargement

`Memory` contient un tableau indexé par `u16`; le code de `Memory::Reset`, `Read8/Write8` et `Read16/Write16` indique une RAM de 65 536 octets et un format little-endian pour les mots. L'adressage suivant FFFFh reboucle dans les accès utilisant `u16`. Aucune protection de plage additionnelle n'est visible.

`Emulator::LoadROM` lit un binaire et en écrit le contenu dans la mémoire à partir de zéro. Le code examiné ne sépare pas mémoire ROM et RAM et ne protège pas l'image contre l'écriture. Le compteur d'adresse du chargeur est `u16`; aucune garde explicite contre une image trop grande n'est visible. `Emulator::Reset` remet mémoire et CPU à zéro/état initial; pour préserver l'image, Reset doit précéder LoadROM. `main.cpp` utilise cet ordre.

## Pile

La pile descendante utilise FE00h–FFFFh (512 octets), avec SP initialisé à FFFFh. Push8 écrit à `[SP]` puis décrémente; Pop8 incrémente puis lit, après contrôle des sentinelles. En cas d'erreur, le CPU signale l'indicateur correspondant et passe en halt. Push16/Pop16 enchaînent des opérations 8 bits sans atomicité ni rollback. Les détails sont décrits dans [Documentation Stack](Documentation%20Stack.md) et [Documentation SP](Documentation%20SP.md).

## Instructions visibles

Le switch CPU comprend NOP (00h), MOV (10h), LOAD (11h), STORE (12h), PUSH (20h), POP (21h), CALL (22h), RET (23h), INC (30h), DEC (31h), ADD (32h) et HLT (FFh). Le chemin par défaut signale `UNKNOWN OPCODE` et halt. SUB, CMP, JMP, JZ et JNZ ne sont pas dans le switch transmis. Voir [tableau ISA](../Specifications/Azure-8_Instruction_Set_v0.0.3.md).

Tout code de registre hors 00h–03h retourne actuellement A par `GetRegister`, sans erreur. INC/DEC/ADD modifient Z/N uniquement; voir [FLAGS](Documentation%20FLAGS.md).

## Limites de preuve

Ceci est une lecture statique des pièces du lot, pas un build, un test ou une exécution de ROM. Les cas frontières et les comportements souhaités ne sont pas nécessairement spécifiés. Arborescence du dépôt, chemins des includes, configuration effective du compilateur et publication/version restent à confirmer. Le dossier [audit](../README_Cohérence.md) explicite les limites.
