hepsi: derle calistir

derle:
	if not exist lib mkdir lib
	if not exist bin mkdir bin
	g++ -I ./include/ -o ./lib/AnaDugum.o -c ./src/AnaDugum.cpp
	g++ -I ./include/ -o ./lib/AnaListe.o -c ./src/AnaListe.cpp
	g++ -I ./include/ -o ./lib/CizimProgrami.o -c ./src/CizimProgrami.cpp
	g++ -I ./include/ -o ./lib/Ekran.o -c ./src/Ekran.cpp
	g++ -I ./include/ -o ./lib/Canvas.o -c ./src/Canvas.cpp
	g++ -I ./include/ -o ./lib/SolMenu.o -c ./src/SolMenu.cpp
	g++ -I ./include/ -o ./lib/AltMenu.o -c ./src/AltMenu.cpp
	g++ -I ./include/ -o ./lib/AnaEkran.o -c ./src/AnaEkran.cpp
	g++ -I ./include/ -o ./lib/Sekil.o -c ./src/Sekil.cpp
	g++ -I ./include/ -o ./lib/Ucgen.o -c ./src/Ucgen.cpp
	g++ -I ./include/ -o ./lib/Yildiz.o -c ./src/Yildiz.cpp
	g++ -I ./include/ -o ./lib/Dikdortgen.o -c ./src/Dikdortgen.cpp
	g++ -I ./include/ -o ./lib/SekilDugum.o -c ./src/SekilDugum.cpp
	g++ -I ./include/ -o ./lib/SekilListe.o -c ./src/SekilListe.cpp
	g++ -I ./include/ -o ./lib/GlobalFonksiyonlar.o -c ./src/GlobalFonksiyonlar.cpp
	g++ -I ./include/ -o ./bin/program.exe ./lib/GlobalFonksiyonlar.o ./lib/AnaDugum.o ./lib/AnaListe.o ./lib/CizimProgrami.o ./lib/AnaEkran.o ./lib/Canvas.o ./lib/SolMenu.o ./lib/AltMenu.o ./lib/Ekran.o ./lib/Dikdortgen.o ./lib/Yildiz.o ./lib/Ucgen.o ./lib/Sekil.o ./lib/SekilDugum.o ./lib/SekilListe.o ./src/Main.cpp

calistir: ./bin/program.exe
	./bin/program.exe