CC=gcc
CFLAGS=-I.
DEPS=company.h employee.h
OBJ=company.o employee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core driver
