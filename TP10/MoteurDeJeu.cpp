#include "MoteurDeJeu.h"

MoteurDeJeu::MoteurDeJeu () {
    /// Création du composant cadre
    cadre = new Cadre ();

    /// Création du composant serpent
    serpent = new Serpent (cadre, getRandomCoordonnees());

    /// Création du composant cible
    Coordonnees xy;
    // 1. Les coordonnées xy ou placer la cible doivent différer du serpent
    do {
        xy = getRandomCoordonnees ();
    } while (serpent->seTrouveEn(xy));

    // 2. Création de la cible avec ses coordonnées et sa valeur comprise entre 1 et 9
    cible = new Cible (cadre, xy, (1 + random() % 9));
}

// installer : Installe le jeu
void MoteurDeJeu::installer () {
    system("CLS");      // Efface l'écran
    cadre->afficher();  // Affiche le cadre
    serpent->afficher();// Affiche le serpent
    cible->afficher();  // Affiche la cible
}

// jouer : Gère le déroulement du jeu
void MoteurDeJeu::jouer () {
    // Variables locales pour gérer le déplacement du serpent
    Coordonnees coordTete;
    Coordonnees futureCoordTete;

    // Variables locales pour gérer le déplacement de la cible
    Coordonnees     futureCoordCible;
    unsigned int    futureValeurCible;

    // Boucle du jeu dont on sort quand la tête du serpent touche le cadre ou bien touche son propre corps
    for (;;) {
        // Afficher les paramètres du jeu
        cadre->gotoXY (Coordonnees (1, 24));  cout << "Vitesse (" << DIRECTIVE_ACCELERER << "/" << DIRECTIVE_RALENTIR << ") :";
        cadre->gotoXY (Coordonnees (17, 24)); cout << serpent->vitesse;

        cadre->gotoXY (Coordonnees (30, 24)); cout << "Score : " << serpent->score;
        cadre->gotoXY (Coordonnees (50, 24));
        cout << " H/" << DIRECTIVE_HAUT << "  B/" << DIRECTIVE_BAS << "  D/" << DIRECTIVE_DROITE << "  G/" << DIRECTIVE_GAUCHE
             << "  S/" << DIRECTIVE_STOP;

        // Obtenir les coordonnées de la tête du serpent
        coordTete = *(serpent->corps.begin());

        // Lire et interprêter la directive saisie au clavier
        switch (lireDirective()) {
            case DIRECTIVE_NULLE: break; // rien n'a été saisi
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
            // 1. Créditer le score
            serpent->score += cible->valeur;
            // 2. Créditer le serpent de la longueur à ralonger
            serpent->creditLongueur += cible->valeur;
            // 3. Etablir les nouvelles coordonnées de la cible
            do {
                // Obtenir une new proposition de coordonnées pour la cible
                futureCoordCible = getRandomCoordonnees();
            } while (/*(!(cadre->seTrouveEn(futureCoordCible))) || */(serpent->seTrouveEn(futureCoordCible)) || (cible->seTrouveEn(futureCoordCible))); // Tant qu’elles coïncident avec le cadre, le serpent ou la cible courante
            // 4. Etablir la valeur de la cible : qui doit valoir entre 1 et 9
            do {
                futureValeurCible = random() % 10;
            } while (!(futureValeurCible <= 9 && futureValeurCible >= 1));
            // 5. Effacer la cible
            cible->effacer();
            // 6. Redéfinir les propriétés de la cible
            cible->definir(futureCoordCible, futureValeurCible);
            // 7. Afficher la cible
            cible->afficher();
        }

        

        // S’il est en mouvement, déplacer le serpent
        if (coordTete != futureCoordTete) { /// Equivaut à (direction != STOP)
            serpent->effacer ();                   // Effacer
            serpent->avancerEn (futureCoordTete);  // Avancer
            serpent->afficher();                   // Afficher
        }

        // Temporiser
        for (int nbDeGrains = 0 ; nbDeGrains < (VITESSE_MAX - serpent->vitesse) ; nbDeGrains++)
            Sleep (GRAIN_DE_TEMPS);
    }
}  // Fin de la méthode jouer

// terminer : Termine le jeu
void MoteurDeJeu::terminer () {
    cadre->gotoXY (Coordonnees (10, 25), "     P E R D U !!   ");
    cout << "taper un caractere pour recommencer      ";
    char c; cin >> c;
}

// lireDirective : Retourne l'éventuel caractère saisi au clavier
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

// random : Retourne une valeur aléatoire
int MoteurDeJeu::random () {
    srand (time (NULL));
    return rand ();
}
