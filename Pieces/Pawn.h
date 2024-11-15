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
			pawn = true;
		}
		else {
			texture.loadFromFile("images/PawnBlack.png");
			pawn = true;
		}
	}
	Pawn(bool color1, int coor) : Piece(color1, coor) {
		if (color1) {
			texture.loadFromFile("images/PawnWhite.png");
			pawn = true;
		}
		else {
			texture.loadFromFile("images/PawnBlack.png");
			pawn = true;
		}
	}

	void get_posible_moves(unordered_map<int, Piece*> pieces) override {

		int moment_x = coordinates.xcoor;
		int moment_y = coordinates.ycoor - 1;

		if (!contains(moment_x + moment_y * 8, pieces) && moment_y >=0 && color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));

		}
		if (!contains(moment_x + moment_y * 8, pieces) && !contains(moment_x + (moment_y - 1) * 8, pieces) && moment_y >= 0 && first_move && color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y-1));

			
		}



		moment_x = coordinates.xcoor;
		moment_y = coordinates.ycoor + 1;

		if (!contains(moment_x + moment_y * 8, pieces) && moment_y < 8 && !color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));

		}
		if (!contains(moment_x + moment_y * 8, pieces) && !contains(moment_x + (moment_y + 1) * 8, pieces) && moment_y < 8 && first_move && !color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y + 1));

		}

		moment_x = coordinates.xcoor + 1;
		moment_y = coordinates.ycoor + 1;
		if (contains_enemy(moment_x + (moment_y * 8), pieces) && !color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
		}

		moment_x = coordinates.xcoor - 1;
		moment_y = coordinates.ycoor + 1;
		if (contains_enemy(moment_x + (moment_y * 8), pieces) && !color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
		}


		moment_x = coordinates.xcoor + 1;
		moment_y = coordinates.ycoor - 1;
		if (contains_enemy(moment_x + (moment_y * 8), pieces) && color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
		}

		moment_x = coordinates.xcoor - 1;
		moment_y = coordinates.ycoor - 1;
		if (contains_enemy(moment_x + (moment_y * 8), pieces) && color) {
			coordinates_moves.insert(coor_int(moment_x, moment_y));
		}




		
	}

	
};