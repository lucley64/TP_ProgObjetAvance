#include "Facture.h"
#include <string>

Facture::Facture(ReferenceFacture ref, IdentifantClient idCli, Date date, MontantFacture montant) :
	refFacture(ref),
	idClient(idCli),
	date(date),
	montant(montant) {}

Facture::Facture(const Facture& facture):
	refFacture(facture.refFacture),
	idClient(facture.idClient),
	date(facture.date),
	montant(facture.montant) {}

Facture Facture::operator=(const Facture& facture) {
	refFacture = facture.refFacture;
	idClient = facture.idClient;
	date = facture.date;
	montant = facture.montant;

	return *this;
}

string Facture::toString(string message) {
	return message + refFacture + ", " + idClient + ", " + date + ", " + to_string(montant);
}
