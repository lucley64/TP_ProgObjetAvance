/**
 @file main.cpp

 @brief jeu du snake
Les r�gles du jeu sont les suivante :
- L'utilisateur g�re la vitesse (+/-) d'un serpent pour manger des cibles valant entre 1 et 9.
- Le corps du serpent se rallonge alors d'autant de cases.
- Les directives sont celles du pav� num�rique (Gauche-5, Droite-6, Haut-8, Bas-2, Stop-5)
- Le jeu s'arr�te quand la t�te du serpent coincide avec le cadre du jeu ou avec une des cases occup�es par son corps.

L'intention p�dagogique de ce jeu est :
- la r�troing�nierie
- l'usage de tests du type assertions
- l'application de principes SOLID

 @author Lopist�guy
 @version 0.1
 @date jj/mm/aaa
**/

#define NDEBUG

#include "MoteurDeJeu.h"

int main() {


    for (;;) { /// Possibilit� de rejouer autant de fois que voulu
        MoteurDeJeu monJeu;
        monJeu.installer();
        monJeu.jouer();
        monJeu.terminer();
    }
    return 0;
}

