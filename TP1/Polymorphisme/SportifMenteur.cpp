#include "SportifMenteur.h"
#include "Outils.h"

SportifMenteur::SportifMenteur(std::string nom, std::string prenom, int anneeNaissance, std::string tuteur):
	Sportif(nom, prenom, anneeNaissance)
{
	setTuteur(tuteur);
}

SportifMenteur::~SportifMenteur()
{
}

std::string SportifMenteur::getTuteur()
{
	return m_tuteur;
}

void SportifMenteur::setTuteur(std::string tuteur)
{
	m_tuteur = tuteur;
}

int SportifMenteur::getAge()
{
	int age = Outils::anneeActuelle() - getAnneeNaissance();
	if (age < 18) {
		age = 18;
	}
	return age;
}
