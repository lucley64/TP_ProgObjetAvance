#ifndef SINGLETON_DIRECTEUR_IUT
#define SINGLETON_DIRECTEUR_IUT

#include <iostream>

using namespace std;

class SingletonDirecteurIUT {
private:
	static SingletonDirecteurIUT* instance;
	string nom;
	string prenom;

	SingletonDirecteurIUT();
	~SingletonDirecteurIUT();


public:
	void setNom(string nom);
	void setPrenom(string prenom);

	string getNom();
	string getPrenom();

	string toString(string message = "");

	static SingletonDirecteurIUT*	getInstance();
	static void						killInstance();

};

#endif // !SINGLETON_DIRECTEUR_IUT
