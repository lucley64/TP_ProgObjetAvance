#include "Point.h"
#include "Terminal.h"

Point::Point(int ligne, int colone, char motif):
	motif(motif) {
	definir(ligne, colone);
}

void Point::dessiner(bool marquer) {
	if (marquer) {
		Terminal::charLigneColone(ligne, colone, motif);
	}
	else {
		Terminal::clear();
	}
	
}

void Point::definir(int ligne, int colone) {
	this->ligne = ligne;
	this->colone = colone;
}

void Point::deplacerDe(int ligne, int colone) {
	definir(this->ligne + ligne, this->colone + colone);
}