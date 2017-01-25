#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 10

typedef struct 
{
	int size;
	int *items;
	int top;
} stack;

//static int array[STACK_SIZE];
//static int count_elem = -1;


static void
_init_stack(stack *s, int size)
{
	s->size = size;
	s->items = (int *) calloc (sizeof(int), size);
	s->top = -1;
}	


static void
_free_stack(stack *s)
{
	if (s->top == -1) {
		printf("\nEmpty stack. Nothing to deallocate\n");
		return;
	}
	s->top = -1;
	free(s->items);
	s->items = NULL;
	printf("\nStack deallocated\n");
}

static void
//push(int elem)
push(stack *s, int elem)
{
	//if (count_elem == (STACK_SIZE - 1)) {
	if (s->top == (s->size - 1)) {
		printf("\nStack is full. Overflow\n");
		return;
	}
	s->top += 1;
	s->items[s->top] = elem;
	//array[++count_elem] = elem;
}

static int
//pop(void)
pop(stack *s)
{
	int elem = 0;

	//if (count_elem == -1) {
	if (s->top == -1) {
		printf("\nEmpty stack. Underflow\n");
		return -1;
	}
	//elem = array[count_elem];
	elem = s->items[s->top];
	//count_elem--;
	s->top -= 1;
	return elem;
}

static void
//display(void)
display(stack *s)
{
	int i = s->top;

	printf("\nSTACK\n");
	//while (i <= count_elem)
	while (i >= 0)
		//printf("%d ", array[i++]);
		printf("%d ", s->items[i--]);
}

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
