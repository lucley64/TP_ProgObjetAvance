#ifndef SPORTIF_MENTEUR_H
#define SPORTIF_MENTEUR_H


#include "Sportif.h"

class SportifMenteur : public Sportif {
/// ATTRIBUTS
protected:
	std::string m_tuteur;

/// METHODES 
public:
	/* CONSTRUCTEUR */
	SportifMenteur(std::string, std::string, int, std::string);

	/* DESTRUCTEUR */
	virtual ~SportifMenteur();

	/* ENCAPSULATION */
	std::string getTuteur();
	void setTuteur(std::string);

	/* METHODES USUELLES */
	int getAge();
};

#endif // !SPORTIF_MENTEUR_H