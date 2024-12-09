#include "Grille.h"
#include <fstream>
#include <iostream>

/* 
 * Constructeur de la grille.
 * Initialise une grille vide avec les dimensions données.
 */
Grille::Grille(int largeur, int hauteur)
    : largeur(largeur), hauteur(hauteur), cellules(hauteur, std::vector<Cellule>(largeur)) {}

/* 
 * Retourne la largeur de la grille.
 */
int Grille::getLargeur() const {
    return largeur;
}

/* 
 * Retourne la hauteur de la grille.
 */
int Grille::getHauteur() const {
    return hauteur;
}

/* 
 * Charge la grille depuis un fichier.
 * Le fichier doit contenir la largeur, la hauteur, puis l'état de chaque cellule (1 pour vivante, 0 pour morte).
 */
void Grille::chargerDepuisFichier(const std::string& fichier) {
    std::ifstream fichierEntree(fichier);
    if (!fichierEntree) {
        std::cerr << "[JDLV Manager | Grille]> Impossible de charger le fichier: " << fichier << std::endl;
        return;
    }
    fichierEntree >> largeur >> hauteur;
    cellules.resize(hauteur, std::vector<Cellule>(largeur));
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int etat;
            fichierEntree >> etat;
            cellules[y][x] = Cellule(etat == 1);
        }
    }
}

/* 
 * Affiche la grille dans la console.
 * Les cellules vivantes sont affichées par '1', les mortes par '0'.
 */
void Grille::afficher() const {
    for (const auto& ligne : cellules) {
        for (const auto& cellule : ligne) {
            std::cout << (cellule.estVivante() ? '1' : '0');
        }
        std::cout << std::endl;
    }
}

/* 
 * Actualise l'état de toutes les cellules.
 * Cette méthode met à jour l'état des cellules en fonction des règles du jeu.
 */
void Grille::actualiserEtat() {
    for (auto& ligne : cellules) {
        for (auto& cellule : ligne) {
            cellule.actualiserEtat();
        }
    }
}

/* 
 * Calcule le prochain état de la grille.
 * Pour chaque cellule, on calcule son état en fonction du nombre de voisins vivants.
 */
void Grille::calculerProchainEtat() {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int voisinsVivants = 0;

            // Parcours des voisins (y compris diagonales)
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // On ne compte pas la cellule elle-même
                    int nx = x + dx;
                    int ny = y + dy;

                    // Vérifie les limites de la grille
                    if (nx >= 0 && nx < largeur && ny >= 0 && ny < hauteur) {
                        voisinsVivants += cellules[ny][nx].estVivante();
                    }
                }
            }
            cellules[y][x].calculerEtatProchain(voisinsVivants);
        }
    }
}


/* 
 * Retourne la cellule située à la position (x, y).
 * Cette méthode permet de modifier l'état de la cellule.
 */
Cellule& Grille::getCellule(int x, int y) {
    return cellules[y][x];
}

/* 
 * Retourne la cellule située à la position (x, y).
 * Cette méthode permet d'accéder à l'état de la cellule sans la modifier.
 */
const Cellule& Grille::getCellule(int x, int y) const {
    return cellules[y][x];
}
