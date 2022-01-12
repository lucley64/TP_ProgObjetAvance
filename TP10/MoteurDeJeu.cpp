#include "MoteurDeJeu.h"

MoteurDeJeu::MoteurDeJeu () {
    /// Cr�ation du composant cadre
    cadre = new Cadre ();

    /// Cr�ation du composant serpent
    serpent = new Serpent (cadre, getRandomCoordonnees());

    /// Cr�ation du composant cible
    Coordonnees xy;
    // 1. Les coordonn�es xy ou placer la cible doivent diff�rer du serpent
    do {
        xy = getRandomCoordonnees ();
    } while (serpent->seTrouveEn(xy));

    // 2. Cr�ation de la cible avec ses coordonn�es et sa valeur comprise entre 1 et 9
    cible = new Cible (cadre, xy, (1 + random() % 9));

    do {
        xy = getRandomCoordonnees ();
    } while (serpent->seTrouveEn(xy) || cible->seTrouveEn(xy));

    etoile = new Etoile(cadre, xy);
}

// installer : Installe le jeu
void MoteurDeJeu::installer () {
    system("CLS");      // Efface l'�cran
    cadre->afficher();  // Affiche le cadre
    serpent->afficher();// Affiche le serpent
    cible->afficher();  // Affiche la cible
    etoile->activee = random()%10 == 1;
    etoile->afficher();
}

