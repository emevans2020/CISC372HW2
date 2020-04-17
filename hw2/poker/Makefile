run : poker
	./poker.exe 1000000

poker : poker.o
	cc -o poker.exe poker.o

poker.o : poker.c
	cc -c -std=c11 -pedantic poker.c

clean :
	rm -f *.exe *~ *.o
