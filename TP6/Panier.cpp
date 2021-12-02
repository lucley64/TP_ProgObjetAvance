#include "Panier.h"
#include <string>

Panier::Panier(const Panier& panier):
	magasin(panier.magasin),
	achats(panier.achats){}

Panier::Panier(Magasin* magasin, Achats achats) :
	achats(achats),
	magasin(magasin) {}

void Panier::editer(std::string message)
{
	std::cout << message << "Panier dans : " << magasin->toString() << std::endl << "Contenu du panier : " << std::endl;
	Prix cout = 0;
	Achats::iterator iter = achats.begin();
	for (; iter != achats.end(); iter++) {
		std::cout << iter->first->toString() << " : " << std::to_string(iter->second) << std::endl;
		cout += (iter->first->prix * iter->second);
	}
	std::cout << "Prix total : " << cout << std::endl;
}

bool Panier::acheter(Produit* produit, Quantite qt)
{
	bool retour = false;
	Stock::iterator existe;
	existe = magasin->stock.find(produit);
	if ((existe != magasin->stock.end()) && (existe->second >= qt)) {
		retour = achats.insert(Achats::value_type(produit, qt)).second;
		if (!retour) {
			Quantite quantiTot = qt + achats.find(produit)->second;
			achats.erase(produit);
			retour = achats.insert(Achats::value_type(produit, quantiTot)).second;
		}
		Quantite qtStock = existe->second - qt;
		magasin->stock.erase(produit);
		if (qt > 0) {
			magasin->addProduit(produit, qtStock);
		}

	}
	return retour;
}
