#ifndef GRAPHIQUE_COMPOSE_H
#define GRAPHIQUE_COMPOSE_H

#include <set>

#include "Graphique.h"

class GraphiqueCompose :public Graphique{
private:
	std::set<Graphique*> enfants;

public:
	GraphiqueCompose();
	virtual bool ajouter(Graphique*);
	virtual bool supprimer(Graphique*);
	virtual bool jeSuisCompose();

	virtual void afficher();
	virtual void effacer();
	virtual void deplacerDe(int, int);
};

#endif // !GRAPHIQUE_COMPOSE_H
