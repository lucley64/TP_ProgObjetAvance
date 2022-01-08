#include "Cadre.h"

Cadre::Cadre (char carCadre) {
    apparence = carCadre;
}

// gotoXY : positionne le curseur en xy - repère cartésien (0,0) en bas à gauche
void Cadre::gotoXY (const Coordonnees xy) {
    COORD coord;
    coord.X = xy.first;
    coord.Y = xy.second;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// gotoXYint : positionne le curseur en xy et écrit i
void Cadre::gotoXY (const Coordonnees xy, const unsigned int i) {
    gotoXY(xy); cout << i;
}

// gotoXYchar : positionne le curseur en xy et écrit c
void Cadre::gotoXY (const Coordonnees xy, char c) {
    gotoXY(xy); cout << c;
}

// gotoXYstring : positionne le curseur en xy et écrit s
void Cadre::gotoXY (const Coordonnees xy, string s) {
    gotoXY(xy); cout << s;
}

// afficher : affiche le cadre
void Cadre::afficher () {
    for (int i = 0; i < LARGEUR_CADRE; i++) {
        gotoXY (Coordonnees (i, 0), apparence);
        gotoXY (Coordonnees (i, HAUTEUR_CADRE), apparence);
    }
    for (int j = 0; j < HAUTEUR_CADRE; j++) {
        gotoXY (Coordonnees (0, j), apparence);
        gotoXY (Coordonnees (LARGEUR_CADRE, j), apparence);
    }
}

// seTrouveEn : dit si le cadre occupe les coordonnées xy
bool Cadre::seTrouveEn (const Coordonnees xy) {
    return ((xy.first == LARGEUR_CADRE || xy.second == HAUTEUR_CADRE || xy.first == 0 || xy.second == 0) ? true : false);
}
