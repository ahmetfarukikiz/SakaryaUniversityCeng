hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Bst.o -c ./src/Bst.cpp
	g++ -I ./include/ -o ./lib/BstNode.o -c ./src/BstNode.cpp
	g++ -I ./include/ -o ./lib/GlobalFonksiyonlar.o -c ./src/GlobalFonksiyonlar.cpp
	g++ -I ./include/ -o ./lib/Program.o -c ./src/Program.cpp
	g++ -I ./include/ -o ./lib/Queue.o -c ./src/Queue.cpp
	g++ -I ./include/ -o ./bin/program.exe ./lib/BstNode.o ./lib/Bst.o ./lib/GlobalFonksiyonlar.o ./lib/Program.o ./lib/Queue.o ./src/main.cpp

calistir:
	./bin/program.exe