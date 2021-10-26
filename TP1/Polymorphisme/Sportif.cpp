#include "Sportif.h"
#include "Outils.h"
#include <string>


Sportif::Sportif(std::string nom, std::string prenom, int anneeNaissance)
{
	setNom(nom);
	setPrenom(prenom);
	setAnneeNaissance(anneeNaissance);
}

Sportif::~Sportif()
{
}

std::string Sportif::getNom()
{
	return m_nom;
}

void Sportif::setNom(std::string nom)
{
	m_nom = nom;
}

std::string Sportif::getPrenom()
{
	return m_prenom;
}

void Sportif::setPrenom(std::string prenom)
{
	m_prenom = prenom;
}

int Sportif::getAnneeNaissance()
{
	return m_anneeNaissance;
}

void Sportif::setAnneeNaissance(int anneeNaissance)
{
	m_anneeNaissance = anneeNaissance;
}

std::string Sportif::toString()
{
	return "Nom : " + getNom() + ", Prenom : " + getPrenom() + ", Annee de naissance : " + std::to_string(getAnneeNaissance());
}

int Sportif::getAge()
{
	return (Outils::anneeActuelle()-getAnneeNaissance());
}

