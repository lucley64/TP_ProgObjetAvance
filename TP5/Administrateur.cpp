#include "Administrateur.h"

Administrateur::Administrateur(string identite, string fonction) :
	identite(identite),
	fonction(fonction) {}

Administrateur::Administrateur(const Administrateur& admin) :
	identite(admin.identite),
	fonction(admin.fonction) {}

Administrateur::~Administrateur() {}

Administrateur& Administrateur::operator=(const Administrateur& admin) {
	identite = admin.identite;
	fonction = admin.fonction;

	return *this;
}

string Administrateur::toString(string message)
{
	return identite + " | " + fonction;
}