#include <iostream>
#include "Queen.h"
#include <string>
#include "ChessBoard.h"

Queen::Queen(Color color){
  pieceColor = color;
  type = QUEEN;
  icon = (color == WHITE) ? "♛ " : "♕ ";
}

void Queen::move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color) {
  std::cout << "In Quenn CPP" << std::endl;
}

PieceType Queen::getPieceType() const {
  return type;
}

Color Queen::getPieceColor() const {
  return pieceColor;
}

std::string Queen::getPieceIcon() const {
  return icon;
}
