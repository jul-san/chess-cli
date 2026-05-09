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
  for (int row{0}; row < 8; row++){
    for (int col{0}; col < 8; col++){
      board[row][col] = nullptr;
    }
  }

  // Pawns
  for (int col{0}; col < 8; col++){ board[1][col] = new Pawn(BLACK); }
  for (int col{0}; col < 8; col++){ board[6][col] = new Pawn(WHITE); }

  // Rooks
  board[0][0] = new Rook(BLACK);
  board[0][7] = new Rook(BLACK);
  board[7][0] = new Rook(WHITE);
  board[7][7] = new Rook(WHITE);

  board[0][1] = new Knight(BLACK);
  board[0][6] = new Knight(BLACK);
  board[7][1] = new Knight(WHITE);
  board[7][6] = new Knight(WHITE);

  board[0][2] = new Bishop(BLACK);
  board[0][5] = new Bishop(BLACK);
  board[7][2] = new Bishop(WHITE);
  board[7][5] = new Bishop(WHITE);

  board[0][3] = new Queen(BLACK);
  board[7][3] = new Queen(WHITE);

  board[0][4] = new King(BLACK);
  board[7][4] = new King(WHITE);

}

Piece* ChessBoard::get(char col, int row){
  int c = tolower(col) - 'a';
  int r = 8 - row;
  return board[c][r];
}

void ChessBoard::set(char init_col, int init_row, char new_col, int new_row, Piece* p){
  int ic = tolower(init_col) - 'a';  int ir = 8 - init_row;
  int nc = tolower(new_col)  - 'a';  int nr = 8 - new_row;
  board[ic][ir] = nullptr;
  board[nc][nr] = p;
}

void ChessBoard::printBoard() const{
  std::cout << "                  ████████████████████████" << std::endl;
  std::cout << "                  ██                    ██" << std::endl;

  int num_of_rows = 8;
  for (int row{0}; row < 8; row++){
    std::cout << "                  ██ " << num_of_rows - row << " ";
    
    for (int col{0}; col < 8; col++){
      if (board[col][row] == nullptr){
        std::cout << ". ";
      }
      else{
        std::cout << board[col][row]->getPieceIcon();
      }
    }

    std::cout << " ██";
    std::cout << " \n";
  }
  std::cout << "                  ██   A B C D E F G H  ██" << std::endl;
  std::cout << "                  ████████████████████████\n\n" << std::endl;
}
