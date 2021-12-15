#include "Ligne.h"
#include "Terminal.h"

Ligne::Ligne(int ligne, int colonne, int longueur, char direction, char sens, char motif):
	Point(ligne, colonne, motif) {
	this->longueur = longueur;
	this->direction = direction;
	this->sens = sens;
}

void Ligne::definir(int ligne, int colonne, int longueur, char direction, char sens) {
	Point::definir(ligne, colonne);
	this->longueur = longueur;
	this->direction = direction;
	this->sens = sens;
}

void Ligne::deplacerDe(int ligne, int colonne, int longueur, char direction, char sens) {
	Point::deplacerDe(ligne, colonne);
	definir(longueur, direction, sens);
}

void Ligne::definir(int, char, char) {
	this->longueur = longueur;
	this->direction = direction;
	this->sens = sens;
}

void Ligne::dessiner(bool marquer) {
	if (marquer) {
		Terminal::charLigneColonneLongueurDirectionSens(ligne, colonne, longueur, motif, direction, sens);
	}
	else {
		Terminal::clear();
	}
}
