CFLAGS= -std=gnu99 -g

all: pizza2

%.o: %.c
	gcc -c -o $@ $< $(CFLAGS)

pizza2: main.o pizza2.o
	gcc main.o pizza2.o -o pizza2
clean:
	rm *.o pizza2 test
test: pizza2.c tests/test.c
	gcc pizza2.c tests/test.c tests/unity.c -Itests -o test
	./test
