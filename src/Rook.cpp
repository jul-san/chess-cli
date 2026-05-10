#include <iostream>
#include "Rook.h"
#include "ChessBoard.h"

Rook::Rook(Color color){
  pieceColor = color;
  type = ROOK;
  icon = (color == WHITE) ? "♜ " : "♖ ";
}

bool Rook::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) {
  std::cout << "In Rook CPP" << std::endl;
  return false;
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
