CC=gcc
CFLAGS=-c -O2 -Wall
LDFLAGS= 
SOURCES= test.c ntt.c ntt.h gf.h
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)