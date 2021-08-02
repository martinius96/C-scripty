all: pizza1
pizza1.o: pizza1.c
	gcc -c pizza1.c -o pizza1.o
main.o: main.c
	gcc -c main.c -o main.o
pizza1: main.o pizza1.o
	gcc main.o pizza1.o -o pizza1
clean:
	rm ./*.o pizza1 test
test: pizza1.c tests/test.c
	gcc pizza1.c tests/test.c tests/unity.c -Itests -o test
	./test
