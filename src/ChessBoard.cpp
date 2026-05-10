#include <iostream>
#include <format>
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
  for (int col{0}; col < 8; col++){
    for (int row{0}; row < 8; row++){
      board[col][row] = nullptr;
    }
  }

  // Pawns: black on rank 7 (row index 1), white on rank 2 (row index 6)
  for (int col{0}; col < 8; col++){ board[col][1] = new Pawn(BLACK); }
  for (int col{0}; col < 8; col++){ board[col][6] = new Pawn(WHITE); }

  // Rooks: a8, h8, a1, h1
  board[0][0] = new Rook(BLACK);
  board[7][0] = new Rook(BLACK);
  board[0][7] = new Rook(WHITE);
  board[7][7] = new Rook(WHITE);

  // Knights: b8, g8, b1, g1
  board[1][0] = new Knight(BLACK);
  board[6][0] = new Knight(BLACK);
  board[1][7] = new Knight(WHITE);
  board[6][7] = new Knight(WHITE);

  // Bishops: c8, f8, c1, f1
  board[2][0] = new Bishop(BLACK);
  board[5][0] = new Bishop(BLACK);
  board[2][7] = new Bishop(WHITE);
  board[5][7] = new Bishop(WHITE);

  // Queens: d8, d1
  board[3][0] = new Queen(BLACK);
  board[3][7] = new Queen(WHITE);

  // Kings: e8, e1
  board[4][0] = new King(BLACK);
  board[4][7] = new King(WHITE);

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

void ChessBoard::printBoard(Color turn) const{
  std::string label = (turn == WHITE) ? "WHITE TO MOVE" : "BLACK TO MOVE";
  std::cout << "                  ████████████████████████\n";
  std::cout << std::format("                  ██ {:^19}██\n", label);

  for (int row{0}; row < 8; row++){
    std::string rowStr;
    for (int col{0}; col < 8; col++){
      rowStr += (board[col][row] == nullptr) ? ". " : board[col][row]->getPieceIcon();
    }
    std::cout << std::format("                  ██ {} {} ██\n", 8 - row, rowStr);
  }

  std::cout << "                  ██   a b c d e f g h  ██\n";
  std::cout << "                  ████████████████████████\n\n";
}
