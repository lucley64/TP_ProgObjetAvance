#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

class Graphique {
public:
	virtual bool ajouter(Graphique*);
	virtual bool supprimer(Graphique*);
	virtual bool jeSuisCompose();

	virtual void afficher() = 0;
	virtual void effacer() = 0;
	virtual void deplacerDe(int, int) = 0;

};

#endif // !GRAPHIQUE_H
