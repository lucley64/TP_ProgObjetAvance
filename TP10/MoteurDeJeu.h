/**
 @file MoteurDeJeu.h
 @brief sp�cifie MoteurDeJeu
Attributs : cadre, serpent, cible
M�thodes  : MoteurDejeu, installer, jouer, terminer, lireDirective, random, getRandomCoordonn�es
 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/

#ifndef MOTEURDEJEU_H
#define MOTEURDEJEU_H

#include <iostream>
#include <conio.h>   // Pour g�rer la saisie a la vol�e
#include <time.h>    // Pour g�rer la temporisation

#include "Cadre.h"
#include "Serpent.h"
#include "Cible.h"
#include "Etoile.h"

// DECLARATION DES DIRECTIVES RECONNUES AU CLAVIER
#define DIRECTIVE_STOP      '5'
#define DIRECTIVE_DROITE    '6'
#define DIRECTIVE_GAUCHE    '4'
#define DIRECTIVE_HAUT      '8'
#define DIRECTIVE_BAS       '2'
#define DIRECTIVE_ACCELERER '+'
#define DIRECTIVE_RALENTIR  '-'
#define DIRECTIVE_NULLE     char (NULL)

using namespace std;

class MoteurDeJeu {

/// ATTRIBUTS : -cadre, -serpent, -cible
private:
    Cadre*   cadre;   // Dans lequel s'inscrit le jeu
    Serpent* serpent; // Que le joueur d�place vers la cible
    Cible*   cible;   // Qui se r�g�n�re et rapporte du cr�dit d�s quelle est touch�e
    Etoile*  etoile;

/// CONSTRUCTEUR
public:
    MoteurDeJeu ();

/// METHODES SPECIFIQUES : installer, jouer, terminer, -lireDirective, -random, -getRandomCoordonn�es
public:
    // installer : Installe le jeu
    void installer ();

    // jouer : G�re le d�roulement du jeu
    void jouer ();

    // terminer : Termine le jeu
    void terminer ();

/// M�thodes priv�es : lireDirective, getRandomCoordonn�es, random
private:
    // lireDirective : Retourne l'�ventuel caract�re saisi au clavier
    char lireDirective();

    // getRandomCoordonnees : Retourne des coordonnees inscrites dans le cadre
    Coordonnees getRandomCoordonnees ();

    // random : Retourne une valeur al�atoire
    int random ();
};
#endif // MOTEURDEJEU_H
