CC=gcc
CFLAGS=-std=c99 -c -O2 -Wall
LDFLAGS= 
SOURCES= lin_kruh_konvol_Chlebovec.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main
all: $(SOURCES) $(EXECUTABLE)
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@
clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)