hepsi: derle calistir

derle:
	gcc -I ./include/ -o ./lib/Topluluk.o -c ./src/Topluluk.c
	gcc -I ./include -o ./lib/Koleksiyon.o -c ./src/Koleksiyon.c
	gcc -I ./include -o ./bin/Test.exe ./lib/Koleksiyon.o ./lib/Topluluk.o ./src/Test.c

calistir: ./bin/Test.exe
	./bin/Test