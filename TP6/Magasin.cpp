#include "Magasin.h"
#include <string>

Magasin::Magasin(const Magasin& magasin):
	adresse(magasin.adresse)
{
	stock.insert(magasin.stock.begin(), magasin.stock.end());
}

Magasin::Magasin(Adresse adresse, Stock stock) :
	adresse(adresse)
{
	stock.insert(stock.begin(), stock.end());
}

std::string Magasin::toString(std::string message)
{
	std::string retour = message + adresse + "\n" + "Stock : \n";
	Stock::iterator iter = stock.begin();
	while (iter != stock.end())
	{
		retour += iter->first->toString() + " : " + std::to_string(iter->second) + "\n";
		iter++;
	}

	return retour;
}

void Magasin::addProduit(Produit* produit, Quantite qt)
{
	if (!(stock.insert(Stock::value_type(produit, qt)).second))
	{
		Quantite qtStock =qt + stock.find(produit)->second;
		stock.erase(produit);
		stock.insert(Stock::value_type(produit, qtStock));
	}
}
