#ifndef FACTURE_H
#define FACTURE_H

#include <iostream>

using namespace std;

typedef	string	ReferenceFacture;
typedef	string	IdentifantClient;
typedef	string	Date;
typedef	float	MontantFacture;

class Facture {
public:
	ReferenceFacture	refFacture;
	IdentifantClient	idClient;
	Date				date;
	MontantFacture		montant;

	Facture(ReferenceFacture ref = "", IdentifantClient idCli = "", Date date = "", MontantFacture montant = 0);
	Facture(const Facture& facture);

	Facture operator=(const Facture& facture);

	string toString(string message = "");
};

#endif // !FACTURE_H
