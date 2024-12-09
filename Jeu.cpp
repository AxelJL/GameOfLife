#include "Jeu.h"
#include <iostream>
#include <thread>
#include <chrono>

/*
 * Constructeur de la classe Jeu.
 * Initialise la grille, le nombre maximum d'itérations, l'itération actuelle et le mode graphique.
 */
Jeu::Jeu(int largeur, int hauteur, int maxIterations, bool modeGraphique)
    : grille(largeur, hauteur), maxIterations(maxIterations), iterationActuelle(0), modeGraphique(modeGraphique) {}

/*
 * Lance le jeu en mode console.
 * Affiche la grille et calcule le prochain état de la grille à chaque itération.
 */
void Jeu::demarrer() {
    for (iterationActuelle = 0; iterationActuelle < maxIterations; ++iterationActuelle) {
        afficherModeConsole();
        grille.calculerProchainEtat(); 
        grille.actualiserEtat(); 
    }
}

/*
 * Affiche la grille dans la console.
 * Affiche l'itération actuelle, puis l'état de la grille.
 */
void Jeu::afficherModeConsole() {
    std::cout << "Iteration: " << iterationActuelle << std::endl;
    std::cout << std::endl;
    grille.afficher(); // Affiche l'état actuel de la grille
    std::cout << std::endl;
}

/*
 * Définit une nouvelle grille.
 */
void Jeu::setGrille(const Grille& nouvelleGrille) {grille = nouvelleGrille;}

/*
 * Retourne la grille actuelle.
 */
Grille& Jeu::getGrille() {return grille;}

/*
 * Lance le jeu en mode graphique.
 * Affiche la grille et gère les événements de la fenêtre.
 * Lorsque le nombre maximum d'itérations est atteint, affiche l'état final de la grille.
 * gestionnaire Le gestionnaire graphique pour afficher la grille.
 * fenetre La fenêtre SFML où la grille sera dessinée.
 */
void Jeu::lancerModeGraphique(GestionnaireGraphique& gestionnaire, sf::RenderWindow& fenetre) {
    bool grilleFinaleAffichee = false; 
    while (fenetre.isOpen()) {
        sf::Event event;
        while (fenetre.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                fenetre.close(); 
            }
        }

        if (iterationActuelle < maxIterations) {
            std::cout << "Iteration: " << iterationActuelle << std::endl; 
            gestionnaire.afficherGrille(grille, fenetre); 
            grille.calculerProchainEtat();
            grille.actualiserEtat(); 
            ++iterationActuelle; 

            std::this_thread::sleep_for(std::chrono::milliseconds(300));
        } else if (!grilleFinaleAffichee) {
            std::cout << "[JDLV Manager]> Etat final atteint, affichage de la grille finale." << std::endl;
            gestionnaire.afficherGrille(grille, fenetre); // Affiche la grille finale
            grilleFinaleAffichee = true; 
        }
    }
}
