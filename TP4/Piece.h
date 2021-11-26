#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece {
public:
	std::string m_reference;
	std::string m_libelle;
	int m_prix;
	int m_poid;

	Piece (std::string, std::string, int, int);

	std::string toString();
};

#endif // PIECE_H
