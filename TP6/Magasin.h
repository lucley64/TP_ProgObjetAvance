#ifndef MAGASIN_H
#define MAGASIN_H

#include <iostream>
#include <map>

#include "Produit.h"

typedef std::string						Adresse;
typedef int								Quantite;
typedef std::map<Produit*, Quantite>	Stock;

class Magasin {
public:
	Adresse adresse;
	Stock	stock;

	Magasin(const Magasin& magasin);
	Magasin(Adresse adresse = "", Stock stock = Stock());

	std::string toString(std::string message = "");

	void addProduit(Produit*, Quantite = 1);

};

#endif // !MAGASIN_H
