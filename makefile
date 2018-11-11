all: signal.o
	gcc -o test signal.o

signal.o: signal.c
	gcc -c signal.c

run:
	./test

clean:
	rm *.o
	rm error.txt
	rm test