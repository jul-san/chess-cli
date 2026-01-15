#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.h"
#include <string>

class Queen : public Piece{
  public:
    Queen(Color color);
    virtual void move(ChessBoard& board, int row, int col, Color color) override;
    virtual PieceType getPieceType() const override;
    virtual Color getPieceColor() const override;
    virtual std::string getPieceIcon() const override;

  private:
    Color pieceColor;
    PieceType type;
    std::string icon;
};

#endif
