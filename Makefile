CFLAGS=-O -lm
LDFLAGS=
CC=gcc

all : test testNode
test: test.o mc48.o attack.o utils.o node.o
	$(CC) -o test test.o attack.o mc48.o utils.o node.o -lm

testNode: testNode.o node.o
	$(CC) -o testNode testNode.o node.o

attack.o: attack.c attack.h mc48.h node.h utils.h
	gcc -o attack.o -c attack.c $(CFLAGS)

mc48.o: mc48.c mc48.h
	gcc -o mc48.o -c mc48.c $(CFLAGS)
	
node.o: node.c node.h
	gcc -o node.o -c node.c $(CFLAGS)
	
utils.o: utils.c utils.h
	gcc -o utils.o -c utils.c $(CFLAGS)

testNode.o: testNode.c node.h
	gcc -o testNode.o -c testNode.c $(CFLAGS)
	
test.o: test.c attack.h utils.h
	gcc -o test.o -c test.c $(CFLAGS)

clean:
	rm -rf *.o testNode test