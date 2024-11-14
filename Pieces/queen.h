#pragma once
#include "../Piece.h"
#include <set>

using namespace std;

class Queen : public Piece
{

public:
	Queen(bool color1, Coordinates coordinates1) : Piece(color1, coordinates1) {
		if (color1) {
			texture.loadFromFile("images/QueenWhite.png");
		}
		else {
			texture.loadFromFile("images/QueenBlack.png");

		}
	}
	Queen(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/QueenWhite.png");

		}
		else {
			texture.loadFromFile("images/QueenBlack.png");

		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces) override {

		int moment_x = coordinates.xcoor + 1;
		int moment_y = coordinates.ycoor + 1;

		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x < 8 && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x++;
			moment_y++;
		}


		moment_x = coordinates.xcoor + 1;
		moment_y = coordinates.ycoor - 1;

		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x < 8 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x++;
			moment_y -= 1;
		}




		moment_x = coordinates.xcoor - 1;
		moment_y = coordinates.ycoor + 1;



		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x >= 0 && moment_y < 8) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x -= 1;
			moment_y++;
		}





		moment_x = coordinates.xcoor - 1;
		moment_y = coordinates.ycoor - 1;


		while (!contains_teammate(moment_x + moment_y * 8, pieces) && moment_x >= 0 && moment_y >= 0) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
			if (contains_enemy(moment_x + moment_y * 8, pieces)) {
				break;
			}
			moment_x -= 1;
			moment_y -= 1;
		}
















		moment_x = coordinates.xcoor + 1;
		moment_y = coordinates.ycoor;

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
			moment_y++;
		}















	}


};