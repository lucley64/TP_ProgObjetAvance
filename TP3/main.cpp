#include <list>
#include <map>
#include <iostream>

using namespace std;

void listeSimple();
void listePaires();
void leMap();

int main() {
	cout << "une liste simple : " << endl << "----------" << endl;
	listeSimple();
	
	cout << "----------" << endl << endl << "une liste de paires : " << endl << "----------" << endl;
	listePaires();

	cout << "----------" << endl << endl << "une map : " << endl << "----------" << endl;
	leMap();
	return 0;
}

void listeSimple() {
	typedef list<string> ListeS;

	ListeS uneListeS;

	uneListeS.push_back(ListeS::value_type("Pantxika"));
	uneListeS.push_back(ListeS::value_type("Yann"));
	uneListeS.push_back(ListeS::value_type("Philippe"));
	uneListeS.push_back(ListeS::value_type("Patrick"));

	ListeS::iterator unPointeur;

	unPointeur = uneListeS.begin();

	while (unPointeur != uneListeS.end()) {
		cout << *unPointeur << endl;
		unPointeur++;
	}
}

void listePaires() {
	typedef list<pair<string, string>> ListeP;

	ListeP uneListeP;

	uneListeP.push_back(ListeP::value_type("Pantxika", "06.01.01.01.01"));
	uneListeP.push_back(ListeP::value_type("Yann", "06.02.02.02.02"));
	uneListeP.push_back(ListeP::value_type("Philippe", "06.03.03.03.03"));
	uneListeP.push_back(ListeP::value_type("Patrick", "06.04.04.04.04"));

	ListeP::iterator unPointeur = uneListeP.begin();

	while (unPointeur != uneListeP.end()) {
		cout << unPointeur->first << ", " << unPointeur->second << endl;
		unPointeur++;
	}
}

void leMap() {
	typedef map<string, string> Annuaire;

	Annuaire unAnnuaire;

	pair<Annuaire::iterator, bool> resultatInsert;

	resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
	if (resultatInsert.second) {
		cout << "insertion BIEN realisee" << endl;
	}
	else {
		cout << "insertion MAL realisee" << endl;
	}

	resultatInsert = unAnnuaire.insert(Annuaire::value_type("Pantxika", "06.01.01.01.01"));
	if (resultatInsert.second) {
		cout << "insertion BIEN realisee" << endl;
	}
	else {
		cout << "insertion MAL realisee" << endl;
	}

	resultatInsert = unAnnuaire.insert(Annuaire::value_type("Yann", "06.02.02.02.02"));
	if (resultatInsert.second) {
		cout << "insertion BIEN realisee" << endl;
	}
	else {
		cout << "insertion MAL realisee" << endl;
	}

	resultatInsert = unAnnuaire.insert(Annuaire::value_type("Philippe", "06.03.03.03.03"));
	if (resultatInsert.second) {
		cout << "insertion BIEN realisee" << endl;
	}
	else {
		cout << "insertion MAL realisee" << endl;
	}

	resultatInsert = unAnnuaire.insert(Annuaire::value_type("Patrick", "06.04.04.04.04"));
	if (resultatInsert.second) {
		cout << "insertion BIEN realisee" << endl;
	}
	else {
		cout << "insertion MAL realisee" << endl;
	}

	Annuaire::iterator unPointeur = unAnnuaire.begin();

	while (unPointeur != unAnnuaire.end()) {
		cout << unPointeur->second << endl;
		unPointeur++;
	}


}