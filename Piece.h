#pragma once
#include <SFML/Graphics.hpp>
#include "Coordinates.h"
#include <set>

using namespace sf;
using namespace std;

class Piece
{
	
public:
	bool pawn = false;
	bool king = false;
	bool first_move = true;
	bool color = false;
	Coordinates coordinates;
	Texture texture;
	set <int> coordinates_moves;

	bool get_king() { return king; }
	bool get_pawn() { return pawn; }
	void set_first_move(bool r) { first_move = r; }
	bool get_color() {
		return color;
	}

	Texture get_texture() {
		return texture;
	}

	set <int> get_coordinates_moves() {
		return coordinates_moves;
	}
	void clear_coordinate_moves() {
		coordinates_moves.clear();
	}

	Piece () {}


	Piece(bool color1) {
		color = color1;

	}

	Piece(const Piece& pice) {
		color = pice.color;
		coordinates = pice.coordinates;
		texture = pice.texture;
	}



	Piece(bool color1, Coordinates coordinates1) {
		color = color1;
		coordinates = coordinates1;

	}

	Piece(bool color1, int coor) {
		color = color1;
		coordinates = Coordinates(coor);
	}
	Coordinates get_coordinates() { return coordinates; }
	void set_coordinates(Coordinates coordinates1) { coordinates = coordinates1; }
	void set_coordinates(int coor) {
		coordinates = Coordinates(coor%8,coor/8); 
	}

	
	virtual void get_posible_moves(unordered_map<int, Piece*> pieces) {

	}

	bool contains_teammate(int n, unordered_map<int, Piece*> pieces) {
		for (auto& item : pieces) {
			if (n == item.second->get_coordinates().GetInt() && item.second->get_color() == color) return true;
		}
		return false;
	}
	
	bool contains(int n, unordered_map<int, Piece*> pieces) {
		for (auto& item : pieces) {
			if (n == item.second->get_coordinates().GetInt()) return true;
		}
		return false;
	}

	bool contains_enemy(int n, unordered_map<int, Piece*> pieces) {
		for (auto& item : pieces) {
			if (n == item.second->get_coordinates().GetInt() && item.second->get_color() == !color) return true;
		}
		return false;
	}

	int coor_int(int x, int y) {
		return x + y * 8;
	}







	int coor_toint(int x, int y) {
		return x + y * 8;
	}
};

