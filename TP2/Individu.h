#ifndef INDIVIDU_H
#define INDIVIDU_H

#include <iostream>
#include "Voiture.h"

class Voiture;

class Individu {
	private:
		std::string m_nom;
		std::string m_prenom;

		Voiture* m_maVoiture;

	public:
		Individu(std::string, std::string);

		void setNom(std::string);
		std::string getNom();

		void setPrenom(std::string);
		std::string getPrenom();

		void setMaVoiture(Voiture*);
		Voiture* getMaVoiture();

		std::string toString();

		std::string toStringAndLink();
};


#endif // !INDIVIDU_H