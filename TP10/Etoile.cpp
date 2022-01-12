#include "Etoile.h"

Etoile::Etoile(Cadre* unCadre, const Coordonnees unePosition){
    assert(unCadre);
    cadre = unCadre; // Dans lequel s'inscrit la cible
    assert(unePosition.first > 0 && unePosition.first < LARGEUR_CADRE && unePosition.second > 0 && unePosition.second < HAUTEUR_CADRE);
    definir (unePosition);
    activee = false;
}

void Etoile::definir (const Coordonnees unePosition){
    assert(unePosition.first > 0 && unePosition.first < LARGEUR_CADRE && unePosition.second > 0 && unePosition.second < HAUTEUR_CADRE);
    position = unePosition;
}

void Etoile::afficher (){
    if (activee){
        cadre->gotoXY (position, 'X');
    }
}

void Etoile::effacer (){
    cadre->gotoXY (position, ' ');
}


bool Etoile::seTrouveEn (const Coordonnees xy){
    return (position == xy);
}