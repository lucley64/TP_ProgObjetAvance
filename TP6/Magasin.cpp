#include "Magasin.h"

Magasin::Magasin(const Magasin& magasin):
	adresse(magasin.adresse)
{
	stock.insert(magasin.stock.begin(), magasin.stock.end());
}

Magasin::Magasin(Adresse adresse, Stock stock)
{
}

std::string Magasin::toString(std::string message)
{
	return std::string();
}

void Magasin::addProduit(Produit*, Quantite)
{
}
