/**
 @file Cible.h
 @brief sp�cifie Cible
Attributs : position, valeur
M�thodes  : Cible, definir, afficher, effacer, seTrouverEn
 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/
#ifndef CIBLE_H
#define CIBLE_H

#include "ElementDeJeu.h"

class Cible : public ElementDeJeu {

/// ATTRIBUTS : position, valeur
public:
    Coordonnees position;   // A l'int�rieur du cadre
    unsigned int valeur;    // Entre 1 et 9

/// CONSTRUCTEUR
public:
    Cible (Cadre* unCadre, const Coordonnees unePosition, const unsigned int unevaleur);

/// METHODE SPECIFIQUES : d�finir, afficher, effacer, seTrouveEn
public:
    // definir : (Re)D�finit les propri�t�s de la cible
    void definir (const Coordonnees unePosition, const unsigned int uneValeur);

    // afficher : Affiche a cible
    void afficher ();

    // effacer : Efface la cible
    void effacer ();

    // seTrouveEn : Dit si la cible occupe la position xy
    bool seTrouveEn (const Coordonnees xy);
};

#endif // CIBLE_H
