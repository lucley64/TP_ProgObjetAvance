#include <iostream>
#include "Voiture.h"
#include "Individu.h"

int main() {
	
	Voiture voit1("RenaultClio", "123AB64");
	Voiture voit2("Peugeot106", "678CD96");
	Voiture voit3("CitroenPicasso", "456EF75");

	Individu ind1("Dupond", "Pierre");
	Individu ind2("Martin", "Louis");
	Individu ind3("Durand", "Marcel");

	std::cout << "Voiture 1 : " << voit1.toString() << std::endl;
	std::cout << "Voiture 2 : " << voit2.toString() << std::endl;
	std::cout << "Voiture 3 : " << voit3.toString() << std::endl;

	std::cout << "Individu 1 : " << ind1.toString() << std::endl;
	std::cout << "Individu 2 : " << ind2.toString() << std::endl;
	std::cout << "Individu 3 : " << ind3.toString() << std::endl;

	voit3.setMonPilote(&ind3);

	std::cout << "Plaque de la voiture de l'individu 3 : " << ind3.getMaVoiture()->getPlaque() << std::endl;

	voit3.setPlaque("77777NO22");

	std::cout << "Plaque de la voiture de l'individu 3 : " << ind3.getMaVoiture()->getPlaque() << std::endl;

	std::cout << "Individu 3 : " << ind3.toStringAndLink() << std::endl;

	std::cout << "Individu 2 : " << ind2.toStringAndLink() << std::endl;

	ind2.setMaVoiture(&voit3);

	std::cout << "Individu 3 : " << ind3.toStringAndLink() << std::endl;

	std::cout << "Individu 2 : " << ind2.toStringAndLink() << std::endl;

	return 0;
}