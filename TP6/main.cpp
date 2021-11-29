#include <iostream>

#include "Produit.h"

typedef std::string	Libelle;
typedef std::string	Code;
typedef float		Prix;
typedef int			Quantite;
typedef std::string	Adresse;

int main() {

	Produit p1("TABLE",		"T001",	110),
			p2("CHAISE",	"C001",	50),
			p3("FAUTEUIL",	"F001", 70);

	std::cout << p1.toString() << std::endl << p2.toString() << std::endl << p3.toString() << std::endl;


	return 0;
}