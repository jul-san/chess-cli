#include <iostream>
#include "Rook.h"

Rook::Rook(Color color){
  pieceColor = color;
  type = ROOK;
  icon = (color == WHITE) ? "♜ " : "♖ ";
}

void Rook::move() {
  std::cout << "In Rook CPP" << std::endl;
}

PieceType Rook::getPieceType() const{
  return type;
}

Color Rook::getPieceColor() const{
  return pieceColor;
}

std::string Rook::getPieceIcon() const{
  return icon;
}
