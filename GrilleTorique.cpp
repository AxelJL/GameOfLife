#include "GrilleTorique.h"

/*
 * Constructeur de la classe GrilleTorique.
 * Initialise la grille avec une largeur et une hauteur, en appelant le constructeur de la classe de base Grille.
 * @param largeur La largeur de la grille.
 * @param hauteur La hauteur de la grille.
 */
GrilleTorique::GrilleTorique(int largeur, int hauteur)
    : Grille(largeur, hauteur) {}

/*
 * Calcule le prochain état de chaque cellule de la grille.
 * Pour chaque cellule, cette méthode compte les voisins vivants en tenant compte des bords toriques.
 * Les cellules aux bords de la grille sont considérées comme adjacentes aux cellules opposées, formant ainsi un "toroïde".
 */
void GrilleTorique::calculerProchainEtat() {
    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            int voisinsVivants = 0;

            // Parcours de tous les voisins possibles
            for (int dy = -1; dy <= 1; ++dy) {
                for (int dx = -1; dx <= 1; ++dx) {
                    if (dx == 0 && dy == 0) continue; // Ne pas compter la cellule elle-même

                    // Calcul des indices toriques des voisins
                    int nx = indiceTorique(x + dx, largeur);
                    int ny = indiceTorique(y + dy, hauteur);

                    // Ajout à la somme des voisins vivants
                    voisinsVivants += cellules[ny][nx].estVivante();
                }
            }

            // Mise à jour de l'état de la cellule en fonction des voisins
            cellules[y][x].calculerEtatProchain(voisinsVivants);
        }
    }
}

/*
 * Calcule l'indice toriques d'une cellule en tenant compte des bords de la grille.
 * Si l'indice est en dehors des limites de la grille, il est "replié" pour revenir dans les limites de la grille.
 * indice L'indice à "replier" (s'il est en dehors des limites).
 * max La taille maximale de la grille dans la dimension (largeur ou hauteur).
 * retourne L'indice toriques, qui peut être un indice entre 0 et max-1.
 */
int GrilleTorique::indiceTorique(int indice, int max) const {
    return (indice + max) % max;
}