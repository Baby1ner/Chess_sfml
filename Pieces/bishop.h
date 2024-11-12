#pragma once
#include "../Piece.h"
#include <set>

using namespace std;

class Bishop : public Piece
{

public:
	Bishop(bool color1, Coordinates coordinates1) : Piece(color1, coordinates1) {
		if (color1) {
			texture.loadFromFile("images/BishopWhite.png");
		}
		else {
			texture.loadFromFile("images/BishopBlack.png");

		}
	}
	Bishop(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/BishopWhite.png");

		}
		else {
			texture.loadFromFile("images/BishopBlack.png");

		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces ) override {
	}

};