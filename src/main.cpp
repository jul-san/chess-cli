#include <iostream>
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
    std::cout << " Enter move in algebraic notation (e.g. e2 e4)\n\n";
    std::string from, to;
    std::cin >> from >> to;

    char fromCol = from[0];
    int fromRow = from[1] - '0';

    char toCol = to[0];
    int toRow = to[1] - '0';

    Piece* p = board.get(fromCol, fromRow);
    p->move(board, fromCol, fromRow, toCol, toRow, currentTurn);

    currentTurn = (currentTurn == WHITE) ? BLACK : WHITE;
    board.printBoard(currentTurn);

  }
  return 0;
}
