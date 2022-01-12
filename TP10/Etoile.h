#ifndef ETOILE_H
#define ETOILE_H

#include "ElementDeJeu.h"

class Etoile : public ElementDeJeu{
/// ATTRIBUTS : position
public:
    Coordonnees position;
    bool activee;

/// CONSTRUCTEUR
public:
    Etoile(Cadre* unCadre, const Coordonnees unePosition);

/// METHODE SPECIFIQUES : d�finir, afficher, effacer, seTrouveEn
public:
    // definir : (Re)D�finit les propri�t�s de la cible
    void definir (const Coordonnees unePosition);

    // afficher : Affiche a cible
    void afficher ();

    // effacer : Efface la cible
    void effacer ();

    // seTrouveEn : Dit si la cible occupe la position xy
    bool seTrouveEn (const Coordonnees xy);
};

#endif //! ETOILE_H