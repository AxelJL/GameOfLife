#include "Cellule.h"

/* 
 * Constructeur de la classe Cellule.
 * Initialise l'état de la cellule à l'état donné (vivante ou morte) et la prochaine état à "morte".
 */
Cellule::Cellule(bool etatInitial) : etat(etatInitial), prochaine_etat(false) {}

/* 
 * Retourne l'état actuel de la cellule.
 * return true si la cellule est vivante, false si elle est morte.
 */
bool Cellule::estVivante() const { return etat; }

/* 
 * Calcule l'état suivant de la cellule basé sur le nombre de voisins vivants.
 * Si la cellule est vivante et qu'elle a 2 ou 3 voisins vivants, elle reste vivante, sinon elle meurt.
 * Si la cellule est morte et qu'elle a exactement 3 voisins vivants, elle devient vivante.
 * nbVivants Le nombre de voisins vivants de la cellule.
 */
void Cellule::calculerEtatProchain(int nbVivants) {
    if (etat) {
        // Si la cellule est vivante, elle survit si elle a 2 ou 3 voisins vivants.
        prochaine_etat = (nbVivants == 2 || nbVivants == 3);
    } else {
        // Si la cellule est morte, elle devient vivante si elle a 3 voisins vivants.
        prochaine_etat = (nbVivants == 3);
    }
}

/* 
 * Actualise l'état de la cellule en fonction du prochain état calculé.
 */
void Cellule::actualiserEtat() { etat = prochaine_etat; }
