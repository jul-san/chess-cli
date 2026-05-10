#include <iostream>
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
  int startingRow = 2;

  int rowDiff = std::abs(fromRow - toRow);
  int colDiff = std::abs(fromCol - toCol);

  if (piece->getPieceType() == PAWN){

    if (rowDiff == 1 && colDiff == 0 && board.get(toCol, toRow) == nullptr){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return true;
    }

    if (fromRow == startingRow && rowDiff == 2){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return true;
    }

    if (rowDiff == 1 && colDiff == 1 && board.get(toCol, toRow) != nullptr){
      board.set(fromCol, fromRow, toCol, toRow, piece);
      return true;
    }

    std::cout << "Illegal Pawn move!" << std::endl;
    return false;

  }
  else{
    std::cout << "You have selected an incorrect piece." << std::endl;
    return false;
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
