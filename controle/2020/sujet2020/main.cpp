#include <iostream>
#include <map>

#include "Facture.h"

using namespace std;

typedef multimap<IdentifantClient, Facture*> FacturePar

int main() {

	Facture f1("F001", "Patrick", "01/01/2020", 100),
		f2("F002", "Pantxika", "02/01/2020", 200),
		f3("F003", "Patrick", "03/01/2020", 300),
		f4("F004", "Tournesol", "04/01/2020", 400);

	cout << f1.toString("Facture 1 : ") << endl << f2.toString("Facture 2 : ") << endl << f3.toString("Facture 3 : ") << endl << f4.toString("Facture 4 : ") << endl;



	return 0;
}