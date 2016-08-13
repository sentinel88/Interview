CC=gcc
CFLAGS=-I.
DEPS=list.h
OBJ=driver.o list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bst: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core bst
