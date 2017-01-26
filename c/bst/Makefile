CC=gcc
CFLAGS=-g -I. -fPIC
DEPS=stack.h
OBJ=driver.o stack.o
EXE=stack
LIB=libstack.so

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(EXE) $(LIB)

$(EXE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

$(LIB): stack.o
	$(CC) -shared -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core $(EXE) $(LIB)
