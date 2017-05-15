.PHONY: all clean maxclean

CC=gcc
CFLAGS= -Wall -std=c99
LDFLAGS=-lm
EXEC=hex
OBJ=graph.o main.o short_graph.o

all:	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(EXEC) $(LDFLAGS)

graph.o: graph.c graph.h
short_graph.o: short_graph.c short_graph.h
main.o: main.c graph.h

clean:
	rm -rf *.o

maxclean: clean
	  rm -rf $(EXEC)
