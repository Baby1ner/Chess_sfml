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

		int moment_x = coordinates.xcoor + 1;
		int moment_y = coordinates.ycoor;

		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x < 8) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x++;
		}

		moment_x = coordinates.xcoor;
		moment_y = coordinates.ycoor - 1;

		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_y -= 1;
		}




		moment_x = coordinates.xcoor - 1;
		moment_y = coordinates.ycoor;



		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x >= 0) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x -= 1;
		}




		moment_x = coordinates.xcoor;
		moment_y = coordinates.ycoor + 1;


		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_y ++;
		}






	}

};