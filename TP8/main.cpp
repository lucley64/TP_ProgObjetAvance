#include <iostream>


#include "Graphique.h"
#include "Point.h"
#include "GraphiqueCompose.h"


using namespace std;

int main() {
	Point p1(5, 2),
		p2(2, 5),
		p3(7, 3);

	GraphiqueCompose fenetre;

	fenetre.ajouter(&p1);
	fenetre.ajouter(&p2);
	fenetre.ajouter(&p3);

	fenetre.afficher();

	cout << endl << endl << endl << "Entrez q pour quiter" << endl;
	char fin;
	do {
		cin >> fin;
	} while (fin != 'q');

	fenetre.effacer();

	return 0;
}