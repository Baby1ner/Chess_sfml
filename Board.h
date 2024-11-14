#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Coordinates.h"
#include "Piece.h"
#include "Pieces/Pawn.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "Pieces/bishop.h"



#include <iostream>
using namespace sf;
using namespace std;
class Board
{
	
	int int_coor;
public:

	std::unordered_map<int, Piece*> pieces;

	Board() {}

	unordered_map<int, Piece*> get_pieces() {
		return pieces;
	}
	void setPiece(Coordinates coordinates, Piece* piece) {
		piece->set_coordinates(coordinates);
		int int_coor = coordinates.GetInt();
		pieces.insert(std::make_pair(int_coor, piece));
	}

	void setPiece(int int_coor, Piece* piece) {
		piece->set_coordinates(int_coor);
		pieces.insert(std::make_pair(int_coor, piece));
	}

	void delPiece(int int_coor) {
		for (auto&& item : pieces)
		{
			if (item.first == int_coor)
				pieces.erase(item.first);
		}

	}

	void set_Coordinates(int int_coor, int new_coor) {
		for (auto&& item : pieces)
		{
			if (item.first == int_coor)
				item.second->set_coordinates(new_coor);
		}
	}



	void set_default_position() {
		King* king_bl = new King(false, 4);
		setPiece(4, king_bl);
		Knight* knight = new Knight(false, 1);
		setPiece(1, knight);
		Knight* knight1 = new Knight(false, 6);
		setPiece(6, knight1);
		Queen* queen = new Queen(false,3);
		setPiece(3, queen);
		Rook* rook = new Rook(false, 0);
		setPiece(0, rook);
		Rook* rook1 = new Rook(false, 7);
		setPiece(7, rook1);
		Bishop* bishop = new Bishop(false, 2);
		setPiece(2, bishop);
		Bishop* bishop1 = new Bishop(false, 5);
		setPiece(5, bishop1);



		for (int i = 8; i < 16;i++) {
			Pawn* pawn =new Pawn(false, i);
			setPiece(i, pawn);
		}

		for (int i = 48; i < 56;i++) {
			Pawn* pawn =new Pawn(true, i);
			setPiece(i, pawn);
		}
		King* king_wh = new  King(true, 60);
		setPiece(60, king_wh);
		Knight* knight2 = new Knight(true, 62);
		setPiece(62, knight2);
		Knight* knight3 = new Knight(true, 57);
		setPiece(57, knight3);
		Queen* queen1 = new Queen(true, 59);
		setPiece(59, queen1);
		Rook* rook2 = new Rook(true, 56);
		setPiece(56, rook2);
		Rook* rook12 = new Rook(true, 63);
		setPiece(63, rook12);
		Bishop* bishop2 = new Bishop(true, 58);
		setPiece(58, bishop2);
		Bishop* bishop12 = new Bishop(true, 61);
		setPiece(61, bishop12);



	}





























	/*
	void board_print() {
		sf:RenderWindow window(sf::VideoMode(800, 800), L"Шахматы!");
		Texture texture_board;
		texture_board.loadFromFile("images/Board.png");
		RectangleShape board(Vector2f(800, 800));
		board.setTexture(&texture_board);


		RectangleShape piece_rectangle(Vector2f(100, 100));

		while (window.isOpen())
		{
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();

			}

			for (auto& item : pieces) {
				
				piece_rectangle.setTexture(&item.second.texture);
				piece_rectangle.setPosition(item.first % 8, item.first / 8);
				cout << "govno";
				
			}

			window.clear();
			window.draw(piece_rectangle);
			window.draw(board);
			window.display();
		}
	}
	*/


};

