#include <iostream>
#include <format>
#include <cmath>
#include "Rook.h"
#include "ChessBoard.h"

Rook::Rook(Color color){
  pieceColor = color;
  type = ROOK;
  icon = (color == WHITE) ? "♜ " : "♖ ";
}

bool Rook::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color) {
  bool sameCol = fromCol == toCol;
  bool sameRow = fromRow == toRow;

  if (!sameCol && !sameRow) {
    std::cout << std::format("Illegal move: {}{} to {}{} is not a valid Rook move.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  Piece* dest = board.get(toCol, toRow);
  if (dest != nullptr && dest->getPieceColor() == color) {
    std::cout << std::format("Illegal move: {}{} to {}{} is occupied by a friendly piece.\n",
      fromCol, fromRow, toCol, toRow);
    return false;
  }

  int colStep = sameCol ? 0 : (toCol > fromCol ? 1 : -1);
  int rowStep = sameRow ? 0 : (toRow > fromRow ? 1 : -1);

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

  // Revoke castling right for whichever corner this rook started from
  if      (fromCol == 'a' && fromRow == 1) board.revokeCastlingRight(WHITE, false);
  else if (fromCol == 'h' && fromRow == 1) board.revokeCastlingRight(WHITE, true);
  else if (fromCol == 'a' && fromRow == 8) board.revokeCastlingRight(BLACK, false);
  else if (fromCol == 'h' && fromRow == 8) board.revokeCastlingRight(BLACK, true);

  return true;
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
