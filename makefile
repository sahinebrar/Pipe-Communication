OBJS = prog1 prog2 prog3 main
CC = gcc

all: prog1 prog2 prog3 main

prog1:
	$(CC) prog1.c -o prog1
prog2:
	$(CC) prog2.c -o prog2
prog3:
	$(CC) prog3.c -o prog3
main:
	$(CC) main.c -o main
clean:
	rm -rf $(OBJS)
