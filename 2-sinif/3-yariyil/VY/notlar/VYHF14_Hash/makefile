hepsi: derle calistir
derle:
	if not exist lib mkdir lib
	if not exist bin mkdir bin
	g++ -I ./include/ -o ./lib/DoubleHash.o -c ./src/DoubleHash.cpp
	g++ -I ./include/ -o ./lib/OpenHash.o -c ./src/OpenHash.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/OpenHash.o ./lib/DoubleHash.o ./src/Test.cpp    
calistir:
	./bin/Test