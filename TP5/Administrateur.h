#ifndef ADMINISTRATEUR_H
#define ADMINISTRATEUR_H

#include <iostream>

using namespace std;

class Administrateur {
public:
	string identite;
	string fonction;

	Administrateur(string identite="", string fonction="");
	Administrateur(const Administrateur& admin);

	virtual ~Administrateur();

	Administrateur& operator=(const Administrateur& admin);
};

#endif // !ADMINISTRATEUR_H
