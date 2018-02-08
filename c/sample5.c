#include <stdlib.h>
#include <stdio.h>

int i =0;

void f1(void)

{

static int k;

i = 50;

printf("%d\n",k);

}

int main()

{

int j;

f1();

i =0;

printf(" i in main %d\n",i);

f1();

printf(" i after call%d\n",i);
return 0;
}
