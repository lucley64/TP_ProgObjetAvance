/**
 @file main.cpp

 @brief jeu du snake
Les règles du jeu sont les suivante :
- L'utilisateur gère la vitesse (+/-) d'un serpent pour manger des cibles valant entre 1 et 9.
- Le corps du serpent se rallonge alors d'autant de cases.
- Les directives sont celles du pavé numérique (Gauche-5, Droite-6, Haut-8, Bas-2, Stop-5)
- Le jeu s'arrête quand la tête du serpent coincide avec le cadre du jeu ou avec une des cases occupées par son corps.

L'intention pédagogique de ce jeu est :
- la rétroingénierie
- l'usage de tests du type assertions
- l'application de principes SOLID

 @author Lopistéguy
 @version 0.1
 @date jj/mm/aaa
**/

#include "MoteurDeJeu.h"

int main() {


    for (;;) { /// Possibilité de rejouer autant de fois que voulu
        MoteurDeJeu monJeu;
        monJeu.installer();
        monJeu.jouer();
        monJeu.terminer();
    }
    return 0;
}

