.PHONY: compile run clean
compile main: main.o
	@gcc -o main main.o
main.o: main.c
	@gcc -c main.c -Wall
run: main
	@./main
clean:
	@rm -f *.o main
