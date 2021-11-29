#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>

typedef std::string	Libelle;
typedef std::string	Code;
typedef float		Prix;


class Produit {
public:
	Libelle libelle;
	Code code;
	Prix prix;

	Produit(const Produit& produit);
	Produit(Libelle libelle ="", Code code ="", Prix prix =0);

	std::string toString(std::string message="");
};

#endif // !PRODUIT_H