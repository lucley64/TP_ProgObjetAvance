#include <iostream>


#include "Graphique.h"
#include "Point.h"
#include "GraphiqueCompose.h"
#include "Terminal.h"
#include "Ligne.h"


using namespace std;

int main() {
	char carSaisi;     // Caractère saisi au clavier pour scander la progression

	system("CLS"); // Efface l'écran
	/// Crée et affiche un par un les objets p1, p2 et p3
	Point point1(6, 10, '*');
	Terminal::stringLigneColonne(20, 1, "TAPER un car pour afficher p1 (6,10,*) : ");
	cin >> carSaisi; point1.afficher();

	Point point2(6, 20, '#');
	Terminal::stringLigneColonne(20, 1, "Taper UN car pour afficher p1 (6,20,#) : ");
	cin >> carSaisi; point2.afficher();

	Point point3(10, 15);
	Terminal::stringLigneColonne(20, 1, "Taper un CAR pour afficher p3 (10,15 ) : ");
	cin >> carSaisi; point3.afficher();

	Ligne l1(6, 15, 12);
	Terminal::stringLigneColonne(20, 1, "Taper un CAR pour afficher l1 (6, 15, 2) : ");
	cin >> carSaisi;
	l1.afficher();

	/// Regroupe p1, p2 et p3 en un seul objet graphique gc
	Terminal::stringLigneColonne(20, 1, "Taper un CAR pour regrouper p1, p2 et p3 en gc : ");
	GraphiqueCompose gc;
	gc.ajouter(&point1);
	gc.ajouter(&point2);
	gc.ajouter(&point3);
	gc.ajouter(&l1);
	cin >> carSaisi; gc.afficher();

	/// Effacer l'objet graphique gc
	Terminal::stringLigneColonne(20, 1, "Taper un car POUR effacer le graphique compose gc : ");
	cin >> carSaisi; gc.effacer();

	/// Déplacer l'objet graphique gc
	Terminal::stringLigneColonne(20, 1, "Taper un car pour DEPLACER le graphique compose (-2 ,5) : ");
	cin >> carSaisi; gc.deplacerDe(-2, 5);

	/// Réafficher l'objet graphique gc
	Terminal::stringLigneColonne(20, 1, "Taper un car pour afficher LE gc a sa nouvelle position : ");
	cin >> carSaisi; gc.afficher();

	Terminal::stringLigneColonne(20, 1, "T E R M I N E ...                                          ");

}