#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <cstdint>
#include "Piece.h"

class ChessBoard{
  private:
    Piece* board[8][8];

  public:
    ChessBoard();
    void printBoard() const;
};

#endif
