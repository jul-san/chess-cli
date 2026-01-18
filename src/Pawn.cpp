#include <iostream>
#include "Pawn.h"
#include "ChessBoard.h"

Pawn::Pawn(Color color){
  pieceColor = color;
  type = PAWN;
  icon = (color == WHITE) ? "♟ " : "♙ ";
}

void Pawn::move(ChessBoard& board, int fromRow, int fromCol, int toRow, int toCol, Color color){
  Piece* piece = board.get(fromRow, fromCol);
  if (piece->getPieceType() == PAWN){
    board.set(fromRow, fromCol, toRow, toCol, piece);
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
