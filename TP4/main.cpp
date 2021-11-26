#include <iostream>
#include <map>
#include <list>
#include "Produits.h"

using namespace std;

void exempleDeFind();
void exempleDeFindIf();
bool memeReference(Produits);

typedef string Libelle;
typedef string Reference;
typedef int Prix;
typedef int Poids;

Reference referenceRecherchee;

int main() {
	cout << "----------Partie 1----------" << endl;
	exempleDeFind();

	cout << endl << "----------Partie 1----------" << endl;
	exempleDeFindIf();

	return 0;
}

void exempleDeFind() {
	typedef map<Reference, pair<Libelle, Prix>> MapDeProduits;

	MapDeProduits unMapDeProduits;

	unMapDeProduits.insert(MapDeProduits::value_type("AB128", MapDeProduits::value_type::second_type("Tomate", 1)));
	unMapDeProduits.insert(MapDeProduits::value_type("FR256", MapDeProduits::value_type::second_type("Patate", 2)));
	unMapDeProduits.insert(MapDeProduits::value_type("SC955", MapDeProduits::value_type::second_type("Pomme", 1)));

	referenceRecherchee = "AB128";
	MapDeProduits::iterator existe;
	existe = unMapDeProduits.find(referenceRecherchee);
	if (!(existe == unMapDeProduits.end())) {
		cout << existe->first << ", " << existe->second.first << ", " << existe->second.second << endl;
	}
	else {
		cout << referenceRecherchee << " : Echec de la recherche" << endl;
	}

	referenceRecherchee = "UF596";
	existe = unMapDeProduits.find(referenceRecherchee);
	if (!(existe == unMapDeProduits.end())) {
		cout << existe->first << ", " << existe->second.first << ", " << existe->second.second << endl;
	}
	else {
		cout << referenceRecherchee << " : Echec de la recherche" << endl;
	}


}

void exempleDeFindIf() {
	typedef list<Produits> ListeDeProduits;
	ListeDeProduits uneListeDeProduits;
	ListeDeProduits::iterator existe;


	uneListeDeProduits.push_back(ListeDeProduits::value_type("AB128", "Tomate", 1));
	uneListeDeProduits.push_back(ListeDeProduits::value_type("FR256","Patate", 2));
	uneListeDeProduits.push_back(ListeDeProduits::value_type("SC955", "Pomme", 1));

	ListeDeProduits::iterator borneDebut = uneListeDeProduits.begin();
	ListeDeProduits::iterator borneFin = uneListeDeProduits.end();

	referenceRecherchee = "AB128";

	existe = find_if(borneDebut, borneFin, memeReference);

	if (!(existe == uneListeDeProduits.end())) {
		cout << existe->toString() << endl;
	}
	else {
		cout << referenceRecherchee << " : Echec de la recherche" << endl;
	}

	referenceRecherchee = "UF596";

	existe = find_if(borneDebut, borneFin, memeReference);

	if (!(existe == uneListeDeProduits.end())) {
		cout << existe->toString() << endl;
	}
	else {
		cout << referenceRecherchee << " : Echec de la recherche" << endl;
	}
}

bool memeReference(Produits unProduit) {
	return unProduit.m_reference == referenceRecherchee;
}