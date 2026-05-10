main:
	g++ -std=c++20 src/main.cpp src/Pawn.cpp src/ChessBoard.cpp src/Rook.cpp src/Knight.cpp src/Bishop.cpp src/Queen.cpp src/King.cpp -Iinclude -o main

clean:
	rm -rf main
