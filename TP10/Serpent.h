/**
 @file Serpent.h
 @brief sp�cifie deltaX, deltaY, Serpent
Attributs : pparenceCorps, apparenceTete, corps, direction, vitesse, cr�ditLongueur, score
M�thodes  : Serpent, afficher, effacer, seTrouveEn, avancerEn
 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/

#ifndef SERPENT_H
#define SERPENT_H

#include "ElementDeJeu.h"
#include <list>

// D�finitions sur l'apparence du serpent
#define APPARENCE_TETE  '@'  // La t�te du serpent
#define APPARENCE_CORPS 'o'  // Le corps du serpent

// D�finitions relatives aux d�placements de la t�te du serpent
// Note : le coin sup�rieur gauche de l'�cran est (0, 0)
#define STOP   0
#define DROITE 1
#define GAUCHE 2
#define HAUT   3
#define BAS    4
const int deltaX[] = {0, 1, -1, 0, 0};
const int deltaY[] = {0, 0, 0, -1, 1};

// D�finitions des bornes de vitesse du serpent
#define VITESSE_MAX 9
#define VITESSE_MIN 1
#define GRAIN_DE_TEMPS 100 // qui s'�coule en millisecondes entre 2 d�placements

class Serpent : public ElementDeJeu {

/// ATTRIBUTS : apparenceCorps, apparenceTete, corps, direction, vitesse, cr�ditLongueur, score
private:
    char apparenceCorps;                // Apparence du corps du serpent
    char apparenceTete;                 // Apparence de la t�te du serpent
    typedef list <Coordonnees> Corps;   // D�finition du type Corps
public:
    Corps corps;                        // Le corps est une liste de coordonn�es
    int direction;                      // STOP, HAUT, BAS, DROITE,GAUCHE vers laquelle se dirige le serpent
    int vitesse;                        // VITESSE_MIN..VITESSE_MAX a laquelle se d�place le serpent
    int score;                          // Que cumule le serpent en touchant les cibles
    unsigned int creditLongueur;        // Non encore cr�dit� dans la queue du serpent

    int invincibilite;

/// CONSTRUCTEUR
public:
    Serpent (Cadre* unCadre, Coordonnees xy, char carCorps=APPARENCE_CORPS, char carTete=APPARENCE_TETE);

/// METHODE SPECIFIQUES : afficher, effacer, seTrouveEn, avancerEn
public:
    // afficher : Affiche tout le serpent
    void afficher ();

    // effacer : Efface le serpent
    void effacer ();

    // seTrouveEn : Dit si le serpent occupe la position xy
    bool seTrouveEn (const Coordonnees xy);

    // avancerEn : Met � jour les donn�es du serpent qui progresse en position xy
    void avancerEn (const Coordonnees xy);
};

#endif // SERPENT_H
