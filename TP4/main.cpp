#include <iostream>
#include <map>
#include <list>
#include "Produits.h"
#include "Piece.h"
#include <algorithm>

using namespace std;

void exempleDeFind();
void exempleDeFindIf();
bool memeReference(Produits);
void afficher(Piece*);
void surPoids(Piece*);
bool tropCestTrop(Piece* Piece);
void exempleForEachEtPartition();

typedef string Libelle;
typedef string Reference;
typedef int Prix;
typedef int Poids;

Reference referenceRecherchee;

int main() {
	cout << "----------Partie 1----------" << endl;
	exempleDeFind();

	cout << endl << "----------Partie 2----------" << endl;
	exempleDeFindIf();

	cout << endl << "----------Partie 3----------" << endl;
	exempleForEachEtPartition();

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

void afficher(Piece* pPiece) {
	cout << pPiece->toString() << endl;
}

void surPoids(Piece* pPiece) {
	if (pPiece->m_poid > 80) {
		pPiece->m_prix = pPiece->m_prix * 1.1;
	}
}

bool tropCestTrop(Piece* pPiece) {
	return pPiece->m_prix > 100;
}

void exempleForEachEtPartition() {
	Piece piece1("DE895", "Piece de collection allemande", 150, 100);
	Piece piece2("FR856", "Piece de collection francaise", 36, 150);
	Piece piece3("LU995", "Piece de collection francaise", 50, 75);
	
	typedef list<Piece*> ListeDePieces;

	ListeDePieces unelisteDePieces;

	unelisteDePieces.push_back(ListeDePieces::value_type(&piece1));
	unelisteDePieces.push_back(ListeDePieces::value_type(&piece2));
	unelisteDePieces.push_back(ListeDePieces::value_type(&piece3));

	ListeDePieces::iterator debut = unelisteDePieces.begin(), fin = unelisteDePieces.end(), debutDeuxiemePartie;

	cout << endl << "Afficher toutes les pieces de la liste" << endl;
	for_each(debut, fin, afficher);

	cout << endl << "Appliquer surPoids a toutes les pieces de la liste" << endl;
	for_each(debut, fin, surPoids);

	cout << endl << "Reorganiser la liste et placer en tête de liste les pieces dont le prix depasse 100 euros" << endl;
	debutDeuxiemePartie = partition(debut, fin, tropCestTrop);

	cout << endl << "Afficher les pieces ayant un prix superieur a 100 euros" << endl;
	for_each(debut, debutDeuxiemePartie, afficher);

	cout << endl << "Afficher les autres pieces" << endl;
	for_each(debutDeuxiemePartie, fin, afficher);


}