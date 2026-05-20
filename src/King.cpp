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

  // Castling: king slides exactly 2 squares horizontally
  if (rowDiff == 0 && colDiff == 2) {
    bool kingside = (toCol > fromCol);
    int  row      = fromRow;
    Color enemy   = (pieceColor == WHITE) ? BLACK : WHITE;

    if (!board.hasCastlingRight(pieceColor, kingside)) {
      std::cout << "Illegal move: castling right has been forfeited.\n";
      return false;
    }

    char rookCol = kingside ? 'h' : 'a';
    Piece* rook = board.get(rookCol, row);
    if (rook == nullptr || rook->getPieceType() != ROOK || rook->getPieceColor() != pieceColor) {
      std::cout << "Illegal move: castling rook is not available.\n";
      return false;
    }

    // All squares between king and rook must be empty
    if (kingside) {
      if (board.get('f', row) != nullptr || board.get('g', row) != nullptr) {
        std::cout << "Illegal move: castling path is blocked.\n";
        return false;
      }
    } else {
      if (board.get('b', row) != nullptr || board.get('c', row) != nullptr || board.get('d', row) != nullptr) {
        std::cout << "Illegal move: castling path is blocked.\n";
        return false;
      }
    }

    // King must not be in check, and must not cross a square under attack
    if (board.isSquareAttacked(fromCol, row, enemy)) {
      std::cout << "Illegal move: cannot castle while in check.\n";
      return false;
    }
    char throughCol = kingside ? 'f' : 'd';
    if (board.isSquareAttacked(throughCol, row, enemy)) {
      std::cout << "Illegal move: king would pass through check.\n";
      return false;
    }
    // Landing square safety is enforced by the game loop's post-move isInCheck

    char kingDest = kingside ? 'g' : 'c';
    char rookDest = kingside ? 'f' : 'd';
    board.set(fromCol, row, kingDest, row, this);
    board.set(rookCol, row, rookDest, row, rook);
    board.revokeBothCastlingRights(pieceColor);
    return true;
  }

  // Regular one-square move
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

  board.set(fromCol, fromRow, toCol, toRow, this);
  board.revokeBothCastlingRights(pieceColor);
  return true;
}

PieceType King::getPieceType() const{ return type; }
Color King::getPieceColor() const{ return pieceColor; }
std::string King::getPieceIcon() const{ return icon; }
