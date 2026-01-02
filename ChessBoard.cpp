#include <iostream>
#include <cstdint>
#include "ChessBoard.h"
#include "Piece.h"
#include "Pawn.h"

ChessBoard::ChessBoard(){
  for (int row = 0; row < 8; row++){
    for (int col = 0; col < 8; col++){
      board[row][col] = nullptr;
    }
  }

  board[1][0] = new Pawn(BLACK);
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
