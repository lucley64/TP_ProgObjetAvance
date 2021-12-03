#include "Hotel.h"

int main() {
	//1
	Hotel* hotel = new Hotel("LesDormeurs", "Terrain Instable, 75.000 PARIS");
	
	cout << hotel->toString("\n----------Creation de l'hotel----------\n") << endl;

	//2
	Administrateur admin1("Etcheverry", "President");
	Administrateur admin2("Dagorret", "Presidente");

	hotel->administrePar(&admin1);
	hotel->administrePar(&admin2);

	cout << hotel->toString("\n----------Ajout des admins----------\n") << endl;

	//3
	Chambre chambre1("Campagne", "Rez-de-chaussee", 50);
	Chambre chambre2("Royale", "Etage 1", 100);
	Chambre chambre3("Solaire", "Etage 2", 150);

	hotel->inclutChambre(&chambre1);
	hotel->inclutChambre(&chambre2);
	hotel->inclutChambre(&chambre3);

	cout << hotel->toString("\n----------Ajout des chambres----------\n") << endl;

	//4
	Hotel hotelBis(*hotel);

	cout << hotelBis.toString("\n----------Hotel bis par cteur par copie----------\n") << endl;

	//5-6
	Hotel hotelTer = *hotel;

	cout << hotelTer.toString("\n----------Hotel Ter par l'operateur =----------\n") << endl;

	//7
	hotelBis.modifierPrixChambre("Campagne", 70);
	hotelTer.modifierPrixChambre("Solaire", 170);

	cout << hotelBis.toString("\n----------Modification du prix des chambres Campagnes a 70----------\n") << endl;
	cout << hotelTer.toString("\n----------Modification du prix des chambres Solaires a 170----------\n") << endl;

	//8
	admin1.fonction = "President Adjoin";

	cout << admin1.toString("\n----------Admin1 change de fonction----------\n") << endl;
	cout << "Les hotels sont donc mis a jours" << endl;
	cout << hotel->toString("\n----------Pour hotel----------\n") << endl;
	cout << hotelBis.toString("\n----------Pour hotelBis----------\n") << endl;
	cout << hotelTer.toString("\n----------Pour hotelTer----------\n") << endl;

	//9 
	delete hotel;

	return 0;
}