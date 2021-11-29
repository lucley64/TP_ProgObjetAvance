#include "Panier.h"

Panier::Panier(const Panier& panier):
	magasin(panier.magasin)
{
	Achats::iterator iter = panier.achats.begin();
	for (;iter!=panier.achats.end(); iter++)
	{
		achats.push_back(*iter);
	}
}

Panier::Panier(Achats achats, Magasin* magasin)
{
}

std::string Panier::toString()
{
	return std::string();
}

void Panier::addProduit(Produit* produit, Quantite qt)
{
}
