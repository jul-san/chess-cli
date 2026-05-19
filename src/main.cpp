#include <iostream>
#include <format>
#include "ChessBoard.h"
#include "Pawn.h"

void printLogo() {

  std::cout << "\n";
  std::cout << "  ██████╗██╗  ██╗███████╗███████╗███████╗     ██████╗██╗     ██╗\n";
  std::cout << " ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝    ██╔════╝██║     ██║\n";
  std::cout << " ██║     ███████║█████╗  ███████╗███████╗    ██║     ██║     ██║\n";
  std::cout << " ██║     ██╔══██║██╔══╝  ╚════██║╚════██║    ██║     ██║     ██║\n";
  std::cout << " ╚██████╗██║  ██║███████╗███████║███████║    ╚██████╗███████╗██║\n";
  std::cout << "  ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝     ╚═════╝╚══════╝╚═╝\n";
  std::cout << "\n";
}

int main(){
  printLogo();

  std::cout << "                    Welcome to Chess CLI!\n";
  std::cout << "              Your command-line chess experience\n\n";

  std::cout << "             What color would you like to play as?\n";
  std::cout << "                      (1) White Pieces\n";
  std::cout << "                      (2) Black Pieces\n\n";

  int userChoice = 0;
  std::cin >> userChoice;
  
  ChessBoard board;
  Color currentTurn = WHITE;
  board.printBoard(currentTurn);

  while (true){
    if (board.isInCheck(currentTurn)){
      std::string cs = (currentTurn == WHITE) ? "White" : "Black";
      std::cout << std::format(" *** {} is in check! ***\n", cs);
    }
    std::cout << " Enter move in algebraic notation (e.g. e2 e4)\n\n";
    std::string from, to;
    std::cin >> from >> to;

    char fromCol = from[0];
    int fromRow = from[1] - '0';

    char toCol = to[0];
    int toRow = to[1] - '0';

    Piece* p = board.get(fromCol, fromRow);

    if (p == nullptr || p->getPieceColor() != currentTurn){
      std::string turnStr = (currentTurn == WHITE) ? "WHITE" : "BLACK";
      std::cout << std::format("You can only move {} pieces.\n", turnStr);
      board.printBoard(currentTurn);
      continue;
    }

    BoardState saved = board.saveState();
    bool legal = p->move(board, fromCol, fromRow, toCol, toRow, currentTurn);

    if (legal && board.isInCheck(currentTurn)){
      board.restoreState(saved);
      std::cout << "Illegal move: that leaves your king in check.\n";
      legal = false;
    }

    if (legal){
      bool wasDoublePush = (p->getPieceType() == PAWN && std::abs(fromRow - toRow) == 2);
      if (!wasDoublePush) board.clearEnPassant();
      currentTurn = (currentTurn == WHITE) ? BLACK : WHITE;

      if (!board.hasLegalMove(currentTurn)){
        board.printBoard(currentTurn);
        if (board.isInCheck(currentTurn)){
          std::string winner = (currentTurn == WHITE) ? "BLACK" : "WHITE";
          std::cout << std::format(" Checkmate! {} wins!\n", winner);
        } else {
          std::cout << " Stalemate! The game is a draw.\n";
        }
        break;
      }
    }
    board.printBoard(currentTurn);

  }
  return 0;
}
