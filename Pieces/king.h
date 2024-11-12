#pragma once
#include "../Piece.h"
#include <set>

using namespace std;

class King : public Piece
{

public:
	King(bool color1, Coordinates coordinates1) : Piece(color1, coordinates1) {
		if (color1) {
			texture.loadFromFile("images/KingWhite.png");
		}
		else {
			texture.loadFromFile("images/KingBlack.png");

		}
	}
	King(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/KingWhite.png");

		}
		else {
			texture.loadFromFile("images/KingBlack.png");

		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces) override {
	}



};