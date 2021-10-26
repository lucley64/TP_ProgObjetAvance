#ifndef SPORTIF_H
#define SPORTIF_H

#include <iostream>

class Sportif {
/// ATTRIBUTS
protected:
	std::string m_nom;
	std::string m_prenom;
	int m_anneeNaissance;

/// METHODES
public:
	/** CONSTRUCTEUR **/
	Sportif(std::string, std::string, int);

	/** DESTRUCTEUR **/
	virtual ~Sportif();

	/** ENCAPSULATION **/
	std::string getNom();
	void setNom(std::string);

	std::string getPrenom();
	void setPrenom(std::string);

	int getAnneeNaissance();
	void setAnneeNaissance(int);

	/** METHODES USUELLES **/
	std::string toString();
	virtual int getAge();

};

#endif // !SPORTIF_H

