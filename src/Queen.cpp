#include <iostream>
#include <format>
#include <cmath>
#include "Queen.h"
#include <string>
#include "ChessBoard.h"

Queen::Queen(Color color){
  pieceColor = color;
  type = QUEEN;
  icon = (color == WHITE) ? "♛ " : "♕ ";
}

bool Queen::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) {
  int colDiff = std::abs(toCol - fromCol);
  int rowDiff = std::abs(toRow - fromRow);

  bool isDiagonal = colDiff == rowDiff && colDiff != 0;
  bool isStraight = (fromCol == toCol) != (fromRow == toRow);

  if (!isDiagonal && !isStraight) {
    std::cout << std::format("Illegal move: {}{} to {}{} is not a valid Queen move.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  Piece* dest = board.get(toCol, toRow);
  if (dest != nullptr && dest->getPieceColor() == color) {
    std::cout << std::format("Illegal move: {}{} to {}{} is occupied by a friendly piece.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  int colStep = (toCol == fromCol) ? 0 : (toCol > fromCol ? 1 : -1);
  int rowStep = (toRow == fromRow) ? 0 : (toRow > fromRow ? 1 : -1);

  char c = fromCol + colStep;
  int r = fromRow + rowStep;
  while (c != toCol || r != toRow) {
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

PieceType Queen::getPieceType() const {
  return type;
}

Color Queen::getPieceColor() const {
  return pieceColor;
}

std::string Queen::getPieceIcon() const {
  return icon;
}
