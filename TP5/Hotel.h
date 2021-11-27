#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <set>

#include "Administrateur.h"
#include "Chambre.h"

using namespace std;

class Hotel {
public:
	Hotel(const Hotel& hotel);
	Hotel(string nom="", string adresse="");

	virtual ~Hotel();

	Hotel& operator=(const Hotel& hotel);

	bool administrePar(Administrateur* admin);
	bool inclutChambre(Chambre* chambre);
	bool modifierPrixChambre(string numero, unsigned short int prix);

	string toString(string message="");

	string nom;
	string adresse;
	set<Chambre*> mesChambres;
	set<Administrateur*> lesAdministrateurs;

};


#endif // !HOTEL_H
