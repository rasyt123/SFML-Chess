//
// Created by rasyt on 12/22/2021.
//
#include "Pawn.h"


void Chess::Pawn::EnPassant(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, Pieces prevpiece, int prevy, int prevx) {
    if (turn == "black") {
        if (startposy == 3 and InBounds(endposy, endposx, underboard) and endposy == startposy-1 and endposx == startposx - 1) {
            if (thepieces[startposy][startposx - 1].getcolor() == "white" and underboard[startposy][startposx - 1] == 'P' and prevy == endposy - 1 and prevx == endposx and
                    prevpiece.getcolor() == "white" and prevpiece.gettype() == 'P') {
                    createblank(startposy, startposx - 1, underboard, thepieces);
                    char temp = underboard[startposy][startposx];
                    Pieces tempcopy = thepieces[startposy][startposx];
                    createblank(startposy, startposx, underboard, thepieces);
                    underboard[endposy][endposx] = temp;
                    thepieces[endposy][endposx] = tempcopy;
            } else if (startposy == 3 and InBounds(endposy, endposx, underboard) and endposy == startposy-1 and endposx == startposx+1) {
                if (thepieces[startposy][startposx + 1].getcolor() == "white" and underboard[startposy][startposx + 1] == 'P' and prevy == endposy - 1 and prevx == endposx and
                    prevpiece.getcolor() == "white" and prevpiece.gettype() == 'P') {
                    createblank(startposy, startposx + 1, underboard, thepieces);
                    char temp = underboard[startposy][startposx];
                    Pieces tempcopy = thepieces[startposy][startposx];
                    createblank(startposy, startposx, underboard, thepieces);
                    underboard[endposy][endposx] = temp;
                    thepieces[endposy][endposx] = tempcopy;
                }
            }
        }
    } else {
        if (startposy == 5 and InBounds(endposy, endposx, underboard) and endposy == startposy + 1 and endposx == startposx - 1) {
            if (thepieces[startposy][startposx - 1].getcolor() == "black" and underboard[startposy][startposx - 1] == 'P' and prevy == endposy + 1 and prevx == endposx and
                prevpiece.getcolor() == "black" and prevpiece.gettype() == 'P') {
                createblank(startposy, startposx - 1, underboard, thepieces);
                char temp = underboard[startposy][startposx];
                Pieces tempcopy = thepieces[startposy][startposx];
                createblank(startposy, startposx, underboard, thepieces);
                underboard[endposy][endposx] = temp;
                thepieces[endposy][endposx] = tempcopy;
            }
        } else if (startposy == 5 and InBounds(endposy, endposx, underboard) and endposy == startposy + 1 and endposx == startposx + 1) {
            if (thepieces[startposy][startposx + 1].getcolor() == "black" and underboard[startposy][startposx + 1] == 'P' and
            prevy == endposy + 1 and prevx == endposx and prevpiece.getcolor() == "black" and prevpiece.gettype() == 'P') {
                createblank(startposy, startposx + 1, underboard, thepieces);
                char temp = underboard[startposy][startposx];
                Pieces tempcopy = thepieces[startposy][startposx];
                createblank(startposy, startposx, underboard, thepieces);
                underboard[endposy][endposx] = temp;
                thepieces[endposy][endposx] = tempcopy;
            }
        }
    }
}

void Chess::Pawn::ListPromotionOptions(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn, std::vector<std::vector<std::pair<float, float>>>& boardcoords) {
    if (turn == "white" and IsValidMove(endposy, endposx) and endposy == 7) {
        std::string whitequeen = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_Q60.png";
        std::string whitebishop = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_b60.png";
        std::string whiterook = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_R60.png";
        std::string whiteknight = "C:\\Users\\rasyt\\Pictures\\Saved Pictures\\w_K60.png";
        std::pair<float, float> cellcoords = boardcoords[endposy][endposx];
        sf::RectangleShape promotionwindow(sf::Vector2f(480.0f, 120.0f));
        promotionwindow.setPosition(cellcoords.first, cellcoords.second);
        sf::Texture wqtexture;
        sf::Texture wbtexture;
        sf::Texture wrtexture;
        




        //print queen, rook, knight, bishop
    } else if (turn == "black" and IsValidMove(endposy, endposx) and endposy == 0) {




    }

}

