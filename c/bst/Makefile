CC=gcc
CFLAGS=-I.
DEPS=node.h
OBJ=driver.o node.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bst: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core bst
