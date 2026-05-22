#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <cstdint>
#include "Piece.h"

class Piece;

struct BoardState {
  Piece* cells[8][8];
  char   epCol;
  int    epRow;
  bool   castleRights[4]; // [wKingside, wQueenside, bKingside, bQueenside]
};

class ChessBoard{
  private:
    Piece* board[8][8];
    char enPassantCol = '\0';
    int  enPassantRow = 0;
    bool castleRights[4] = {true, true, true, true};
    int  halfMoveClock = 0;

  public:
    ChessBoard();
    Piece* get(char col, int row);
    void set(char init_col, int init_row, char new_col, int new_row, Piece* p);
    void clear(char col, int row);
    void printBoard(Color turn) const;
    void setEnPassant(char col, int row);
    void clearEnPassant();
    char getEnPassantCol() const;
    int  getEnPassantRow() const;
    bool hasCastlingRight(Color color, bool kingside) const;
    void revokeCastlingRight(Color color, bool kingside);
    void revokeBothCastlingRights(Color color);
    BoardState saveState() const;
    void restoreState(const BoardState& s);
    int  getHalfMoveClock() const;
    void incrementHalfMoveClock();
    void resetHalfMoveClock();
    void place(char col, int row, Piece* p);
    bool isSquareAttacked(char col, int row, Color byEnemy);
    bool isInCheck(Color color);
    bool hasLegalMove(Color color);
};

#endif
