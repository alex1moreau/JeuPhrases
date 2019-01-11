CC=gcc
CFLAGS=-W -Wall -Wextra -std=c99
LDFLAGS=
EXEC=main clean

all: $(EXEC)

main: main.o game.o op.o
	$(CC) -o main game.o op.o main.o $(LDFLAGS)

main.o: main.c game.h op.h
	$(CC) -o main.o -c main.c $(CFLAGS)

game.o: game.c
	$(CC) -o game.o -c game.c $(CFLAGS)

op.o: op.c
	$(CC) -o op.o -c op.c $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
