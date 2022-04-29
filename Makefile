CFLAGS=-O3 -lm
LDFLAGS=
CC=gcc

all : test 
test: test.o mc48.o attack.o utils.o node.o
	$(CC) -o test test.o attack.o mc48.o utils.o node.o -lm

attack.o: attack.c attack.h mc48.h node.h utils.h
	gcc -o attack.o -c attack.c $(CFLAGS)

mc48.o: mc48.c mc48.h
	gcc -o mc48.o -c mc48.c $(CFLAGS)
	
node.o: node.c node.h
	gcc -o node.o -c node.c $(CFLAGS)
	
utils.o: utils.c utils.h
	gcc -o utils.o -c utils.c $(CFLAGS)
	
test.o: test.c attack.h utils.h
	gcc -o test.o -c test.c $(CFLAGS)

clean:
	rm -rf *.o test