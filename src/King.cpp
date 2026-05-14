#include <iostream>
#include <format>
#include <cmath>
#include "King.h"
#include "ChessBoard.h"

King::King(Color color){
  pieceColor = color;
  type = KING;
  icon = (color == WHITE) ? "♚ " : "♔ ";
}

bool King::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color){
  int colDiff = std::abs(toCol - fromCol);
  int rowDiff = std::abs(toRow - fromRow);

  if (colDiff > 1 || rowDiff > 1 || (colDiff == 0 && rowDiff == 0)) {
    std::cout << std::format("Illegal move: {}{} to {}{} is not a valid King move.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  Piece* dest = board.get(toCol, toRow);
  if (dest != nullptr && dest->getPieceColor() == color) {
    std::cout << std::format("Illegal move: {}{} to {}{} is occupied by a friendly piece.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  board.set(fromCol, fromRow, toCol, toRow, board.get(fromCol, fromRow));
  return true;
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
