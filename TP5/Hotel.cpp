#include "Hotel.h"
#include <algorithm>

void detruireChambre(Chambre*);

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
	set<Chambre*>::iterator debut = mesChambres.begin(), fin = mesChambres.end();
	for_each(debut, fin, detruireChambre);

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
		mesChambres.insert(new Chambre(**chambre)); // Insère une chambre sur le modèle de la chambre courante
	}

	return *this;
}

bool Hotel::administrePar(Administrateur* admin) {
	return (lesAdministrateurs.insert(admin).second);
}

bool Hotel::inclutChambre(Chambre* chambre) {
	return (mesChambres.insert(chambre).second);
}

void detruireChambre(Chambre* chambre) {
	delete chambre;
}
