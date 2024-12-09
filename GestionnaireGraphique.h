#pragma once

#include <SFML/Graphics.hpp>
#include "Grille.h"
#include <vector>

class GestionnaireGraphique {
private:
    sf::Font police;
    sf::Text titre;
    sf::Texture textureFond;
    sf::Sprite spriteFond;
    std::vector<sf::Text> textes;
    int tailleCellule;
    bool menuActif;

public:
    GestionnaireGraphique(int tailleCellule = 20);

    void ajouterBouton(const std::string& texte, int posX, int posY);
    void chargerImageDeFond(const std::string& cheminImage);
    void afficherMenu(sf::RenderWindow& fenetre);
    int gererEvenements(sf::RenderWindow& fenetre);
    void fermer(sf::RenderWindow& fenetre);
    void afficherGrille(const Grille& grille, sf::RenderWindow& fenetre);
};

