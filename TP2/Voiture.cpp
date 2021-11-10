#include "Voiture.h"

Voiture::Voiture(std::string marque, std::string plaque) {
	setMarque(marque);
	setPlaque(plaque);
}

void Voiture::setMarque(std::string marque) {
	m_marque = marque;
}

std::string Voiture::getMarque() {
	return m_marque;
}

void Voiture::setPlaque(std::string plaque) {
	m_plaque = plaque;
}

std::string Voiture::getPlaque() {
	return m_plaque;
}


std::string Voiture::toString() {
	return "Marque : " + getMarque() + ", Plaque : " + getPlaque();
}

std::string Voiture::toStringAndLink() {
	std::string retour = toString();
	Individu* monPilote = getMonPilote();

	if (monPilote) {
		retour += ", " + monPilote->toString();
	}

	return retour;
}

void Voiture::majMonPilote(Individu* individu) {
	m_monPilote = individu;
}

void Voiture::supprimerLien() {
	Individu* monPilote = getMonPilote();
	if (monPilote) {
		monPilote->majMaVoiture(nullptr);
		majMonPilote(nullptr);
	}
}

void Voiture::setMonPilote(Individu* individu) {
	supprimerLien();
	if (individu) {
		individu->supprimerLiens();
		individu->majMaVoiture(this);
	}
	majMonPilote(individu);
}

Individu* Voiture::getMonPilote() {
	return m_monPilote;
}