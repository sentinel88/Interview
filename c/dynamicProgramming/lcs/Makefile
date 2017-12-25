CC=gcc
CFLAGS=-I.
COMMON_LIB_PATH=/Interview/c/matrix/common
DEPS=$(COMMON_LIB_PATH)/matrix.h
OBJ=driver.o
LIB=lmatrix

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ) 
	$(CC) -L$(COMMON_LIB_PATH) -o $@ $^ $(CFLAGS) -$(LIB)

.PHONY: clean

clean: 
	rm -f *.o core driver
