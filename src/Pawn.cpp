#include <iostream>
#include <format>
#include <climits>
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♟ " : "♙ ";
}

bool Pawn::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color){
  Piece* piece = board.get(fromCol, fromRow);

  if (piece->getPieceType() != PAWN){
    std::cout << std::format("Illegal move: selected piece at {}{} is not a Pawn.\n", fromCol, fromRow);
    return false;
  }

  int direction   = (pieceColor == WHITE) ? 1 : -1;
  int startingRow = (pieceColor == WHITE) ? 2 : 7;
  int rowStep     = (toRow - fromRow) * direction;  // positive = forward
  int colDiff     = std::abs(fromCol - toCol);

  // Single step forward
  if (rowStep == 1 && colDiff == 0 && board.get(toCol, toRow) == nullptr){
    board.set(fromCol, fromRow, toCol, toRow, piece);
    return true;
  }

  // Double step forward from starting row
  if (rowStep == 2 && colDiff == 0 && fromRow == startingRow){
    int midRow = fromRow + direction;
    if (board.get(fromCol, midRow) == nullptr && board.get(toCol, toRow) == nullptr){
      int ghostRow = midRow;
      board.setEnPassant(toCol, ghostRow);
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return true;
    }
  }

  // Diagonal capture of enemy piece
  if (rowStep == 1 && colDiff == 1){
    Piece* dest = board.get(toCol, toRow);
    if (dest != nullptr && dest->getPieceColor() != pieceColor){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return true;
    }

    // En passant capture
    if (toCol == board.getEnPassantCol() && toRow == board.getEnPassantRow()){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      board.clear(toCol, fromRow);  // remove the double-pushed pawn beside us
      return true;
    }
  }

  std::cout << std::format("Illegal move: {}{} to {}{} is not a valid Pawn move.\n",
    fromCol, fromRow, toCol, toRow);
  return false;
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
