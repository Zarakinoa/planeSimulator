---
title: Projet L3 IN505 Groupe 2
author: Soufiane Chikar Théo Lefebvre
---

# Plane Simulator

Nous avons utilisé Visual Studio Code pour développer notre application. Nous avons choisi cet IDE car nous avons pu déjà expérimenté le logiciel et qu'il est complet.
Nos bibliothèque de programmation sont Raylib pour l'interface et Json pour la gestion des pilotes et de l'historique.

## raylib

[Raylib](https://www.raylib.com/) est une librairie graphique C/C++ qui permet de crée notre interface et de la manipuler.
Elle est fortement inspiré de la bibliothèque graphique Borland BGI et du framework XNA.

C'est une bibliothèque de programmation pour profiter de la programmation de jeux vidéo;
pas d'interface sophistiquée, pas d'aides visuelles, pas de débogage automatique.

![Fonctionnalités de raylib](https://www.raylib.com/images/raylib_architecture_v2.5.png)

## Json

[nlohmann/json](https://github.com/nlohmann/json) est une librairie C++ qui permet de manipuler les fichier json.
Nous l'avons utilisé pour lire et ecrire les taches du pilote faites sur notre Application pour en faire un historique.
Nous aurions pu utiliser un simple fichier mais on serai trop restreint.

## Paquets Requis

Pour construire votre raylib sur GNULinux, vous devez télécharger le dépôt git de raylib. raylib est déjà livré avec des makefiles prêts à l'emploi et le système CMake pour compiler le code source, les exemples et les modèles. ce guide est destiné à toutes les distributions GNULinux, notez simplement qu'APT est utilisé comme gestionnaire de paquets pour les distributions basées sur Debian.

```
sudo apt install cmake
sudo apt install build-essential git
sudo apt-get install -y nlohmann-json-dev
sudo apt install libasound2-dev mesa-common-dev libx11-dev libxrandr-dev libxi-dev xorg-dev libgl1-mesa-dev libglu1-mesa-dev
```

## Build Raylib

Téléchargez le dépôt raylib depuis [Github](https://github.com/raysan5/raylib), puis compilez le avec :

```
git clone https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP RAYLIB_LIBTYPE=SHARED
```

## Execution du projet

```
make
```

La connexion à l'interface ce fait avec user et pass.

## Manuel

Vous trouverez le manuel de notre projet dans le dossier "latex/" ecrit avec Doxygen.

## Arhictecure

Afin de pouvoir développer en binome sans encombre, nous avons décidé de nous répartir les tâches. Cela a permis un gain de temp et de développer simultanément des fonctionnalités différentes. Lors de chaque nouvelle fonctionnalité nous fusionnions les parties développées séparément pour n'en faire qu'une seule, afin de pouvoir retravailler de nouvelles fonctionnalités sur un modèle commun.

Il a été obligatoire de choisir une structure pour notre projet. Ce fût là première chose sur laquelle nous nous sommes penchés avons d'entrer dans le vif du sujet.
Etant donné qu'il était demandé un système de connexion à une base de données, ainsi qu'une fonctionnalité d'exercices et un historique, nous avons décidé d'élaborer un menu, ainsi qu'un système multi-fenêtres pour que l'utilisateur dispose de la meilleure navigation possible lors de l'utilisation de l'application.
Pour cela, nous avon utilisé une notion très connue pour le monde du jeu vidéo, particulièrement pour le C++, il s'agit des patrons de conception (design pattern).
Dans notre cas, nous avons utilisé les patrons d'état (pattern state), qui était le choix le plus judicieux pour pouvoir naviguer entre chaque fenêtre.
Chaque fenêtre représente un état qui dérive de la classe abstraite State. Nous gardons au sein de notre class App un état courant permettant de savoir dans quel état (fenêtre) l'on se trouve, et d'appliquer une méthode run sur celui-ci tant que nous ne quittons pas l'application.
Grâce au pattern state, nous avons pu éviter les problêmes de boucles infinies imbriquées (dû à la conception de Raylib), celles-ci auraient créé trop de textures en peu de temp et auraient fait planter le programme.
Ici, nous avons une seule boucle infinie, qui est présente dans la classe App, celle-ci lance la méthode run() sur l'état courant, permettant de faire fonctionner le programme et d'afficher les graphismes.

Ensuite, nous avons développé de la plus petite entité (Moteur,Pompe..) j'usqu'à la plus grande (Systeme de carburant, tableau de bord..), car les plus grandes nécessitaient les plus petites.
Chaque classe avait des propriétés communes, telles qu'un état pour beaucoup d'entre elles, pour que le projet soit le plus lisible possible nous avons utilisé des énumérations pour représenter chaque état (Vide, Plein, Panne..).

Nous avons ensuite créé une classe dérivant de la classe State, qui representerait la fenêtre pour l'entrainement du pilote.
Nous l'avons appelé Game, elle ne possède que 2 attributs, FuelSystem (système de carburant) et DashBoard (tableau de bord).
Lorsque l'état courant sera de type Game, celui la appliquera la mise à jour des valeurs et des graphismes des deux objets qui la composent.

Nous avons ensuite développé une classe abstraite pour mettre en oeuvre les systèmes de reconfiguration demandée.
Etant donné que les reconfigurations ont un effet sur les réservoirs, pompes et les moteurs, le choix le plus adapté était de créer une classe Pipe (Tuyaux) qui reliait tous ces objets.
Il y a donc 2 classes qui dérivent de la classe Pipe:

- PipeTanktoTank = permet de remplir un réservoir à partir d'un autre réservoir.
- PipetanktoMotor = permet d'utliser les pompes secondaires en cas de panne, et d'alimenter un moteur à partir d'un autre réservoir.

Afin de gérer la reconfiguration pour l'alimentation des differents moteur, nous avons implémenter une table de hashage (std::map) permettant de liée un moteur à un réservoir en fonction de la valve utilisé.
Ainsi lorsqu'un action est faite sur une vanne, nous pourrons mettre à jour le bon réservoir et le bon moteur grâce à la table de hashage.

Lors de chaque tour de boucle, une méthode run() sera appliqué pour chaque tuyau, mettant à jour les capacités des réservoirs, la pompe qui alimente chaque moteur, l'état de chaque moteur,etc.

Lorsque chaque réservoir est vide, c'est la fin de partie, puis nous pouvons en relancer une immédiatement grâce au pattern state, sans avoir à quitter l'application et à se reconnecter.
