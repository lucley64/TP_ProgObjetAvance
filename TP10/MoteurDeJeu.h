/**
 @file MoteurDeJeu.h
 @brief spécifie MoteurDeJeu
Attributs : cadre, serpent, cible
Méthodes  : MoteurDejeu, installer, jouer, terminer, lireDirective, random, getRandomCoordonnées
 @author Lopistéguy
 @version 0.1
 @date jj/mm/aaa
**/

#ifndef MOTEURDEJEU_H
#define MOTEURDEJEU_H

#include <iostream>
#include <conio.h>   // Pour gérer la saisie a la volée
#include <time.h>    // Pour gérer la temporisation

#include "Cadre.h"
#include "Serpent.h"
#include "Cible.h"

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
    Serpent* serpent; // Que le joueur déplace vers la cible
    Cible*   cible;   // Qui se régénère et rapporte du crédit dès quelle est touchée

/// CONSTRUCTEUR
public:
    MoteurDeJeu ();

/// METHODES SPECIFIQUES : installer, jouer, terminer, -lireDirective, -random, -getRandomCoordonnées
public:
    // installer : Installe le jeu
    void installer ();

    // jouer : Gère le déroulement du jeu
    void jouer ();

    // terminer : Termine le jeu
    void terminer ();

/// Méthodes privées : lireDirective, getRandomCoordonnées, random
private:
    // lireDirective : Retourne l'éventuel caractère saisi au clavier
    char lireDirective();

    // getRandomCoordonnees : Retourne des coordonnees inscrites dans le cadre
    Coordonnees getRandomCoordonnees ();

    // random : Retourne une valeur aléatoire
    int random ();
};
#endif // MOTEURDEJEU_H
