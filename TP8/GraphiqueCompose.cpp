#include "GraphiqueCompose.h"

GraphiqueCompose::GraphiqueCompose() {
	enfants.clear();
}

bool GraphiqueCompose::ajouter(Graphique* g) {
	return enfants.insert(std::set<Graphique*>::value_type(g)).second;
}

bool GraphiqueCompose::supprimer(Graphique* g) {
	return enfants.erase(g) > 1;
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

void GraphiqueCompose::deplacerDe(int ligne, int colone) {
	std::set<Graphique*>::iterator enfant;
	for (enfant = enfants.begin(); enfant != enfants.end(); enfant++) {
		(*enfant)->deplacerDe(ligne, colone);
	}
}
