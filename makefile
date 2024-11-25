.PHONY: run compile clean
compile: main.o
	gcc -o program main.o -Wall
main.o: main.c
	gcc -c main.c -Wall
run: program
	./program
clean:
	rm -f *.o
	rm program
