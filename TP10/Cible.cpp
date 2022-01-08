#include "Cible.h"

Cible::Cible (Cadre* unCadre, const Coordonnees unePosition, const unsigned int uneValeur) {
    assert(unCadre);
    cadre = unCadre; // Dans lequel s'inscrit la cible
    assert(uneValeur > 0 && uneValeur < 10);
    //assert(cadre->seTrouveEn(unePosition));
    definir (unePosition, uneValeur);
}

// definir : (Re)Définit les propriétés de la cible
void Cible::definir (const Coordonnees unePosition, const unsigned int uneValeur) {
    assert(uneValeur > 0 && uneValeur < 10);
    //assert(cadre->seTrouveEn(unePosition));
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
