#ifndef VOITURE_H
#define VOITURE_H

#include <iostream>
#include "Individu.h"

class Individu;

class Voiture {
	private:
		std::string m_marque;
		std::string m_plaque;
		Individu* m_monPilote;

	public:
		Voiture(std::string, std::string);

		void setMarque(std::string);
		std::string getMarque();

		void setPlaque(std::string);
		std::string getPlaque();

		void setMonPilote(Individu*);
		Individu* getMonPilote();

		std::string toString();

		std::string toStringAndLink();
};

#endif // !VOITURE_H