.PHONY: all clean maxclean

CC=gcc
CFLAGS= -Wall -std=c99
LDFLAGS=-lm


graph.o: graph.c graph.h
mainTestBlack.o: mainTestBlack.c
mainTestWhite.o : mainTestWhite.c
mainTestErreur.o: mainTestErreur.c
mainTestLose.o : mainTestLose.c
graph.o mainTestMilieu.o: graph.o mainTestMilieu.c
mainTest4x4.o: mainTest4x4.c

clean:
	rm -rf *.o

maxclean: clean
	  rm -rf $(EXEC)
	  
test1: graph.o mainTestBlack.o
	$(CC) $(CFLAGS) graph.o mainTestBlack.o -o test1 $(LDFLAGS)
	
test2: graph.o mainTestWhite.o
	$(CC) $(CFLAGS) graph.o mainTestWhite.o -o test2 $(LDFLAGS)
	
test3: graph.o mainTestErreur.o
	$(CC) $(CFLAGS) graph.o mainTestErreur.o -o test3 $(LDFLAGS)
	
test4: graph.o mainTestLose.o
	$(CC) $(CFLAGS) graph.o mainTestLose.o -o test4 $(LDFLAGS)
	
test5: graph.o mainTestMilieu.o
	$(CC) $(CFLAGS) graph.o mainTestMilieu.o -o test5 $(LDFLAGS)
	
test6: graph.o mainTest4x4.o
	$(CC) $(CFLAGS) graph.o mainTest4x4.o -o test6 $(LDFLAGS)
