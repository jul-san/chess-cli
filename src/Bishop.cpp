#include <iostream>
#include <format>
#include <cmath>
#include "Bishop.h"
#include "ChessBoard.h"

Bishop::Bishop(Color color){
  pieceColor = color;
  type = BISHOP;
  icon = (color == WHITE) ? "♝ " : "♗ ";
}

bool Bishop::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) {
  int colDiff = std::abs(toCol - fromCol);
  int rowDiff = std::abs(toRow - fromRow);

  if (colDiff != rowDiff || colDiff == 0) {
    std::cout << std::format("Illegal move: {}{} to {}{} is not a valid Bishop move.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  Piece* dest = board.get(toCol, toRow);
  if (dest != nullptr && dest->getPieceColor() == color) {
    std::cout << std::format("Illegal move: {}{} to {}{} is occupied by a friendly piece.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  int colStep = (toCol > fromCol) ? 1 : -1;
  int rowStep = (toRow > fromRow) ? 1 : -1;

  char c = fromCol + colStep;
  int r = fromRow + rowStep;
  while (c != toCol) {
    if (board.get(c, r) != nullptr) {
      std::cout << std::format("Illegal move: path from {}{} to {}{} is blocked.\n",
        fromCol, fromRow, toCol, toRow);
      return false;
    }
    c += colStep;
    r += rowStep;
  }

  board.set(fromCol, fromRow, toCol, toRow, board.get(fromCol, fromRow));
  return true;
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
