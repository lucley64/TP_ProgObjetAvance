#include "Piece.h"
#include <string>

Piece::Piece(std::string reference, std::string libelle, int prix, int poid) :
	m_reference(reference),
	m_libelle(libelle),
	m_prix(prix),
	m_poid(poid)
{}

std::string Piece::toString() {
	return m_reference + ", " + m_libelle + ", " + std::to_string(m_prix) + ", " + std::to_string(m_poid);
}