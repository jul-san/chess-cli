#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"

class Pawn : public Piece{
  public:
    Pawn(Color color);
    virtual void move() override;
    virtual PieceType getPieceType() const override;
    virtual Color getPieceColor() const override;
    virtual char32_t getPieceIcon() const override;

  private:
    Color pieceColor;
    PieceType type;
    char32_t icon;
};

#endif
