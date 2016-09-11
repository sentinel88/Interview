#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

static int array[STACK_SIZE];
static int count_elem = -1;

static void
push(int elem)
{
	if (count_elem == (STACK_SIZE - 1)) {
		printf("\nStack is full. Overflow\n");
		return;
	}
	array[++count_elem] = elem;
}

static int
pop(void)
{
	int elem = 0;

	if (count_elem == -1) {
		printf("\nEmpty stack. Underflow\n");
		return -1;
	}
	elem = array[count_elem];
	count_elem--;
	return elem;
}

static void
display(void)
{
	int i = 0;

	printf("\nSTACK\n");
	while (i <= count_elem)
		printf("%d ", array[i++]);
}

int 
main (int argc, char *argv[])
{
	char ch;
        int choice;
        int data;
	int value;

        while (1) {
                printf("\nStack\n\n");
                printf("1. Push\n");
                printf("2. Pop\n");
                printf("3. Display\n");
                printf("\nEnter your choice\n");
                scanf("%d", &choice);
                switch (choice)
                {
                        case 1:
                                printf("\nEnter an integer\n");
                                scanf(" %d", &value);
                                push(value);
                                break;
                        case 2:
				data = pop();
				if (data >= 0)
					printf("\nPopped element from the stack is %d\n", data);
                                break;
                        case 3:
				display();
                                break;
                        default:
                                printf("\nWrong choice. Doing nothing\n");
                }
                printf("Do you want to continue (y/n) ??");
                scanf(" %c", &ch);
                if (ch == 'n' || ch == 'N') {
                        printf("\nBreaking the driver loop\n");
                        break;
                }
        }
	return 0;
}
