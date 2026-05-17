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

constexpr int colIndex(char col) { return tolower(col) - 'a'; }
constexpr int rowIndex(int row)  { return 8 - row; }

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
  return board[colIndex(col)][rowIndex(row)];
}

void ChessBoard::set(char init_col, int init_row, char new_col, int new_row, Piece* p){
  board[colIndex(init_col)][rowIndex(init_row)] = nullptr;
  board[colIndex(new_col)][rowIndex(new_row)]   = p;
}

void ChessBoard::clear(char col, int row){
  board[colIndex(col)][rowIndex(row)] = nullptr;
}

void ChessBoard::setEnPassant(char col, int row){
  enPassantCol = col;
  enPassantRow = row;
}

void ChessBoard::clearEnPassant(){
  enPassantCol = '\0';
  enPassantRow = 0;
}

char ChessBoard::getEnPassantCol() const { return enPassantCol; }
int  ChessBoard::getEnPassantRow() const { return enPassantRow; }

void ChessBoard::printBoard(Color turn) const{
  std::string label = (turn == WHITE) ? "WHITE TO MOVE" : "BLACK TO MOVE";
  std::cout << "                  ████████████████████████\n";
  std::cout << std::format("                  ██ {:^19}██\n", label);

  bool flip = (turn == BLACK);
  for (int i{0}; i < 8; i++){
    int row = flip ? (7 - i) : i;
    std::string rowStr;
    for (int j{0}; j < 8; j++){
      int col = flip ? (7 - j) : j;
      rowStr += (board[col][row] == nullptr) ? ". " : board[col][row]->getPieceIcon();
    }
    std::cout << std::format("                  ██ {} {} ██\n", 8 - row, rowStr);
  }

  std::string colLabel = flip ? "h g f e d c b a" : "a b c d e f g h";
  std::cout << std::format("                  ██   {}  ██\n", colLabel);
  std::cout << "                  ████████████████████████\n\n";
}
