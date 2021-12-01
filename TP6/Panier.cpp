#include "Panier.h"

Panier::Panier(const Panier& panier):
	magasin(panier.magasin),
	achats(panier.achats){}

Panier::Panier(Magasin* magasin, Achats achats) :
	achats(achats),
	magasin(magasin) {}

void Panier::editer(std::string message)
{
	std::cout << message << "Panier dans : " << magasin->adresse << std::endl;
	Prix cout = 0;
	Achats::iterator iter = achats.begin();
	for (; iter != achats.end(); iter++) {
		std::cout << iter->first->toString() << std::endl;
		cout += (iter->first->prix * iter->second);
	}
	std::cout << "Prix total : " << cout << "€" << std::endl;
}

bool Panier::acheter(Produit* produit, Quantite qt)
{
	return achats.insert(Achats::value_type(produit, qt)).second;
}