// jouer : G�re le d�roulement du jeu
void MoteurDeJeu::jouer () {
    // Variables locales pour g�rer le d�placement du serpent
    Coordonnees coordTete;
    Coordonnees futureCoordTete;

    // Variables locales pour g�rer le d�placement de la cible
    Coordonnees     futureCoordCible;
    unsigned int    futureValeurCible;

    Coordonnees     futureCoordEtoile;

    // Boucle du jeu dont on sort quand la t�te du serpent touche le cadre ou bien touche son propre corps
    for (;;) {
        // Afficher les param�tres du jeu
        cadre->gotoXY (Coordonnees (1, 24));  cout << "Vitesse (" << DIRECTIVE_ACCELERER << "/" << DIRECTIVE_RALENTIR << ") :";
        cadre->gotoXY (Coordonnees (17, 24)); cout << serpent->vitesse;

        cadre->gotoXY (Coordonnees (30, 24)); cout << "Score : " << serpent->score;
        cadre->gotoXY (Coordonnees (50, 24));
        cout << " H/" << DIRECTIVE_HAUT << "  B/" << DIRECTIVE_BAS << "  D/" << DIRECTIVE_DROITE << "  G/" << DIRECTIVE_GAUCHE
             << "  S/" << DIRECTIVE_STOP;

        // Obtenir les coordonn�es de la t�te du serpent
        coordTete = *(serpent->corps.begin());

        // Lire et interpr�ter la directive saisie au clavier
        switch (lireDirective()) {
            case DIRECTIVE_NULLE: break; // rien n'a �t� saisi
            case DIRECTIVE_ACCELERER:
                (serpent->vitesse == VITESSE_MAX ? true : serpent->vitesse++); break;
            case DIRECTIVE_RALENTIR:
                (serpent->vitesse > VITESSE_MIN ? serpent->vitesse-- : true); break;
            case DIRECTIVE_STOP:
                serpent->direction = STOP;   break;
            case DIRECTIVE_DROITE:
                serpent->direction = DROITE; break;
            case DIRECTIVE_GAUCHE:
                serpent->direction = GAUCHE; break;
            case DIRECTIVE_HAUT:
                serpent->direction = HAUT;   break;
            case DIRECTIVE_BAS:
                serpent->direction = BAS;    break;
        }

        // Etablir futureCoordTete du serpent
        futureCoordTete.first  = coordTete.first  + deltaX [serpent->direction];
        futureCoordTete.second = coordTete.second + deltaY [serpent->direction];

        // Si futureCoordTete touchent le cadre ou bien touchent le serpent, on sort de la boucle de jeu
        if (cadre->seTrouveEn (futureCoordTete) || (serpent->seTrouveEn (futureCoordTete) && serpent->direction != STOP))
            break;

        // Cas ou futureCoordTete touchent la cible
        if (cible->seTrouveEn(futureCoordTete)) {
            // 1. Cr�diter le score
            serpent->score += cible->valeur;
            // 2. Cr�diter le serpent de la longueur � ralonger
            serpent->creditLongueur += cible->valeur;
            // 3. Etablir les nouvelles coordonn�es de la cible
            do {
                // Obtenir une new proposition de coordonn�es pour la cible
                futureCoordCible = getRandomCoordonnees();
            } while (/*(!(cadre->seTrouveEn(futureCoordCible))) || */(serpent->seTrouveEn(futureCoordCible)) || (cible->seTrouveEn(futureCoordCible)) || (etoile->seTrouveEn(futureCoordCible))); // Tant qu�elles co�ncident avec le cadre, le serpent ou la cible courante
            // 4. Etablir la valeur de la cible : qui doit valoir entre 1 et 9
            do {
                futureValeurCible = random() % 10;
            } while (!(futureValeurCible <= 9 && futureValeurCible >= 1));
            // 5. Effacer la cible
            cible->effacer();
            // 6. Red�finir les propri�t�s de la cible
            cible->definir(futureCoordCible, futureValeurCible);
            // 7. Afficher la cible
            cible->afficher();
        }

        if (etoile->activee){
            // Cas ou futureCoordTete touchent la l'étoile
            if (etoile->seTrouveEn(futureCoordTete)){
                serpent->invincibilite = 25;

                do {
                // Obtenir une new proposition de coordonn�es pour la cible
                futureCoordEtoile = getRandomCoordonnees();
                } while (/*(!(cadre->seTrouveEn(futureCoordCible))) || */(serpent->seTrouveEn(futureCoordCible)) || (cible->seTrouveEn(futureCoordCible)) || (etoile->seTrouveEn(futureCoordCible))); // Tant qu�elles co�ncident avec le cadre, le serpent ou la cible courante
            
                etoile->effacer();

                etoile->definir(futureCoordEtoile);

                etoile->activee = random()%10 == 1;
                etoile->afficher();
            }
        }
        else{
            etoile->activee = random()%10 == 1;
            etoile->afficher();
        }
        

        // S�il est en mouvement, d�placer le serpent
        if (coordTete != futureCoordTete) { /// Equivaut � (direction != STOP)
            serpent->effacer ();                   // Effacer
            serpent->avancerEn (futureCoordTete);  // Avancer
            serpent->afficher();                   // Afficher

        }

        // Temporiser
        for (int nbDeGrains = 0 ; nbDeGrains < (VITESSE_MAX - serpent->vitesse) ; nbDeGrains++)
            Sleep (GRAIN_DE_TEMPS);
    }
}  // Fin de la m�thode jouer

// terminer : Termine le jeu
void MoteurDeJeu::terminer () {
    cadre->gotoXY (Coordonnees (10, 25), "     P E R D U !!   ");
    cout << "taper un caractere pour recommencer      ";
    char c; cin >> c;
}

// lireDirective : Retourne l'�ventuel caract�re saisi au clavier
char MoteurDeJeu::lireDirective() {
    return (_kbhit() ? char (_getch()) : DIRECTIVE_NULLE);
}

// getRandomCoordonnees : Retourne des coordonnees inscrites dans le cadre
Coordonnees MoteurDeJeu::getRandomCoordonnees () {
    Coordonnees xy;
    xy.first  = 1 + random() % (LARGEUR_CADRE - 1);
    xy.second = 1 + random() % (HAUTEUR_CADRE - 1);
    return xy;
}

// random : Retourne une valeur al�atoire
int MoteurDeJeu::random () {
    srand (time (NULL));
    return rand ();
}
