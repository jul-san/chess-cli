#include <iostream>
#include <climits>
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♟ " : "♙ ";
}

void Pawn::move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color){
  Piece* piece = board.get(fromRow, fromCol);
  int startingRow = 6;

  int rowDiff = std::abs(fromRow - toRow);
  int colDiff = std::abs(fromCol - toCol);

  if (piece->getPieceType() == PAWN){

    // Moving one one space forward
    if (rowDiff == 1 && colDiff == 0 && board.get(toRow, toCol) == nullptr){
      board.set(fromRow, fromCol, toRow, toCol, piece);
      return;
    }

    // Moving two spaces forward if on the initial spot
    if (fromRow == startingRow && rowDiff == 2){
      board.set(fromRow, fromCol, toRow, toCol, piece);
      return;
    }

    // Moving diagonally if there is a piece that can be taken
    if (rowDiff == 1 && colDiff == 1 && board.get(toRow, toCol) != nullptr){
      board.set(fromRow, fromCol, toRow, toCol, piece);
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
