main:
	g++ src/main.cpp src/Pawn.cpp src/ChessBoard.cpp src/Rook.cpp src/Knight.cpp src/Bishop.cpp -Iinclude -o main

clean:
	rm -rf main
