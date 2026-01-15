#ifndef PIECE_H
#define PIECE_H
#include <string>

class ChessBoard;

enum Color{
  WHITE,
  BLACK
};

enum PieceType{
  PAWN,
  KNIGHT,
  BISHOP,
  ROOK,
  QUEEN,
  KING,
};

class Piece{
  public:
    virtual ~Piece() = default;
    virtual void move(ChessBoard& board, int row, int col, Color color) = 0;
    virtual PieceType getPieceType() const = 0;
    virtual Color getPieceColor() const = 0;
    virtual std::string getPieceIcon() const = 0;
};

#endif
