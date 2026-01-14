#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <cstdint>

class Piece;

class ChessBoard{
  private:
    Piece* board[8][8];

  public:
    ChessBoard();
    Piece* get(int x_position, int y_position);
    void printBoard() const;
};

#endif
