# AzureEngine — inventaire et cohérence documentaire

**Révision documentaire : 13 novembre 2026.** Les constats ci-dessous proviennent des fichiers transmis et de l'inspection statique décrite ici; ils ne valent pas audit de dépôt Git ou validation dynamique.

## Contenu produit

- [`README.md`](../README.md), `LICENSE`, `.gitignore` à la racine.
- Documentation développeur : Architecture, Build, CodingStyle, Contributing, FLAGS, SP, Stack, et mise à jour de preuve ROM/VS Code.
- Spécifications : historique technique v0.0.1, note factuelle v0.0.2, inventaire ISA portant le nom v0.0.3.
- Roadmaps historiques v0.0.1, v0.0.2 et inventaire/propositions v0.0.3.

Les chemins relatifs des fichiers listés ci-dessus suivent les liens du README. Les trois documents d'origine `.vscode` ne sont pas recopiés/modifiés dans l'ensemble documentaire; leurs contenus sont décrits dans le relevé de preuve.

## Base examinée

Sources : `CPU.cpp/.h`, `Memory.cpp/.h`, `Emulator.cpp/.h`, `main.cpp`, `main(1).cpp`, `Type.h`, fichiers `Test*.cpp`; artefacts : 17 ROMs et trois fichiers VS Code. Documents antérieurs disponibles : README, LICENSE, .gitignore, Architecture, Build, CodingStyle, Contributing, FLAGS, SP, Stack, spécifications et roadmaps. Le lot reçu est aplati, pas une arborescence restaurée.

## Cohérence et limites

Les docs séparent désormais observations du code, récits historiques et propositions. Les versions/tags/publications contradictoires et coches de validation ne sont pas certifiés. ADD existe dans le code remis malgré une roadmap historique qui le disait non commencé. Les effets de flags décrits par l'ancien draft sont corrigés : INC/DEC/ADD modifient Z/N seulement. Plusieurs ROMs de mémoire/pile/erreurs sont HLT seules. `Type.h` est bien fourni, mais le chemin d'inclusion attendu n'est pas restauré.

Le texte MIT et l'attribution de LICENSE étaient présents dans la pièce originale et ont été conservés. Les règles .gitignore d'origine sont conservées, sans exclusion des sources ni des ROMs.

## Vérifications effectuées

- Inspection statique de la logique C++ décrite dans Architecture/ISA/pile/FLAGS.
- Hex dumps des 17 ROMs consignés dans le relevé ROM/VS Code.
- Les trois configurations `.vscode` fournies ont été parsées en JSON valide.
- Vérification des liens relatifs vers les documents inclus lors de la génération documentaire.

**Aucun build, test, lancement de ROM ou session de débogage n'a été réalisé.** Les validations effectuées ne démontrent ni compilabilité, ni disponibilité des outils, ni succès d'exécution. Les sources C++ n'ont pas été modifiées.
