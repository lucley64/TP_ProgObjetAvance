#include "Individu.h"

Individu::Individu(std::string nom, std::string prenom) {
	setNom(nom);
	setPrenom(prenom);
}

void Individu::setNom(std::string nom) {
	m_nom = nom;
}

std::string Individu::getNom() {
	return m_nom;
}

void Individu::setPrenom(std::string prenom) {
	m_prenom = prenom;
}

std::string Individu::getPrenom() {
	return m_prenom;
}


std::string Individu::toString() {
	return "Nom : " + getNom() + ", Prenom : " + getPrenom();
}

std::string Individu::toStringAndLink() {
	std::string retour = toString();
	Voiture* maVoiture = getMaVoiture();

	if (maVoiture) {
		retour += ", " + maVoiture->toString();
	}

	return retour;
}

void Individu::majMaVoiture(Voiture* voiture) {
	m_maVoiture = voiture;
}

void Individu::supprimerLiens() {
	Voiture* maVoiture = getMaVoiture();
	if (maVoiture) {
		maVoiture->majMonPilote(nullptr);
		majMaVoiture(nullptr);
	}
}

void Individu::setMaVoiture(Voiture* voiture) {
	supprimerLiens();
	if (voiture) {
		voiture->supprimerLien();
		voiture->majMonPilote(this);
	}
	majMaVoiture(voiture);
}

Voiture* Individu::getMaVoiture() {
	return m_maVoiture;
}