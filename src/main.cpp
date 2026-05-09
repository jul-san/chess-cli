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
  std::string gameState = "WHITE TO MOVE\n";
  std::cout << "                  " << gameState;
  board.printBoard();

  while (true){
    std::cout << " Enter the coordinates of the piece you want to move -> Row# Col#\n\n";
    std::string from, to;
    std::cin >> from >> to;

    char fromCol = from[0];
    int fromRow = from[1] - '0';

    char toCol = to[0];
    int toRow = to[1] - '0';

    Piece* p = board.get(fromCol, fromRow);
    std::cout << "You have selected " << p->getPieceType() << std::endl;

    p->move(board, fromCol, fromRow, toCol, toRow, WHITE);
    board.printBoard();

  }
  return 0;
}
