//
// Created by rasyt on 12/20/2021.
//

#ifndef CHESS_GAME_H
#define CHESS_GAME_H
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "Pieces.h"
#include <SFML/Graphics.hpp>
#define BOARD_ROWS 8
#define BOARD_COLS 8
#define OUT_OF_BOUNDS -9000

namespace Chess {
    class Game {
    public:
        void SetupBoard(sf::RenderWindow* window);
        void CheckSelect(sf::RenderWindow* window, bool& isgreen,  std::pair<float, float>& piececoords, std::pair<int, int>& pieceyx, bool mademove, float& clickposy, float& clickposx);
        void CoverCellGreen(sf::RenderWindow *window, bool &isgreen, std::pair<float, float> &piececoords, std::pair<int, int> &pieceyx, float& clickposy, float& clickposx);
        void GameLoop();
        void addcoords();
        void set_cellwidth(int width);
        void set_cellheight(int height);
        void SetUnderBoard();
        bool isPiece(float y, float x, std::pair<float, float>& piececords, std::pair<int, int>& boardcords);
        bool isEven(int number);
        void printPiece(float spritex, float spritey, int ypos, int xpos, sf::RenderWindow* window, std::string color);


    private:

        std::vector<std::vector<std::pair<float, float>>> boardcoords;
        std::vector<std::vector<char>> underboard;
        std::vector<std::vector<Pieces>> thepieces;




        int cell_width;
        int cell_height;

        int old_greenposx;
        int old_greenposy;
        float oldposrow;
        float oldposcol;
    };

}


#endif //CHESS_GAME_H
