hepsi: derle test calistir
derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/KuyrukListe.o -c ./src/KuyrukListe.cpp
	g++ -I ./include/ -o ./lib/DugumAgac.o -c ./src/DugumAgac.cpp
	g++ -I ./include/ -o ./lib/Agac.o -c ./src/Agac.cpp
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp	
test:
	g++ -I ./include/ -o ./bin/Test ./lib/Dugum.o ./lib/KuyrukListe.o ./lib/DugumAgac.o ./lib/Agac.o ./lib/Sayi.o ./src/test.cpp
calistir:
	./bin/Test
