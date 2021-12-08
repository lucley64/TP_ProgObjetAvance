#include "SingletonDirecteurIUT.h"

SingletonDirecteurIUT* SingletonDirecteurIUT::instance = nullptr;

SingletonDirecteurIUT::SingletonDirecteurIUT() :
	nom(""),
	prenom("") {}

SingletonDirecteurIUT::~SingletonDirecteurIUT() {}

void SingletonDirecteurIUT::setNom(string nom) {
	this->nom = nom;
}

void SingletonDirecteurIUT::setPrenom(string prenom) {
	this->prenom = prenom;
}

string SingletonDirecteurIUT::getNom() {
	return nom;
}

string SingletonDirecteurIUT::getPrenom() {
	return prenom;
}

string SingletonDirecteurIUT::toString(string message) {
	return message + nom + ", " + prenom;
}

SingletonDirecteurIUT* SingletonDirecteurIUT::getInstance() {
	if (!instance) {
		instance = new SingletonDirecteurIUT();
	}
	return instance;
}

void SingletonDirecteurIUT::killInstance() {
	if (instance) {
		delete instance;
		instance = nullptr;
	}
}