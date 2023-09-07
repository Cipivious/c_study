all: hello.i hello.s hello.o hello

hello.i:
	gcc -E hello.c -o hello.i

hello.s: hello.i
	gcc -S hello.i -o hello.s

hello.o: hello.i hello.s
	gcc -c hello.s -o hello.o

hello: hello.i hello.s hello.o
	gcc hello.o -o hello
