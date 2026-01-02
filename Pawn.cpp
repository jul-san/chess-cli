#include <iostream>
#include "Pawn.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = "♙ ";
}

void Pawn::move(){
  std::cout << "In Pawn CPP" << std::endl;
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
