/**
 @file ElementDeJeu.h
 @brief spécifie ElementDeJeu
Attributs : cadre
Méthodes  : afficher, effacer, seTrouverEn
 @author Lopistéguy
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
    Cadre* cadre; // Dans lequel s'inscrit l'élément de jeu

/// METHODES SPCIFIQUES : afficher, effacer, se trouveEn
public:
    // afficher : Affiche l'élément de jeu (à spécialiser dans les sous-classes)
    virtual void afficher () = 0;

    // effacer : Efface l'élément de jeu (à spécialiser dans les sous-classes)
    virtual void effacer () = 0;

    // seTrouveEn : Dit si l'élément de jeu occupe la position xy (à spécialiser dans les sous-classes)
    virtual bool seTrouveEn (const Coordonnees xy) = 0;
};

#endif // ELEMENTDEJEU_H
