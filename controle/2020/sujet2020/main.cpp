#include <iostream>
#include <map>

#include "Facture.h"

using namespace std;

typedef multimap<IdentifantClient, Facture*> FactureParClient;

void penalite(FactureParClient::value_type);

int main() {

	Facture f1("F001", "Patrick", "01/01/2020", 100),
		f2("F002", "Pantxika", "02/01/2020", 200),
		f3("F003", "Patrick", "03/01/2020", 300),
		f4("F004", "Tournesol", "04/01/2020", 400);

	cout << f1.toString("Facture 1 : ") << endl << f2.toString("Facture 2 : ") << endl << f3.toString("Facture 3 : ") << endl << f4.toString("Facture 4 : ") << endl;

	FactureParClient facturesImpayees;
	facturesImpayees.insert(FactureParClient::value_type(f1.idClient, &f1));
	facturesImpayees.insert(FactureParClient::value_type(f2.idClient, &f2));
	facturesImpayees.insert(FactureParClient::value_type(f3.idClient, &f3));
	facturesImpayees.insert(FactureParClient::value_type(f4.idClient, &f4));

	cout << "Nombre de factures impayees par Patrick : " << facturesImpayees.count("Patrick") << endl;




	return 0;
}

void penalite(FactureParClient::value_type factAPenaliser) {
	factAPenaliser.second->montant *= 1.1;
}