hepsi:delete derle calistir

derle:libfdr.a
	gcc ./src/islem.c -I ./include -o ./bin/islem   -L ./lib -lfdr


libfdr.a: dllist.o fields.o jval.o jrb.o
	ar ru ./lib/libfdr.a ./lib/dllist.o ./lib/fields.o ./lib/jval.o ./lib/jrb.o
	ranlib ./lib/libfdr.a

fields.o: ./src/fields.c
	gcc -I ./include -c ./src/fields.c  -o ./lib/fields.o

jval.o: ./src/jval.c
	gcc -I ./include -c ./src/jval.c  -o ./lib/jval.o

dllist.o: ./src/dllist.c
	gcc -I ./include -c ./src/dllist.c  -o ./lib/dllist.o

jrb.o: ./src/jrb.c
	gcc -I ./include -c ./src/jrb.c  -o ./lib/jrb.o

calistir:
	./bin/islem

delete:
	rm -rf ./bin/* ./lib/*
