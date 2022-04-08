CFLAGS=-W -Wall -g
LDFLAGS=
CC=gcc

all : test testNode
test: test.o attack.o mc48.o node.o
	$(CC) -o test test.o attack.o mc48.o node.o

testNode: testNode.o node.o
	$(CC) -o testNode testNode.o node.o

attack.o: attack.c attack.h mc48.h node.h
	gcc -o attack.o -c attack.c $(CFLAGS)

mc48.o: mc48.c mc48.h
	gcc -o mc48.o -c mc48.c $(CFLAGS)
	
node.o: node.c node.h
	gcc -o node.o -c node.c $(CFLAGS)

testNode.o: testNode.c node.h
	gcc -o testNode.o -c testNode.c $(CFLAGS)
	
test.o: test.c attack.h
	gcc -o test.o -c test.c $(CFLAGS)

clean:
	rm -rf *.o testNode test