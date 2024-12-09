#include "Cellule.h"
#include "Grille.h"
#include "Jeu.h"
#include "GestionnaireGraphique.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>

int main() {
    int nb_iterration;

    // Nombre d iterration
    std::cout<<"Choisir un nombre d iterration : ";
    std::cin >> nb_iterration;

    //Fichier d acces a la grille
    std::string cheminFichier;
    std::cout << "Entrez le chemin du fichier : ";
    std::cin >> cheminFichier;
        
    //Chargement du fichier
    std::ifstream fichier(cheminFichier);
    if (!fichier) {
        std::cerr << "Fichier introuvable !" << std::endl;
        exit(-1);
    }
   
    Jeu jeu(50, 30, nb_iterration, true); 

    int largeur, hauteur;
    fichier >> largeur >> hauteur;
    Grille grille(largeur, hauteur);
    grille.chargerDepuisFichier(cheminFichier);
    jeu.setGrille(grille);

    sf::RenderWindow fenetre(sf::VideoMode(1000, 600), "Jeu de la Vie");
    sf::Image icone;

    if (!icone.loadFromFile("assets/logo.png")) {
        std::cerr << "[JDLV Manager]> Icone pas charge" << std::endl;
        return -1;
    }
    fenetre.setIcon(icone.getSize().x, icone.getSize().y, icone.getPixelsPtr());

    GestionnaireGraphique gestionnaire;
    GestionnaireGraphique gesitonnaireRegles;
    GestionnaireGraphique gestionnaireCredit;
    GestionnaireGraphique gestionnaireJeu(30);
    gestionnaire.chargerImageDeFond("assets/background.png");

    // Ajout des boutons
    gestionnaire.ajouterBouton("Jouer en Console", 415, 100);
    gestionnaire.ajouterBouton("Jouer en Graphique", 415, 200);
    gestionnaire.ajouterBouton("Regles", 460, 300);
    gestionnaire.ajouterBouton("Credits", 460, 400);

    while (fenetre.isOpen()) {
        gestionnaire.afficherMenu(fenetre);
        int choix = gestionnaire.gererEvenements(fenetre);

        switch (choix) {

            case 0: {
                jeu.demarrer();
                exit(-1);
            }
            case 1: { // Jouer
                sf::RenderWindow fenetreJeu(sf::VideoMode(800, 600), "Jeu");

                jeu.lancerModeGraphique(gestionnaireJeu, fenetreJeu);

                while (fenetreJeu.isOpen()) {
                    gestionnaireJeu.afficherMenu(fenetreJeu);
                    int retour = gestionnaireJeu.gererEvenements(fenetreJeu);
                    if (retour == 0) {
                        fenetreJeu.close();
                    }
                }
                break;
            }
            
            case 2: { // Règles
                
                sf::RenderWindow fenetreRegles(sf::VideoMode(800, 600), "Regles");
                gesitonnaireRegles.chargerImageDeFond("assets/background_regles.png");
                gesitonnaireRegles.ajouterBouton("Retour", 350, 550);
                
                while (fenetreRegles.isOpen()) {
                    gesitonnaireRegles.afficherMenu(fenetreRegles);
                    int retour = gesitonnaireRegles.gererEvenements(fenetreRegles);
                    if (retour == 0) {
                        fenetreRegles.close();
                    }
                }
                break;
            }
            case 3: { // Crédits
                sf::RenderWindow fenetreCredits(sf::VideoMode(800, 600), "Credits");
                gestionnaireCredit.chargerImageDeFond("assets/background_credit.png");
                gestionnaireCredit.ajouterBouton("Retour", 350, 550);

                while (fenetreCredits.isOpen()) {
                    gestionnaireCredit.afficherMenu(fenetreCredits);
                    int retour = gestionnaireCredit.gererEvenements(fenetreCredits);
                    if (retour == 0) {
                        fenetreCredits.close();
                    }
                }
                break;
            }
        }
    }
    return 0;
}
