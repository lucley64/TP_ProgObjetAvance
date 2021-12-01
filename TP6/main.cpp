#include <iostream>
#include <list>

#include "Produit.h"
#include "Magasin.h"
#include "Panier.h"

/*typedef std::string	Libelle;
typedef std::string	Code;
typedef float		Prix;
typedef int			Quantite;
typedef std::string	Adresse;*/

int main() {

	// Pour les produits :
	Produit p1("TABLE",		"T001",	110),
			p2("CHAISE",	"C001",	50),
			p3("FAUTEUIL",	"F001", 70);

	std::cout << p1.toString() << std::endl << p2.toString() << std::endl << p3.toString() << std::endl;

	// Pour le magasin :
	Magasin magasin1("Anglet");
	magasin1.addProduit(&p1);
	magasin1.addProduit(&p2, 2);
	magasin1.addProduit(&p3, 3);

	std::cout << std::endl << magasin1.toString() << std::endl;

	//Pour le panier : 
	Panier panier1(&magasin1);
	panier1.acheter(&p1, 2);
	panier1.acheter(&p2);
	panier1.acheter(&p3);

	panier1.editer();

	return 0;
}