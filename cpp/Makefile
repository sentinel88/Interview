CC=g++
#CFLAGS=-g -Wall -Wextra -Werror -I.
CFLAGS=-g -I. -std=c++11
DEPS=company.h employee.h
OBJ=driver.o company.o employee.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

driver: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core driver
