#include <iostream>
#include <cstdint>
#include "ChessBoard.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

ChessBoard::ChessBoard(){
  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      board[row][col] = nullptr;
    }
  }

  // Pawns
  for (int col = 0; col < 8; col++){ board[1][col] = new Pawn(BLACK); }
  for (int col = 0; col < 8; col++){ board[6][col] = new Pawn(WHITE); }

  // Rooks
  board[0][0] = new Rook(BLACK);
  board[0][7] = new Rook(BLACK);
  board[7][0] = new Rook(WHITE);
  board[7][7] = new Rook(WHITE);

  // Knight
  board[0][1] = new Knight(BLACK);
  board[0][6] = new Knight(BLACK);
  board[7][1] = new Knight(WHITE);
  board[7][6] = new Knight(WHITE);

  // Bishop
  board[0][2] = new Bishop(BLACK);
  board[0][5] = new Bishop(BLACK);
  board[7][2] = new Bishop(WHITE);
  board[7][5] = new Bishop(WHITE);

  // Queen
  board[0][3] = new Queen(BLACK);
  board[7][3] = new Queen(WHITE);

  // King
  board[0][4] = new King(BLACK);
  board[7][4] = new King(WHITE);

}

Piece* ChessBoard::get(int x_position, int y_position){
  return board[x_position][y_position];
}

void ChessBoard::printBoard() const{
  std::cout << "PRINT BOARD" << std::endl;

  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      if (board[row][col] == nullptr){
        std::cout << ". ";
      }
      else{
        std::cout << board[row][col]->getPieceIcon();
      }
    }
    std::cout << " \n";
  }
}
