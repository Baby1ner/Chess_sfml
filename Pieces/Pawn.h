#pragma once
#include "../Piece.h"
#include <set>

using namespace std;

class Pawn : public Piece
{

public:
	Pawn(bool color1, Coordinates coordinates1) : Piece(color1,coordinates1) {
		if (color1) {
			texture.loadFromFile("images/PawnWhite.png");
		}
		else {
			texture.loadFromFile("images/PawnBlack.png");

		}
	}
	Pawn(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/PawnWhite.png");

		}
		else {
			texture.loadFromFile("images/PawnBlack.png");

		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces) override {
	}

	
};