#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <list>

#include "Produit.h"
#include "Magasin.h"

typedef std::map<Produit*, Quantite> Achats;

class Panier {
public:
	Achats achats;
	Magasin* magasin;

	Panier(const Panier& panier);
	Panier(Magasin* magasin, Achats achats = Achats());

	void editer(std::string message="");
	bool acheter(Produit* produit, Quantite qt = 1);

};

#endif // !PANIER_H
