CC=gcc
CFLAGS=-I. --std=c99
DEPS=heap_lib.h
OBJ=kmerge.o heap_lib.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

kmerge: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core kmerge
