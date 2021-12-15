#include "Terminal.h"



void Terminal::charLignecolonne(int ligne, int colonne, char motif) {
	std::cout << '\033' << '[' << ligne << ';' << colonne << 'H' << motif;
}

void Terminal::stringLigneColonne(int l, int c, std::string chaine) {
	std::cout << '\033' << '[' << l << ';' << c << 'H' << chaine;
}

void Terminal::charLigneColonneLongueurDirectionSens(int ligne, int colonne, int longueur, char motif, char direction, char sens) {
	for (int i = 0; i < longueur; i++) {
		if (direction == 'H') {
			if (sens == '+') {
				colonne += 1;
			}
			else if (sens == '-') {
				colonne -= 1;
			}
		}
		else if (direction == 'V') {
			if (sens == '+') {
				ligne += 1;
			}
			else if (sens == '-') {
				ligne -= 1;
			}
		}
		std::cout << '\033' << '[' << ligne << ';' << colonne << 'H' << motif;
	}
}



void Terminal::clear() {
	std::cout << '\033' << "[H" << '\033' << "[2J";
}
