#include "Produits.h"
#include <string>

Produits::Produits(std::string reference, std::string libelle, int prix):
	m_reference(reference),
	m_libelle(libelle),
	m_prix(prix)
{
}

std::string Produits::toString()
{
	return m_reference + ", " + m_libelle + ", " + std::to_string(m_prix);
}
