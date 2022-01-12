#include "Serpent.h"

Serpent::Serpent (Cadre* unCadre, Coordonnees xy, char carCorps, char carTete) {
    assert(unCadre);
    cadre = unCadre; // Dans lequel s'inscrit le serpent

    // Initialise le corps � l'unique coordonn�e xy
    assert(xy.first > 0 && xy.first < LARGEUR_CADRE && xy.second > 0 && xy.second < HAUTEUR_CADRE);
    corps.clear(); corps.push_front(xy);
    apparenceCorps = carCorps;
    apparenceTete  = carTete;

    score          = 0;
    creditLongueur = 0;

    direction = STOP;
    vitesse   = VITESSE_MIN;

    invincibilite = 0;
}

// afficher : Affiche tout le serpent
void Serpent::afficher () {
    Corps::iterator iter = corps.begin();
    // Afficher la t�te
    cadre->gotoXY (*iter, apparenceTete);
    // Afficher le reste du corps
    while (++iter != corps.end()) {
        cadre->gotoXY (*iter, apparenceCorps);
    }
}

// effacer : Efface le serpent
void Serpent::effacer () {
    for (Corps::iterator iter = corps.begin(); iter != corps.end(); iter++)
        cadre->gotoXY (*iter, ' ');
}

// seTrouveEn : Dit si le serpent occupe la position xy
bool Serpent::seTrouveEn (const Coordonnees xy) {
    for (Corps::iterator iter = corps.begin(); iter != corps.end(); iter++)
        if (*iter == xy) return true;
    return false;
}

// avancerEn : Met � jour les donn�es du serpent qui progresse en position xy
void Serpent::avancerEn (const Coordonnees xy) {
    // On place les nouvelles coordonn�ee xy en d�but de liste
    corps.push_front (xy);
    // S'il n'y a pas de cr�dit pour prolonger la queue du serpent...
    if (creditLongueur == 0)
        // ... on retire le dernier �l�ment de la liste
        corps.pop_back ();
    else
        // ... sinon on ne retire pas le dernier �l�ment mais on diminue le cr�dit
        creditLongueur--;
}
