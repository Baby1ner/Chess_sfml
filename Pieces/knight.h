#pragma once
#include "../Piece.h"
#include <set>
#include <unordered_map>

using namespace std;

class Knight : public Piece
{

public:
	Knight(bool color1, Coordinates coordinates1) : Piece(color1, coordinates1) {
		if (color1) {
			texture.loadFromFile("images/HorseWhite.png");
		}
		else {
			texture.loadFromFile("images/HorseBlack.png");

		}
	}
	Knight(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/HorseWhite.png");

		}
		else {
			texture.loadFromFile("images/HorseBlack.png");

		}
	}

	Knight(bool color1) : Piece(color1) {
		if (color1) {
			texture.loadFromFile("images/HorseWhite.png");

		}
		else {
			texture.loadFromFile("images/HorseBlack.png");

		}
	}



	void get_posible_moves(unordered_map<int, Piece*> pieces) override {

		
		if (coordinates.xcoor + 2 < 8 && coordinates.ycoor + 1 < 8) {
			if (!contains_teammate(coor_toint(coordinates.xcoor + 2, coordinates.ycoor + 1), pieces)) {
				coordinates_moves.insert((coordinates.xcoor + 2) + (coordinates.ycoor + 1) * 8);
			}
		}
		
		if (coordinates.xcoor + 2 < 8 && coordinates.ycoor - 1 >= 0) {
			if (!contains_teammate(coor_toint(coordinates.xcoor + 2, coordinates.ycoor - 1), pieces)) {
				coordinates_moves.insert((coordinates.xcoor + 2) + (coordinates.ycoor - 1) * 8);
			}
		}


		if (coordinates.xcoor - 2 >= 0 && coordinates.ycoor + 1 < 8) {
			if (!contains_teammate(coor_toint(coordinates.xcoor - 2, coordinates.ycoor + 1), pieces)) {
				coordinates_moves.insert((coordinates.xcoor - 2) + (coordinates.ycoor + 1) * 8);
			}
		}

		if (coordinates.xcoor - 2 >= 0 && coordinates.ycoor - 1 >= 0) {
			if (!contains_teammate(coor_toint(coordinates.xcoor - 2, coordinates.ycoor - 1), pieces)) {
				coordinates_moves.insert((coordinates.xcoor - 2) + (coordinates.ycoor - 1) * 8);
			}
		}



		
		if (coordinates.xcoor + 1 < 8 && coordinates.ycoor + 2 < 8) {
			if (!contains_teammate(coor_toint(coordinates.xcoor + 1, coordinates.ycoor + 2), pieces)) {
				coordinates_moves.insert((coordinates.xcoor + 1) + (coordinates.ycoor + 2) * 8);
			}
		}



		
		if (coordinates.xcoor + 1 < 8 && coordinates.ycoor - 2 >= 0) {
			if (!contains_teammate(coor_toint(coordinates.xcoor + 1, coordinates.ycoor - 2), pieces)) {
				coordinates_moves.insert((coordinates.xcoor + 1) + (coordinates.ycoor - 2) * 8);
			}
		}


		
		if (coordinates.xcoor - 1 >= 0 && coordinates.ycoor + 2 < 8) {
			if (!contains_teammate(coor_toint(coordinates.xcoor - 1, coordinates.ycoor + 2), pieces)) {
				coordinates_moves.insert((coordinates.xcoor - 1) + (coordinates.ycoor + 2) * 8);
			}
		}

		if (coordinates.xcoor - 1 >= 0 && coordinates.ycoor - 2 >= 0) {
			if (!contains_teammate(coor_toint(coordinates.xcoor - 1, coordinates.ycoor - 2), pieces)) {
				coordinates_moves.insert((coordinates.xcoor - 1) + (coordinates.ycoor - 2) * 8);
			}
		}
		








	}
	

};