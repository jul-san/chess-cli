#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.h"
#include <string>

class Knight : public Piece{
  public:
    Knight(Color color);
    virtual void move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color) override;
    virtual PieceType getPieceType() const override;
    virtual Color getPieceColor() const override;
    virtual std::string getPieceIcon() const override;

  private:
    Color pieceColor;
    PieceType type;
    std::string icon;
};

#endif
