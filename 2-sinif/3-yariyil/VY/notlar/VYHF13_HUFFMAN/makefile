hepsi: derle calistir
derle:
	if not exist lib mkdir lib
	if not exist bin mkdir bin
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Huffman.o -c ./src/Huffman.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Huffman.o ./lib/Node.o ./src/Test.cpp    
calistir:
	./bin/Test