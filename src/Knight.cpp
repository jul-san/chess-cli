#include <iostream>
#include <cstdlib>
#include "Knight.h"
#include "ChessBoard.h"

Knight::Knight(Color color){
  pieceColor = color;
  type = KNIGHT;
  icon = (color == WHITE) ? "♞ " : "♘ ";
}

void Knight::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color){
  int colDiff = std::abs(fromCol - toCol);
  int rowDiff = std::abs(fromRow - toRow);

  bool validShape = (colDiff == 1 && rowDiff == 2) || (colDiff == 2 && rowDiff == 1);
  if (!validShape){
    std::cout << "You made an illegal Knight move!" << std::endl;
    return;
  }

  Piece* dest = board.get(toCol, toRow);
  if (dest != nullptr && dest->getPieceColor() == color){
    std::cout << "You made an illegal Knight move!" << std::endl;
    return;
  }

  board.set(fromCol, fromRow, toCol, toRow, this);
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
