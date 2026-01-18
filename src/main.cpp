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
  board.printBoard();

  while (true){
    std::cout << " Enter the coordinates of the piece you want to move -> Row# Col#\n\n";
    int row{}, col{};
    std::cin >> row >> col;

    Piece* p = board.get(row, col);
    std::cout << "You have selected " << p->getPieceType() << std::endl;

    std::cout << "Where would you like to move the piece?\n\n";

    int toRow{}, toCol{};
    std::cin >> toRow >> toCol;
    
    p->move(board, row, col, toRow, toCol, WHITE);
    board.printBoard();

  }
  return 0;
}
