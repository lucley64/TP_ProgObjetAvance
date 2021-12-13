#ifndef POINT_H
#define POINT_H

#include "GraphiqueSimple.h"

class Point :public GraphiqueSimple{
private:
	int ligne, colone;
	char motif;

public:
	Point(int, int, char);
	void definir(int, int);
	void deplacerDe(int, int);

protected:
	void dessiner(bool);
};

#endif // !POINT_H
