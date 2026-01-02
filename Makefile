main:
	g++ src/main.cpp src/Pawn.cpp src/ChessBoard.cpp -Iinclude -o main

clean:
	rm -rf main
