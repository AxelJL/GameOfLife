#pragma once

class Cellule {
private:
    bool etat;
    bool prochaine_etat;

public:
    Cellule(bool etatInitial = false);

    bool estVivante() const;
    void calculerEtatProchain(int nbVivants);
    void actualiserEtat();
};

