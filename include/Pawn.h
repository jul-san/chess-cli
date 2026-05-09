#ifndef PAWN_H
#define PAWN_H
#include "Piece.h"
#include <string>

class Pawn : public Piece{
  public:
    Pawn(Color color);
    virtual void move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) override;
    virtual PieceType getPieceType() const override;
    virtual Color getPieceColor() const override;
    virtual std::string getPieceIcon() const override;

  private:
    Color pieceColor;
    PieceType type;
    std::string icon;
};

#endif
