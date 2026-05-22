#include <iostream>
#include <format>
#include <sstream>
#include <cstdint>
#include <cstring>
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

void ChessBoard::place(char col, int row, Piece* p){
  board[colIndex(col)][rowIndex(row)] = p;
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

int  ChessBoard::getHalfMoveClock() const        { return halfMoveClock; }
void ChessBoard::incrementHalfMoveClock()         { halfMoveClock++; }
void ChessBoard::resetHalfMoveClock()             { halfMoveClock = 0; }

static int castleIdx(Color c, bool kingside) {
  return (c == WHITE ? 0 : 2) + (kingside ? 0 : 1);
}

bool ChessBoard::hasCastlingRight(Color c, bool kingside) const {
  return castleRights[castleIdx(c, kingside)];
}

void ChessBoard::revokeCastlingRight(Color c, bool kingside) {
  castleRights[castleIdx(c, kingside)] = false;
}

void ChessBoard::revokeBothCastlingRights(Color c) {
  castleRights[castleIdx(c, true)]  = false;
  castleRights[castleIdx(c, false)] = false;
}

BoardState ChessBoard::saveState() const {
  BoardState s;
  std::memcpy(s.cells, board, sizeof(board));
  s.epCol = enPassantCol;
  s.epRow = enPassantRow;
  std::memcpy(s.castleRights, castleRights, sizeof(castleRights));
  return s;
}

void ChessBoard::restoreState(const BoardState& s) {
  std::memcpy(board, s.cells, sizeof(board));
  enPassantCol = s.epCol;
  enPassantRow = s.epRow;
  std::memcpy(castleRights, s.castleRights, sizeof(castleRights));
}

bool ChessBoard::isSquareAttacked(char sCol, int sRow, Color byEnemy) {
  // Pawn attacks: white pawns sit one row below the target, black one row above
  int pawnRow = (byEnemy == WHITE) ? sRow - 1 : sRow + 1;
  for (int dc = -1; dc <= 1; dc += 2) {
    char pc = sCol + dc;
    if (pc >= 'a' && pc <= 'h' && pawnRow >= 1 && pawnRow <= 8) {
      Piece* p = get(pc, pawnRow);
      if (p && p->getPieceType() == PAWN && p->getPieceColor() == byEnemy)
        return true;
    }
  }

  // Knight attacks
  const int kDx[] = { 2, 2,-2,-2, 1, 1,-1,-1};
  const int kDy[] = { 1,-1, 1,-1, 2,-2, 2,-2};
  for (int i = 0; i < 8; i++) {
    char nc = sCol + kDx[i]; int nr = sRow + kDy[i];
    if (nc >= 'a' && nc <= 'h' && nr >= 1 && nr <= 8) {
      Piece* p = get(nc, nr);
      if (p && p->getPieceType() == KNIGHT && p->getPieceColor() == byEnemy)
        return true;
    }
  }

  // Diagonal attacks (bishop or queen)
  const int bDx[] = { 1, 1,-1,-1};
  const int bDy[] = { 1,-1, 1,-1};
  for (int i = 0; i < 4; i++) {
    char c = sCol + bDx[i]; int r = sRow + bDy[i];
    while (c >= 'a' && c <= 'h' && r >= 1 && r <= 8) {
      Piece* p = get(c, r);
      if (p) {
        if (p->getPieceColor() == byEnemy &&
            (p->getPieceType() == BISHOP || p->getPieceType() == QUEEN))
          return true;
        break;
      }
      c += bDx[i]; r += bDy[i];
    }
  }

  // Straight attacks (rook or queen)
  const int rDx[] = { 1,-1, 0, 0};
  const int rDy[] = { 0, 0, 1,-1};
  for (int i = 0; i < 4; i++) {
    char c = sCol + rDx[i]; int r = sRow + rDy[i];
    while (c >= 'a' && c <= 'h' && r >= 1 && r <= 8) {
      Piece* p = get(c, r);
      if (p) {
        if (p->getPieceColor() == byEnemy &&
            (p->getPieceType() == ROOK || p->getPieceType() == QUEEN))
          return true;
        break;
      }
      c += rDx[i]; r += rDy[i];
    }
  }

  // Adjacent enemy king
  for (int dc = -1; dc <= 1; dc++) for (int dr = -1; dr <= 1; dr++) {
    if (dc == 0 && dr == 0) continue;
    char nc = sCol + dc; int nr = sRow + dr;
    if (nc >= 'a' && nc <= 'h' && nr >= 1 && nr <= 8) {
      Piece* p = get(nc, nr);
      if (p && p->getPieceType() == KING && p->getPieceColor() == byEnemy)
        return true;
    }
  }

  return false;
}

bool ChessBoard::isInCheck(Color color) {
  char kCol = '\0'; int kRow = 0;
  for (char c = 'a'; c <= 'h'; c++)
    for (int r = 1; r <= 8; r++) {
      Piece* p = get(c, r);
      if (p && p->getPieceColor() == color && p->getPieceType() == KING)
        { kCol = c; kRow = r; }
    }
  if (kCol == '\0') return false;
  return isSquareAttacked(kCol, kRow, (color == WHITE) ? BLACK : WHITE);
}

bool ChessBoard::hasLegalMove(Color color) {
  std::ostringstream devNull;
  for (char fc = 'a'; fc <= 'h'; fc++) {
    for (int fr = 1; fr <= 8; fr++) {
      Piece* p = get(fc, fr);
      if (!p || p->getPieceColor() != color) continue;
      for (char tc = 'a'; tc <= 'h'; tc++) {
        for (int tr = 1; tr <= 8; tr++) {
          BoardState saved = saveState();
          std::streambuf* orig = std::cout.rdbuf(devNull.rdbuf());
          bool moved = p->move(*this, fc, fr, tc, tr, color);
          std::cout.rdbuf(orig);
          if (moved) {
            bool safe = !isInCheck(color);
            restoreState(saved);
            if (safe) return true;
          }
        }
      }
    }
  }
  return false;
}

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
