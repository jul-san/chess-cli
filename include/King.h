#ifndef KING_H
#define KING_H
#include "Piece.h"
#include <string>

class King : public Piece{
  public:
    King(Color color);
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
