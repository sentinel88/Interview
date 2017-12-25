CC=gcc
CFLAGS=-g -I. -fPIC
DEPS=matrix.h
OBJ=matrix.o
LIB=libmatrix.so

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(LIB): matrix.o
	$(CC) -shared -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core libmatrix.so
