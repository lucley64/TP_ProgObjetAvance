#include <iostream>

#include "Outils.h"
#include "Sportif.h"
#include "SportifMenteur.h"

void afficheAgeSportifParValeur(Sportif);
void afficheAgeSportifParReference(Sportif &);
void afficheAgeSportifParAdresse(Sportif*);

int main() {
	
	Sportif sportif1("Nunez", "Dorian", 1999);
	SportifMenteur sportif2("Graire", "Antoine", 2007, "tuteur");
	SportifMenteur sportif3("Marche", "Jules", 2000, "tuteur");

	std::cout << "Pour sportif1 : " << std::endl;
	std::cout << "Par valeur : " << std::endl;
	afficheAgeSportifParValeur(sportif1);

	std::cout << "Par Reference : " << std::endl;
	afficheAgeSportifParReference(sportif1);

	std::cout << "Par Adresse : " << std::endl;
	afficheAgeSportifParAdresse(&sportif1);

	std::cout << "Pour sportif2 : " << std::endl;
	std::cout << "Par valeur : " << std::endl;
	afficheAgeSportifParValeur(sportif2);

	std::cout << "Par Reference : " << std::endl;
	afficheAgeSportifParReference(sportif2);

	std::cout << "Par Adresse : " << std::endl;
	afficheAgeSportifParAdresse(&sportif2);

	std::cout << "Pour sportif3 : " << std::endl;
	std::cout << "Par valeur : " << std::endl;
	afficheAgeSportifParValeur(sportif3);

	std::cout << "Par Reference : " << std::endl;
	afficheAgeSportifParReference(sportif3);

	std::cout << "Par Adresse : " << std::endl;
	afficheAgeSportifParAdresse(&sportif3);


	return 0;
}

void afficheAgeSportifParValeur(Sportif sportif) {
	std::cout << "Annee en cours : " << Outils::anneeActuelle() << std::endl;
	std::cout << "Annee de naissance : " << sportif.getAnneeNaissance() << std::endl;
	std::cout << "Age : " << sportif.getAge() << std::endl;
}

void afficheAgeSportifParReference(Sportif& sportif) {
	std::cout << "Annee en cours : " << Outils::anneeActuelle() << std::endl;
	std::cout << "Annee de naissance : " << sportif.getAnneeNaissance() << std::endl;
	std::cout << "Age : " << sportif.getAge() << std::endl;
}

void afficheAgeSportifParAdresse(Sportif* sportif) {
	std::cout << "Annee en cours : " << Outils::anneeActuelle() << std::endl;
	std::cout << "Annee de naissance : " << sportif->getAnneeNaissance() << std::endl;
	std::cout << "Age : " << sportif->getAge() << std::endl;
}
