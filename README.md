# Git Intro Project

Simple Shell - Holberton School Project
Un interpréteur de commandes simple écrit en C, conforme aux standards Betty.
Description
Ce projet implémente un shell Unix basique capable d'exécuter des commandes, gérer le PATH, et inclut plusieurs commandes intégrées (builtins).
Compilation
bashgcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Utilisation
Mode interactif
bash$ ./hsh
$ ls -l
$ pwd
$ exit
Mode non-interactif
bash$ echo "ls" | ./hsh
$ cat commands.txt | ./hsh
Fonctionnalités par Task
Task 0 : Betty would be proud

✅ Code conforme au style Betty
✅ Pas d'erreurs, pas de warnings

Task 1 : Simple shell 0.1

✅ Afficher un prompt et attendre une commande
✅ Exécuter des commandes simples (sans arguments)
✅ Gestion des erreurs
✅ Gestion de EOF (Ctrl+D)

Task 2 : Simple shell 0.2

✅ Gestion du PATH
✅ Ne pas appeler fork si la commande n'existe pas

Task 3 : Simple shell 0.3

✅ Builtin exit
✅ Ne gère pas les arguments pour exit

Task 4 : Simple shell 0.4

✅ Builtin env
✅ Affiche l'environnement actuel

Task 5 : Simple shell 1.0

✅ Builtin setenv VARIABLE VALUE
✅ Builtin unsetenv VARIABLE
✅ Builtin cd [DIRECTORY]

Structure des fichiers
main.h           - Header avec prototypes et structures
main.c           - Point d'entrée (boucle principale)
read_line.c      - Lecture de l'entrée avec getline()
split_line.c     - Découpage en tokens
execute.c        - Dispatch des commandes
launch.c         - Fork et execve
get_path.c       - Recherche dans PATH
builtins.c       - exit, env, cd
builtins2.c      - setenv, unsetenv
env.c            - Gestion de l'environnement
helpers.c        - Fonctions string personnalisées
Commandes intégrées (Builtins)
CommandeDescriptionExempleexitQuitter le shellexitenvAfficher l'environnementenvsetenvDéfinir une variablesetenv VAR valueunsetenvSupprimer une variableunsetenv VARcdChanger de répertoirecd /tmp
Tests
bash# Test Task 1 - Commandes simples
./hsh
$ /bin/ls
$ /bin/pwd

# Test Task 2 - PATH
$ ls
$ pwd
$ echo "Hello"

# Test Task 3 - exit
$ exit

# Test Task 4 - env
$ env

# Test Task 5 - setenv/unsetenv
$ setenv MY_VAR test_value
$ env | grep MY_VAR
$ unsetenv MY_VAR
$ cd /tmp
$ pwd
Vérification Betty
bashbetty *.c *.h
Auteurs
Projet réalisé pour Holberton School
Notes importantes

Utilise getline() pour la lecture
Utilise strtok() pour le découpage
Gestion propre de la mémoire (pas de fuites)
Compatible avec les checkers Holberton
Code 100% conforme Betty
