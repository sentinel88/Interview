CC=g++
CFLAGS=-Wall -Wextra -Werror -I.
DEPS=company.h employee.h
OBJ=driver.o company.o employee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core driver
