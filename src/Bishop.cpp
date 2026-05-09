#include <iostream>
#include "Bishop.h"
#include "ChessBoard.h"

Bishop::Bishop(Color color){
  pieceColor = color;
  type = BISHOP;
  icon = (color == WHITE) ? "♝ " : "♗ ";
}

void Bishop::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) {
  std::cout << "In Bishop CPP" << std::endl;
}

PieceType Bishop::getPieceType() const{
  return type;
}

Color Bishop::getPieceColor() const{
  return pieceColor;
}

std::string Bishop::getPieceIcon() const{
  return icon;
}
