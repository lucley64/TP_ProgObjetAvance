#include "Cible.h"

Cible::Cible (Cadre* unCadre, const Coordonnees unePosition, const unsigned int uneValeur) {
    assert(unCadre);
    cadre = unCadre; // Dans lequel s'inscrit la cible
    assert(uneValeur > 0 && uneValeur < 10);
    assert(unePosition.first > 0 && unePosition.first < LARGEUR_CADRE && unePosition.second > 0 && unePosition.second < HAUTEUR_CADRE);
    definir (unePosition, uneValeur);
}

// definir : (Re)D�finit les propri�t�s de la cible
void Cible::definir (const Coordonnees unePosition, const unsigned int uneValeur) {
    assert(uneValeur > 0 && uneValeur < 10);
    assert(unePosition.first > 0 && unePosition.first < LARGEUR_CADRE && unePosition.second > 0 && unePosition.second < HAUTEUR_CADRE);
    position = unePosition;
    valeur = uneValeur;
}

// afficher : Affiche a cible
void Cible::afficher () {
    cadre->gotoXY (position, valeur);
}

// effacer : Efface la cible
void Cible::effacer () {
    cadre->gotoXY (position, ' '); // efface le chiffre
}

// seTrouveEn : Dit si la cible occupe la position xy
bool Cible::seTrouveEn (const Coordonnees xy){
    return (position == xy);
}
