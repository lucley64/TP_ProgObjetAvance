#include "Point.h"
#include "Terminal.h"

Point::Point(int ligne, int colonne, char motif):
	motif(motif) {
	definir(ligne, colonne);
}

void Point::dessiner(bool marquer) {
	if (marquer) {
		Terminal::charLignecolonne(ligne, colonne, motif);
	}
	else {
		Terminal::clear();
	}
	
}

void Point::definir(int ligne, int colonne) {
	this->ligne = ligne;
	this->colonne = colonne;
}

void Point::deplacerDe(int ligne, int colonne) {
	definir(this->ligne + ligne, this->colonne + colonne);
}