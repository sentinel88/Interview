#include "Stack.h"

Stack::Stack():top(-1),
		size(Stack::DEFAULT_SIZE),
		elems(Stack::DEFAULT_SIZE)
{
}


Stack::Stack(int inSize):top(-1),
			size(inSize),
			elems(inSize)
{
}



