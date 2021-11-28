main : bin/main.o bin/unichar.o bin/board.o
	gcc bin/main.o bin/unichar.o bin/board.o -o main

bitflip : bin/bitflip.o bin/unichar.o
	gcc bin/bitflip.o bin/unichar.o -o bitflip

ra_test : bin/ra_test.o bin/board.o bin/unichar.o
	gcc bin/ra_test.o bin/board.o bin/unichar.o -o ra_test

bin/bitflip.o : src/bitflip.c
	gcc -c src/bitflip.c -o bin/bitflip.o

bin/unichar.o : src/unichar.c
	gcc -c src/unichar.c -o bin/unichar.o

bin/main.o : src/main.c
	gcc -c src/main.c -o bin/main.o

bin/board.o : src/board.c
	gcc -c src/board.c -o bin/board.o

bin/ra_test.o : src/ra_test.c
	gcc -c src/ra_test.c -o bin/ra_test.o
