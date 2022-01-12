/**
 @file Cadre.h
 @brief sp�cifie Coordonnees, Cadre
Attributs : apparence
M�thodes  : Cadre, gotoXY, gotoXY, gotoXY, afficher, seTrouverEn
 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/

#ifndef CADRE_H
#define CADRE_H

#include <iostream>
#include <windows.h> // Pour les valeurs al�atoires et effacer l'�cran
#include <assert.h>

#define LARGEUR_CADRE   79
#define HAUTEUR_CADRE   23
#define APPARENCE_CADRE '*'

using namespace std;

typedef pair<int, int> Coordonnees; // Pour localiser les parties des �l�ments de jeu

class Cadre {
/// ATTRIBUTS : apparence
private:
    char apparence; // Apprence des cases du cadre

/// CONSTRUCTEUR
public:
    Cadre (char carCadre=APPARENCE_CADRE);

/// METHODES SPECIFIQUES : gotoXY gotoXYint, gotoXYchar, gotoXYstring, afficher, seTrouveEn
public:
    // gotoXY : positionne le curseur en xy - rep�re cart�sien (0,0) en haut � gauche
    void gotoXY (const Coordonnees xy);

    // gotoXY : positionne le curseur en xy et �crit int
    void gotoXY (const Coordonnees xy, const unsigned int i);

    // gotoXY : positionne le curseur en xy et �crit char
    void gotoXY (const Coordonnees xy, char c);

    // gotoXY : positionne le curseur en xy et �crit string
    void gotoXY (const Coordonnees xy, string s);

    // afficher : affiche le cadre
    void afficher ();

    // seTrouveEn : dit si le cadre occupe les coordonn�es xy
    bool seTrouveEn (const Coordonnees xy);
};

#endif // CADRE_H
