#include "Chambre.h"

Chambre::Chambre(string numero, string etage, unsigned short int prix) :
	numero(numero),
	etage(etage),
	prix(prix){}

Chambre::Chambre(const Chambre& chambre) :
	numero(chambre.numero),
	etage(chambre.etage),
	prix(chambre.prix){}

Chambre::~Chambre() {}

Chambre& Chambre::operator=(const Chambre& chambre) {
	numero = chambre.numero;
	etage = chambre.etage;
	prix = chambre.prix;

	return *this;
}