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


		std::string toString();

		std::string toStringAndLink();

		//Link methods :
		void majMonPilote(Individu*);

		void supprimerLien();

		void setMonPilote(Individu*);

		Individu* getMonPilote();
};

#endif // !VOITURE_H