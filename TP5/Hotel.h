#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <set>

#include "Administrateur.h"
#include "Chambre.h"

using namespace std;

class Hotel {
public:
	Hotel();

	~Hotel();

private:
	string nom;
	string adresse;
	set<Chambre*> mesChambres;
	set<Administrateur*> lesAdministrateurs;


};


#endif // !HOTEL_H
