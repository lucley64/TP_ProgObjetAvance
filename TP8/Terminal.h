#ifndef TERMINAL_H
#define TERMINAL_H

#include <iostream>

class Terminal {
public :
	static void charLignecolonne(int, int, char);
	static void stringLigneColonne(int l, int c, std::string chaine);
	static void charLigneColonneLongueurDirectionSens(int, int, int, char, char, char);
	static void clear();
};

#endif // !TERMINAL_H
