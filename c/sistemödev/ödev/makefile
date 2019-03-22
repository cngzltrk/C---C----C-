#her kottan sonra bir boşluk
#ilk kodu bakıp bağımlılık sırasına göre aşağı doğru inip sonra yukarı çıkar
SRC=./src
INC=./inc
LIB=./lib


all: source calistir

source: libfdr.a
	gcc -I ./inc/ -o ./lib/source -c ./src/source.c
	gcc -I ./inc/ -o ./bin/main ./lib/source ./src/main.c -L ./lib/ -lfdr

libfdr.a: dllist.o fields.o jval.o jrb.o
	ar ru $(LIB)/libfdr.a $(LIB)/dllist.o $(LIB)/fields.o $(LIB)/jval.o $(LIB)/jrb.o
	ranlib $(LIB)/libfdr.a

fields.o: $(SRC)/fields.c
	gcc -I $(INC) -c $<  -o $(LIB)/fields.o

jval.o: $(SRC)/jval.c
	gcc -I $(INC) -c $<  -o $(LIB)/jval.o

dllist.o: $(SRC)/dllist.c
	gcc -I $(INC) -c $<  -o $(LIB)/dllist.o

jrb.o: $(SRC)/jrb.c
	gcc -I $(INC) -c $<  -o $(LIB)/jrb.o

calistir:
	./bin/main

sil:
	rm -rf ./bin/* $(LIB)/*
