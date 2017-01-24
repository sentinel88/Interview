CC=gcc
CFLAGS=-std=c99 -I. -g
DEPS=list.h
OBJ=driver.o list.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core driver