void Chess::Pawn::createblank(int posy, int posx, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces) {
    underboard[posy][posx] = ' ';
    thepieces[posy][posx].settype(' ');
    thepieces[posy][posx].setblank(true);
    thepieces[posy][posx].setcolor("");
}


void Chess::Pawn::Capture(std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {
    char oldpiece = underboard[startposy][startposx];
    underboard[startposy][startposx] = ' ';
    underboard[endposy][endposx] = oldpiece;
    thepieces[endposy][endposx] = thepieces[startposy][startposx];
    thepieces[startposy][startposx].settype(' ');
    thepieces[startposy][startposx].setblank(true);
    thepieces[startposy][startposx].setcolor("");
}



bool Chess::Pawn::GenerateMoves(sf::RenderWindow* window, std::vector<std::vector<char>>& underboard, std::vector<std::vector<Pieces>>& thepieces, std::string turn) {
    if (turn == "white") {
        GenerateWhite(underboard);
        if (IsValidMove(endposy, endposx)) {
            return true;
        } else {
            return false;
        }
    } else {
        GenerateBlack(underboard);
        if (IsValidMove(endposy, endposx)) {
            return true;
        } else {
            return false;
        }
    }
}

bool Chess::Pawn::IsValidMove(int rows, int cols) {
    for (std::pair<int, int> coordpair : possiblemoves) {
        if (rows == coordpair.first and cols == coordpair.second) {
            return true;
        }

    }
    return false;
}


bool Chess::Pawn::InBounds(int row, int col, std::vector<std::vector<char>>& underboard) {
    return row >= 0 and row <= underboard.size() - 1 and col >= 0 and col <= underboard[0].size() - 1;
}

void Chess::Pawn::GenerateWhite(std::vector<std::vector<char>>& underboard) {
    if (BottomLeft(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx - 1));
    }
    if (BottomRight(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx + 1));
    }
    if (infrontdown(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy + 1, startposx));
    }
    if (infront2down(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy + 2, startposx));
    }
}

void Chess::Pawn::GenerateBlack(std::vector<std::vector<char>> &underboard) {
    if (TopLeft(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy-1, startposx-1));
    }
    if (TopRight(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy-1, startposx+1));
    }
    if (infronttop(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy-1, startposx));
    }
    if (infront2top(underboard)) {
        possiblemoves.emplace_back(std::make_pair(startposy-2, startposx));
    }
}

bool Chess::Pawn::BottomLeft(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx-1, underboard) and underboard[startposy + 1][startposx - 1] != ' ';
}

bool Chess::Pawn::BottomRight(std::vector<std::vector<char>>& underboard) {
    return InBounds(startposy+1, startposx+1, underboard) and underboard[startposy + 1][startposx + 1] != ' ';
}

bool Chess::Pawn::infrontdown(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy+1, startposx, underboard) and underboard[startposy + 1][startposx] == ' ';
}

bool Chess::Pawn::infront2down(std::vector<std::vector<char>> &underboard) {
    return startposy == 1 and InBounds(startposy+2, startposx, underboard) and underboard[startposy + 2][startposx] == ' ';
}

bool Chess::Pawn::TopLeft(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx-1, underboard) and underboard[startposy - 1][startposx - 1] != ' ';
}

bool Chess::Pawn::TopRight(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx + 1, underboard) and underboard[startposy - 1][startposx + 1];
}

bool Chess::Pawn::infronttop(std::vector<std::vector<char>> &underboard) {
    return InBounds(startposy-1, startposx, underboard) and underboard[startposy - 1][startposx] == ' ';
}

bool Chess::Pawn::infront2top(std::vector<std::vector<char>> &underboard) {
    return startposy == 6 and InBounds(startposy-2, startposx, underboard) and underboard[startposy - 2][startposx] == ' ';
}


