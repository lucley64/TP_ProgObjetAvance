#include "Hotel.h"
#include <algorithm>

bool memeNumero(Chambre);

Hotel::Hotel(const Hotel& hotel) :
	nom(hotel.nom),
	adresse(hotel.adresse) {
	lesAdministrateurs.insert(hotel.lesAdministrateurs.begin(), hotel.lesAdministrateurs.end());

	set<Chambre*>::iterator chambre = hotel.mesChambres.begin();
	for (; chambre != hotel.mesChambres.end(); chambre++) {
		mesChambres.insert(new Chambre(**chambre));
	}
}

Hotel::Hotel(string nom, string adresse) :
	nom(nom),
	adresse(adresse){}

Hotel::~Hotel() {

}

Hotel& Hotel::operator=(const Hotel& hotel) {
	nom = hotel.nom;
	adresse = hotel.adresse;

	lesAdministrateurs.insert(hotel.lesAdministrateurs.begin(), hotel.lesAdministrateurs.end());

	set<Chambre*>::iterator chambre;
	for (chambre = hotel.mesChambres.begin(); // Initialisation
		chambre != hotel.mesChambres.end();  // Condition de fin
		chambre++) {                               // Progression
	   /// Traitement
		mesChambres.insert(new Chambre(**chambre)); // Ins�re une chambre sur le mod�le de la chambre courante
	}

	return *this;
}

bool Hotel::administrePar(Administrateur* admin) {
	return (lesAdministrateurs.insert(admin).second);
}

bool Hotel::inclutChambre(Chambre* chambre) {
	return (mesChambres.insert(chambre).second);
}

bool Hotel::modifierPrixChambre(string numero, unsigned short int prix) {
	bool modification = false;

	set<Chambre*>::iterator chambre;
	for (chambre = mesChambres.begin(); chambre != mesChambres.end(); chambre++) {
		if ((*chambre)->numero == numero) {
			(*chambre)->prix = prix;
			modification = true;
			break;
		}
	}

	return modification;
}

string Hotel::toString(string message) {
	string resultat = message;

	/// Int�gre nom et adresse
	resultat += nom + " | " + adresse + "\n";

	/// Int�gre lesAdministrateurs
	set<Administrateur*>::iterator admin;
	for (admin = lesAdministrateurs.begin(); admin != lesAdministrateurs.end(); admin++) {
		resultat += (*admin)->toString("ADMIN : ") + "\n";
	}
	/// Int�gre les chambres
	set<Chambre*>::iterator chambre;
	for (chambre = mesChambres.begin(); chambre != mesChambres.end(); chambre++) {
		resultat += (*chambre)->toString("CHAMBRE : ") + "\n";
	}
	return resultat;
}

