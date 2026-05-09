#include <iostream>
#include <climits>
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♟ " : "♙ ";
}

void Pawn::move(ChessBoard& board, char fromCol, int fromRow, char toCol, int toRow, Color color){
  Piece* piece = board.get(fromCol, fromRow);
  int startingRow = 2;

  int rowDiff = std::abs(fromRow - toRow);
  int colDiff = std::abs(fromCol - toCol);

  if (piece->getPieceType() == PAWN){

    if (rowDiff == 1 && colDiff == 0 && board.get(toCol, toRow) == nullptr){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return;
    }

    if (fromRow == startingRow && rowDiff == 2){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return;
    }

    if (rowDiff == 1 && colDiff == 1 && board.get(toCol, toRow) != nullptr){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return;
    }

    std::cout << "You made an illegal Pawn move!" << std::endl;

  }
  else{
    std::cout << "You have selected an incorrect piece.";
  }
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
