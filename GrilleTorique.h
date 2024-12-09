#include "Grille.h"

class GrilleTorique : public Grille {
public:
    GrilleTorique(int largeur, int hauteur);
    virtual void calculerProchainEtat();

private:
    int indiceTorique(int indice, int max) const;
};

