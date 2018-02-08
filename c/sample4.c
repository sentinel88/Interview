#include <stdlib.h>
#include <stdio.h>

int main(void)

{

int **pptr,*ptr, q;

ptr = &q;

pptr = &ptr;

q = 1;

printf("%p\n ", ptr);

*ptr++;

printf("%d %p\n", q, ptr);

printf("%d %p\n", q, pptr);
**pptr++;

printf("%d %p %p\n", q, pptr, *pptr);

}
