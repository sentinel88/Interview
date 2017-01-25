#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack.h>


int 
main (int argc, char *argv[])
{
	char ch;
        int choice;
        int data;
	int value;
	int size = 0;
	stack s;

	printf("\nEnter the capacity of the stack\n");
	scanf(" %d", &size);
	_init_stack(&s, size);
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
				push(&s, value);
                                break;
                        case 2:
				data = pop(&s);
				printf("\nPopped element from the stack is %d\n", data);
                                break;
                        case 3:
				display(&s);
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
	_free_stack(&s);
	return 0;
}
