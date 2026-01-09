#include <iostream>
#include "Knight.h"

Knight::Knight(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♞ " : "♘ ";
}

void Knight::move(){
  std::cout << "In Knight CPP" << std::endl;
}

PieceType Knight::getPieceType() const{
  return type;
}

Color Knight::getPieceColor() const{
  return pieceColor;
}

std::string Knight::getPieceIcon() const{
  return icon;
}
