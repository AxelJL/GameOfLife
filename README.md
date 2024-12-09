# Jeu de la vie 

Ce projet implémente un jeu de simulation cellulaire en C++ utilisant la bibliothèque SFML pour l'affichage graphique. Le jeu est basé sur un système de cellules qui évoluent au fil du temps selon des règles simples, similaires au jeu "Conway's Game of Life". Le programme offre à la fois un mode console et un mode graphique pour visualiser l'évolution de la grille de cellules.

## Structure du projet

### Classes principales

1. **`Cellule`**
   - Représente une cellule individuelle dans la grille.
   - Chaque cellule peut être dans un état "vivante" ou "morte", et son état évolue à chaque itération du jeu.
   - Les méthodes principales incluent :
     - `estVivante()`: Vérifie si la cellule est vivante.
     - `estObstacle()`: Vérifie si la cellule est un obstacle.
     - `calculerEtatProchain()`: Calcule l'état suivant de la cellule en fonction du nombre de voisins vivants.
     - `actualiserEtat()`: Met à jour l'état de la cellule.

2. **`Grille`**
   - Représente la grille de cellules, qui est une matrice de cellules vivantes ou mortes.
   - Gère la logique des règles de simulation.
   - Les méthodes principales incluent :
     - `getCellule()`: Accède à une cellule spécifique de la grille.
     - `setCellule()`: Modifie une cellule spécifique.
     - `compterVoisinsVivants()`: Compte le nombre de cellules vivantes autour d'une cellule donnée.

3. **`GestionnaireGraphique`**
   - Gère l'interface graphique du jeu, en utilisant la bibliothèque SFML.
   - Affiche la grille de cellules, les menus, et gère les événements utilisateur.
   - Les méthodes principales incluent :
     - `ajouterBouton()`: Ajoute un bouton à l'écran.
     - `chargerImageDeFond()`: Charge une image de fond.
     - `afficherMenu()`: Affiche le menu du jeu.
     - `gererEvenements()`: Gère les événements clavier et souris.
     - `afficherGrille()`: Affiche la grille de cellules à l'écran.

4. **`Jeu`**
   - Le contrôleur principal qui orchestre la logique du jeu.
   - Gère les itérations du jeu et bascule entre le mode console et graphique.
   - Les méthodes principales incluent :
     - `setGrille()`: Définit la grille du jeu.
     - `getGrille()`: Récupère la grille du jeu.
     - `demarrer()`: Lance le jeu.
     - `afficherModeConsole()`: Affiche l'état du jeu en mode console.
     - `choixMode()`: Permet de choisir le mode (console ou graphique).
     - `lancerModeGraphique()`: Lance le jeu en mode graphique avec un gestionnaire graphique.

## Prérequis

Avant de pouvoir compiler et exécuter ce projet, vous devez avoir les éléments suivants installés :

- **C++** (version C++11 ou plus récente)
- **SFML** (Simple and Fast Multimedia Library) pour l'affichage graphique.
  - Vous pouvez installer SFML via [le site officiel](https://www.sfml-dev.org/download.php) ou via un gestionnaire de paquets comme `vcpkg` ou `brew`.

## Installation

### Cloner le repository

 

