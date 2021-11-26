#ifndef PRODUITS_H
#define PRODUITS_H

#include <iostream>

class Produits {
public:
	std::string m_reference;
	std::string m_libelle;
	int m_prix;

	Produits(std::string, std::string, int);

	std::string toString();

};

#endif // !PRODUITS_H