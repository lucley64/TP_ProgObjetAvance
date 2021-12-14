#include "Terminal.h"

#include <iostream>

void Terminal::charLigneColone(int ligne, int colone, char motif) {
	std::cout << '\033' << '[' << ligne << ';' << colone << 'H' << motif;
}

void Terminal::clear() {
	std::cout << '\033' << "[H" << '\033' << "[2J";
}