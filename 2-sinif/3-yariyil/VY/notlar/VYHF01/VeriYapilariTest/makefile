hepsi: derle calistir

derle:
	if not exist lib mkdir lib
	if not exist bin mkdir bin
	g++ -I ./include/ -o ./lib/Ogrenci.o -c ./src/Ogrenci.cpp

	g++ -I ./include/ -o ./bin/Test ./lib/Ogrenci.o ./src/Test.cpp

calistir: ./bin/Test.exe
	./bin/Test.exe