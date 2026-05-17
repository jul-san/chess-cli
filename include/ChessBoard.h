#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <cstdint>
#include "Piece.h"

class Piece;

class ChessBoard{
  private:
    Piece* board[8][8];
    char enPassantCol = '\0';
    int  enPassantRow = 0;

  public:
    ChessBoard();
    Piece* get(char col, int row);
    void set(char init_col, int init_row, char new_col, int new_row, Piece* p);
    void clear(char col, int row);
    void printBoard(Color turn) const;
    void setEnPassant(char col, int row);
    void clearEnPassant();
    char getEnPassantCol() const;
    int  getEnPassantRow() const;
};

#endif
