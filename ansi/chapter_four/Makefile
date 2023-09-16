all: stack.o getop.o getch.o calculator.o
	gcc stack.o getop.o getch.o calculator.o -o calculator

stack.o:
	gcc -c stack.c -o stack.o

getop.o:
	gcc -c getop.c -o getop.o

getch.o:
	gcc -c getch.c -o getch.o

calculator.o:
	gcc -c calculator.c -o calculator.o

clean:
	rm stack.o getop.o getch.o calculator.o
