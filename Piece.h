#ifndef PIECE_H
#define PIECE_H

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
    virtual void move() = 0;
    virtual PieceType getPieceType() const = 0;
    virtual Color getPieceColor() const = 0;
};

#endif
