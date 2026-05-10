#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.h"
#include <string>

class Bishop : public Piece{
  public:
    Bishop(Color color);
    virtual bool move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) override;
    virtual PieceType getPieceType() const override;
    virtual Color getPieceColor() const override;
    virtual std::string getPieceIcon() const override;

  private:
    Color pieceColor;
    PieceType type;
    std::string icon;
};

#endif
