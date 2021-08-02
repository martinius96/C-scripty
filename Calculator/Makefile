CFLAGS= -std=c99 -g

all: calculator

%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

calculator.o: calculator.c
	gcc -c calculator.c -o calculator.o
main.o: main.c
	gcc -c main.c -o main.o
calculator: main.o calculator.o
	gcc main.o calculator.o -o calculator
clean:
	rm *.o calculator

test: calculator.c tests/test.c
	gcc calculator.c tests/test.c tests/unity.c -Itests -o test
	./test
