#include <iostream>
#include "King.h"
#include "ChessBoard.h"

King::King(Color color){
  pieceColor = color;
  type = KING;
  icon = (color == WHITE) ? "♚ " : "♔ ";
}

void King::move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color){
  std::cout << "In King CPP" << std::endl;
}

PieceType King::getPieceType() const{
  return type;
}

Color King::getPieceColor() const{
  return pieceColor;
}

std::string King::getPieceIcon() const{
  return icon;
}
