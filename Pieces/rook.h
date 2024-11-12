#pragma once
#include "../Piece.h"
#include <set>

using namespace std;

class Rook : public Piece
{

public:
	Rook(bool color1, Coordinates coordinates1) : Piece(color1, coordinates1) {
		if (color1) {
			texture.loadFromFile("images/RookWhite.png");
		}
		else {
			texture.loadFromFile("images/RookBlack.png");

		}
	}
	Rook(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/RookWhite.png");

		}
		else {
			texture.loadFromFile("images/RookBlack.png");

		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces) override {
	}

};