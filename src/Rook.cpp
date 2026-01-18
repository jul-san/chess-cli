#include <iostream>
#include "Rook.h"
#include "ChessBoard.h"

Rook::Rook(Color color){
  pieceColor = color;
  type = ROOK;
  icon = (color == WHITE) ? "♜ " : "♖ ";
}

void Rook::move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color) {
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
