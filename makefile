main : bin/main.o bin/unichar.o
	gcc bin/main.o bin/unichar.o -o main

bitflip : bin/bitflip.o bin/unichar.o
	gcc bin/bitflip.o bin/unichar.o -o bitflip

bin/bitflip.o : src/bitflip.c
	gcc -c src/bitflip.c -o bin/bitflip.o

bin/unichar.o : src/unichar.c
	gcc -c src/unichar.c -o bin/unichar.o

bin/main.o : src/main.c
	gcc -c src/main.c -o bin/main.o
