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

		virtual ~Individu();

		void setNom(std::string);
		std::string getNom();

		void setPrenom(std::string);
		std::string getPrenom();


		std::string toString();

		std::string toStringAndLink();

		//Link Methods : 
		void majMaVoiture(Voiture*);

		void supprimerLien();

		void setMaVoiture(Voiture*);

		Voiture* getMaVoiture();
};


#endif // !INDIVIDU_H