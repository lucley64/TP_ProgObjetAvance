#ifndef GRAPHIQUE_SIMPLE_H
#define GRAPHIQUE_SIMPLE_H

#include "Graphique.h"

class GraphiqueSimple :public Graphique{
public:
	void afficher();
	void effacer();
	virtual void deplacerDe(int , int ) = 0;
	virtual void dessiner(bool) = 0;
};

#endif //!GRAPHIQUE_SIMPLE_H