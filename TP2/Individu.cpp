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

void Individu::setMaVoiture(Voiture* voiture) {
	m_maVoiture = voiture;
}

Voiture* Individu::getMaVoiture() {
	return m_maVoiture;
}

std::string Individu::toString() {
	return "Nom : " + getNom() + ", Prenom : " + getPrenom();
}
