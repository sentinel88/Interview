CC=gcc
CFLAGS=-I.
DEPS=list.h
OBJ=topsort.o list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

topsort: $(OBJ)
	 $(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core topsort
