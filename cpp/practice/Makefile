CC=g++
#CFLAGS=-g -Wall -Wextra -Werror -I.
CFLAGS=-g -I. -std=c++11
DEPS=stack.h 
#OBJ=driver.o company.o employee.o
OBJ=stack.o 

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

stack: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean: 
	rm -f *.o core stack
