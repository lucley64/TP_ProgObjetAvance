#ifndef PANIER_H
#define PANIER_H

#include <iostream>
#include <list>

#include "Produit.h"
#include "Magasin.h"

typedef std::list<std::pair<Produit*, Quantite>> Achats;

class Panier {
public:
	Achats achats;
	Magasin* magasin;

	Panier(const Panier& panier);
	Panier(Achats achats, Magasin* magasin);

	std::string toString();
	void addProduit(Produit* produit, Quantite qt = 1);

};

#endif // !PANIER_H
