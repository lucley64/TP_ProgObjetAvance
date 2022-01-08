/**
 @file ElementDeJeu.h
 @brief sp�cifie ElementDeJeu
Attributs : cadre
M�thodes  : afficher, effacer, seTrouverEn
 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/

#ifndef ELEMENTDEJEU_H
#define ELEMENTDEJEU_H

#include <assert.h>  // Pour l'usage d'assertions

#include "Cadre.h"

using namespace std;


class ElementDeJeu {
/// ATTRIBUTS : cadre
public:
    Cadre* cadre; // Dans lequel s'inscrit l'�l�ment de jeu

/// METHODES SPCIFIQUES : afficher, effacer, se trouveEn
public:
    // afficher : Affiche l'�l�ment de jeu (� sp�cialiser dans les sous-classes)
    virtual void afficher () = 0;

    // effacer : Efface l'�l�ment de jeu (� sp�cialiser dans les sous-classes)
    virtual void effacer () = 0;

    // seTrouveEn : Dit si l'�l�ment de jeu occupe la position xy (� sp�cialiser dans les sous-classes)
    virtual bool seTrouveEn (const Coordonnees xy) = 0;
};

#endif // ELEMENTDEJEU_H
