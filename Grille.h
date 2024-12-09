#pragma once

#include <vector>
#include <string>
#include "Cellule.h"

class Grille {
protected:
    int largeur; 
    int hauteur; 
    std::vector<std::vector<Cellule>> cellules; 

public:
    Grille(int largeur, int hauteur);
    int getLargeur() const;
    int getHauteur() const;
    Cellule& getCellule(int x, int y);
    const Cellule& getCellule(int x, int y) const;
    void chargerDepuisFichier(const std::string& fichier);
    void afficher() const;
    void calculerProchainEtat();
    void actualiserEtat();
};

