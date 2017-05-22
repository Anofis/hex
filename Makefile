.PHONY: all clean maxclean




all:	
	./compiler.sh

	
	


clean:
	rm -rf *.o

maxclean: clean
	  rm -rf $(EXEC) *.class *.o *.so
