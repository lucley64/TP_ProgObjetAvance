#include "Produit.h"
#include <string>

Produit::Produit(const Produit& produit):
	libelle(produit.libelle),
	code(produit.code),
	prix(produit.prix){}

Produit::Produit(Libelle libelle, Code code, Prix prix):
	libelle(libelle),
	code(code),
	prix(prix){}

std::string Produit::toString(std::string message)
{
	return message + libelle + " | " + code + " | " + std::to_string(prix);
}
