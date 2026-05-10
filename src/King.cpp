#include <iostream>
#include "King.h"
#include "ChessBoard.h"

King::King(Color color){
  pieceColor = color;
  type = KING;
  icon = (color == WHITE) ? "♚ " : "♔ ";
}

bool King::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color){
  std::cout << "In King CPP" << std::endl;
  return false;
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
