#ifndef PIECE_H
#define PIECE_H

#include <iostream>

class Piece {
public:
	std::string m_reference;
	std::string m_libelle;
	int m_prix;
	int m_poid;

	Piece(std::string reference, std::string libelle, int prix, int poid);

	std::string toString();
};

#endif // PIECE_H
