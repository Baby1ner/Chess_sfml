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

		int moment_x = coordinates.xcoor;
		int moment_y = coordinates.ycoor;


		if (!contains_teammate(moment_x - 1 + (moment_y - 1) * 8, pieces) && moment_x >= 0 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x-1, moment_y-1));
		}
		if (!contains_teammate(moment_x - 1 + moment_y * 8, pieces) && moment_x >= 0 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x - 1, moment_y));
		}
		if (!contains_teammate(moment_x - 1 + (moment_y + 1) * 8, pieces) && moment_x >= 0 && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x - 1, moment_y + 1));
		}


		if (!contains_teammate(moment_x + 1 + moment_y - 1 * 8, pieces) && moment_x < 8 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x + 1, moment_y - 1));
		}
		if (!contains_teammate(moment_x + 1 + moment_y * 8, pieces) && moment_x < 8) {
			coordinates_moves.insert(coor_int(moment_x + 1, moment_y));
		}
		if (!contains_teammate(moment_x + 1 + moment_y + 1 * 8, pieces) && moment_x < 8 && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x + 1, moment_y + 1));
		}



		if (!contains_teammate(moment_x + moment_y - 1 * 8, pieces) && moment_x < 8 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x, moment_y - 1));
		}
		if (!contains_teammate(moment_x + moment_y + 1 * 8, pieces) && moment_x < 8 && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x, moment_y + 1));
		}



















	}



};