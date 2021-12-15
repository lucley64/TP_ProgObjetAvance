#include "GraphiqueCompose.h"

GraphiqueCompose::GraphiqueCompose() {
	enfants.clear();
}

bool GraphiqueCompose::ajouter(Graphique* g) {
	bool retour = false;
	if (g) {
		retour = enfants.insert(std::set<Graphique*>::value_type(g)).second;
	}
	return retour;
}

bool GraphiqueCompose::supprimer(Graphique* g) {
	bool retour = false;
	if (g) {
		retour = enfants.erase(g) > 1;
	}
	return retour;
}

bool GraphiqueCompose::jeSuisCompose() {
	return false;
}

void GraphiqueCompose::afficher() {
	std::set<Graphique*>::iterator enfant;
	for (enfant = enfants.begin(); enfant != enfants.end(); enfant++) {
		(*enfant)->afficher();
	}
}

void GraphiqueCompose::effacer() {
	std::set<Graphique*>::iterator enfant;
	for (enfant = enfants.begin(); enfant != enfants.end(); enfant++) {
		(*enfant)->effacer();
	}
}

void GraphiqueCompose::deplacerDe(int ligne, int colonne) {
	std::set<Graphique*>::iterator enfant;
	for (enfant = enfants.begin(); enfant != enfants.end(); enfant++) {
		(*enfant)->deplacerDe(ligne, colonne);
	}
}
