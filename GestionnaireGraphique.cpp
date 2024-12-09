#include "GestionnaireGraphique.h"
#include <iostream>

/* 
 * Constructeur de la classe GestionnaireGraphique.
 * Initialise la taille des cellules et charge la police pour l'affichage graphique.
 */
GestionnaireGraphique::GestionnaireGraphique(int tailleCellule)
    : tailleCellule(tailleCellule), menuActif(true) {
    if (!police.loadFromFile("assets/arial.ttf")) {
        throw std::runtime_error("[JDLV Manager]> Police pas charge");
    }

    titre.setFont(police);
    titre.setCharacterSize(36);
    titre.setFillColor(sf::Color::White);
    titre.setPosition(100, 50);
}

/* 
 * Ajoute un bouton au menu avec le texte spécifié à la position donnée.
 */
void GestionnaireGraphique::ajouterBouton(const std::string& texte, int posX, int posY) {
    sf::Text bouton;
    bouton.setFont(police);
    bouton.setString(texte);
    bouton.setCharacterSize(24);
    bouton.setFillColor(sf::Color::Black);
    bouton.setPosition(posX, posY);
    bouton.setOutlineColor(sf::Color::Black);
    textes.push_back(bouton);
}

/* 
 * Charge une image de fond pour l'interface graphique à partir du fichier spécifié.
 * Si le fichier n'est pas trouvé, un message d'erreur est affiché.
 */
void GestionnaireGraphique::chargerImageDeFond(const std::string& cheminImage) {
    if (!textureFond.loadFromFile(cheminImage)) {
        std::cerr << "[JDLV Manager]> Img pas charge" << cheminImage << std::endl;
    } else {
        spriteFond.setTexture(textureFond);
    }
}

/* 
 * Affiche le menu principal dans la fenêtre.
 */
void GestionnaireGraphique::afficherMenu(sf::RenderWindow& fenetre) {
    fenetre.clear(sf::Color::Black);
    fenetre.draw(spriteFond);
    fenetre.draw(titre);
    for (auto& texte : textes) {
        fenetre.draw(texte);
    }
    fenetre.display();
}

/* 
 * Gère les événements utilisateur (comme la fermeture de la fenêtre ou un clic sur un bouton).
 * Retourne l'indice du bouton cliqué ou -1 si aucun bouton n'a été cliqué.
 */
int GestionnaireGraphique::gererEvenements(sf::RenderWindow& fenetre) {
    sf::Event event;
    while (fenetre.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            fenetre.close();
            return -1;
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i posSouris = sf::Mouse::getPosition(fenetre);
            for (size_t i = 0; i < textes.size(); ++i) {
                sf::FloatRect zoneBouton = textes[i].getGlobalBounds();
                if (zoneBouton.contains(sf::Vector2f(posSouris))) {
                    return static_cast<int>(i);
                }
            }
        }
    }
    return -1;
}

/* 
 * Affiche la grille dans la fenêtre.
 * Chaque cellule est dessinée comme un carré, coloré en fonction de son état (vivante ou morte).
 */
void GestionnaireGraphique::afficherGrille(const Grille& grille, sf::RenderWindow& fenetre) {
    fenetre.clear(sf::Color::White);

    for (int y = 0; y < grille.getHauteur(); ++y) {
        for (int x = 0; x < grille.getLargeur(); ++x) {
            sf::RectangleShape cellule(sf::Vector2f(tailleCellule - 1, tailleCellule - 1));
            cellule.setPosition(x * tailleCellule, y * tailleCellule);

            if (grille.getCellule(x, y).estVivante()) {
                cellule.setFillColor(sf::Color::Green);
            } else {
                cellule.setFillColor(sf::Color::Black);
            }
            fenetre.draw(cellule);
        }
    }
    fenetre.display();
}


/* 
 * Ferme la fenêtre graphique.
 */
void GestionnaireGraphique::fermer(sf::RenderWindow& fenetre) {
    fenetre.close();
}
