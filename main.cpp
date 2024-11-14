#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <set>
#include <unordered_map>
#include "Pieces/Pawn.h"
#include "Pieces/king.h"
#include "Pieces/knight.h"
#include "Pieces/queen.h"
#include "Pieces/rook.h"
#include "Pieces/bishop.h"




using namespace sf;

    int mouse_x;
    int mouse_y;
    bool right_pressed = false;
    bool left_pressed = false;
    set<int> coordinates_moves;
    Piece* piece_pressed = new Piece;
    int coor_chosen;
    int a = 100;
    bool turn = true;
    int del_coor;
    bool do_once = true;
    std::unordered_map<int, Piece*> pieces;





int main()
{
    bool First_play = true;
    RenderWindow window(sf::VideoMode(800, 800), L"Шахматы!");

    Vector2i mousePos;

    Texture texture_board;
    texture_board.loadFromFile("images/Board.png");
    RectangleShape rectangle_board(Vector2f(800, 800));
    rectangle_board.setTexture(&texture_board);


    int k = 10;
    Pawn pawn = Pawn(true, k);
    Pawn pawn1 = Pawn(false, k+1);

    RectangleShape piece_rectangle(Vector2f(100, 100));
    RectangleShape under_piece_rectangle(Vector2f(100, 100));
    Board board = Board();
    std::cout << "govno";

    while (window.isOpen())
    {
        sf::Event event;
        mousePos = sf::Mouse::getPosition(window);
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (First_play) {
            board.set_default_position();
            First_play = false;
            pieces = board.get_pieces();

        }
        
        if (Mouse::isButtonPressed(sf::Mouse::Right)) {
            mouse_x = mousePos.x;
            mouse_y = mousePos.y;
            right_pressed = true;
            left_pressed = false;
            if (!do_once) {
                do_once = true;

                if (turn) {
                    turn = false;
                }
                else {
                    turn = true;
                }
            }
        }

        if (Mouse::isButtonPressed(sf::Mouse::Left)) {
            mouse_x = mousePos.x;
            mouse_y = mousePos.y;
            
            right_pressed = false;
            left_pressed = true;
        }




        window.clear();
        window.draw(rectangle_board);
        for (auto& item : pieces) {
            int coor_piece = item.second->get_coordinates().GetInt();
            Texture kostil = (item.second)->get_texture();
            piece_rectangle.setTexture(&kostil);
            piece_rectangle.setPosition(((coor_piece % 8)) * 100, (coor_piece / 8) * 100);
            
            if (coor_piece % 8 == (mouse_x / 100) && coor_piece / 8 == (mouse_y / 100) && right_pressed && turn == item.second->get_color()) {
                coor_chosen = coor_piece;
                coordinates_moves.clear();
                Piece* piece_new{ item.second };
                piece_pressed = piece_new;
                piece_pressed->clear_coordinate_moves();
                
                item.second->get_posible_moves(pieces);
                for (int i = 0; i < 63;i++) {
                    for (int j : item.second->get_coordinates_moves()) {
                        if (i == j) {

                            coordinates_moves.insert(i);

                            under_piece_rectangle.setPosition(((j % 8)) * 100, (j / 8) * 100);
                            under_piece_rectangle.setFillColor(sf::Color::Red);
                            window.draw(under_piece_rectangle);
                        }
                    }
                }
                under_piece_rectangle.setFillColor(sf::Color::Green);
            }
            else {
                under_piece_rectangle.setFillColor(sf::Color::Transparent);
            }


            if (left_pressed) {
                for (int i : coordinates_moves) {
                    if (i % 8 == (mouse_x / 100) && i / 8 == (mouse_y / 100)) {

                        if (do_once) {
                            for (auto& item : pieces) {
                                if (item.second->get_coordinates().GetInt() == i) {
                                    item.second->set_coordinates(-1);
                                    
                                }
                            }
                        }
                        

                        for (auto& item : pieces) {
                            if (item.second->get_coordinates().GetInt() == coor_chosen) {
                                item.second->set_coordinates(i);
                                item.second->set_first_move(false);
                            }
                               
                        }
                        do_once = false;

                    }
                }


            }

            //if (item.first == 3 || item.first == )





            //Govno* govn{ item.second };
            
            under_piece_rectangle.setPosition(((coor_piece % 8)) * 100, (coor_piece / 8) * 100);

            window.draw(under_piece_rectangle);
            window.draw(piece_rectangle);
        }

        // в гет мув проверить чтобы не выходило за поле
        




        window.display();
    }




    return 0;
}