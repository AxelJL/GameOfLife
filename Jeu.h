#pragma once

#include "Grille.h"
#include "GestionnaireGraphique.h"

class Jeu {
private:
    Grille grille;
    int maxIterations;
    int iterationActuelle;
    bool modeGraphique;

public:
    Jeu(int largeur, int hauteur, int maxIterations, bool modeGraphique);
    void setGrille(const Grille& nouvelleGrille);
    Grille& getGrille();
    void demarrer();
    void afficherModeConsole();
    void choixMode();
    void lancerModeGraphique(GestionnaireGraphique& gestionnaire, sf::RenderWindow& fenetre);
};

