hepsi: derle test calistir
derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./lib/Islem.o -c ./src/Islem.cpp
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp	
test:
	g++ -I ./include/ -o ./bin/Test ./lib/Dugum.o ./lib/Liste.o ./lib/Islem.o ./lib/Sayi.o ./src/test.cpp
calistir:
	./bin/Test
