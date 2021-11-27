#ifndef CHAMBRE_H
#define CHAMBRE_H

#include<iostream>

using namespace std;

class Chambre {
public:
	string numero;
	string etage;
	unsigned short int prix;

	Chambre(string numero = "", string etage = "", unsigned short int prix = 0);
	Chambre(const Chambre& chambre);

	virtual ~Chambre();

	Chambre& operator= (const Chambre& chambre);
};

#endif // !CHAMBRE_H
