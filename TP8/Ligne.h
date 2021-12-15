#ifndef LIGNE_H
#define LIGNE_H

#include <iostream>

#include "Point.h"

class Ligne :public Point {
private:
	int longueur;
	char direction;
	char sens;

public:
	Ligne(int, int, int, char = 'H', char = '+', char = '-');
	void definir(int, int, int, char, char);
	void deplacerDe(int, int, int, char ='H', char ='P');

protected:
	void definir(int, char, char);
	void dessiner(bool);
};

#endif // !LIGNE_H
