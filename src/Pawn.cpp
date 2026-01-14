#include <iostream>
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♟ " : "♙ ";
}

void Pawn::move(ChessBoard& board, int x_position, int y_position, Color color){
  Piece* p = board.get(x_position, y_position);
  if (p->getPieceType() == PAWN){
    std::cout << "Hello from move in Pawn" << std::endl;
  }
}

PieceType Pawn::getPieceType() const{
  return type;
}

Color Pawn::getPieceColor() const{
  return pieceColor;
}

std::string Pawn::getPieceIcon() const{
  return icon;
}
