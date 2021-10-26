#ifndef OUTILS_H
#define OUTILS_H

#include <time.h>
class Outils {
/// ATTRIBUTS -non-

/// METHODES
public:
	/** CONSTRUCTEUR -non- **/
	/** DESTRUCTEUR -non **/
	/** ENCAPSULATION -non- **/
	/** METHODES USUELLES -non- **/

	/** METHODE SPECIFIQUE : anneeActuelle**/
	static short int anneeActuelle() {
		time_t timer;						// stocke l'heure actuelle
		struct tm* newTime = new tm();		// pointe sur une structure

		// demande l'heure que l'on recupere a l'adresse de timer
		time(&timer);
		localtime_s(newTime, &timer);		// decompose timer dans 1 structure
		return (newTime->tm_year + 1900);	// retourne l'heure actuelle
	}

};

#endif // !OUTILS_H
