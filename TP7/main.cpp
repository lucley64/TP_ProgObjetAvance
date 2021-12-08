#include <iostream>
#include "SingletonDirecteurIUT.h"

using namespace std;

int main() {
	SingletonDirecteurIUT* directeur;
	SingletonDirecteurIUT* leChef;

	directeur = SingletonDirecteurIUT::getInstance();

	directeur->setNom("Luthon");

	leChef = SingletonDirecteurIUT::getInstance();

	cout << leChef->toString("Le chef est : ") << endl;

	SingletonDirecteurIUT::killInstance();

	return 0;
}