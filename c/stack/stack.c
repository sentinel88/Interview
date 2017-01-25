#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"


void
_init_stack(stack *s, int size)
{
        s->size = size;
        s->items = (int *) calloc (sizeof(int), size);
        s->top = -1;
}


void
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


void
push(stack *s, int elem)
{
        if (s->top == (s->size - 1)) {
                printf("\nStack is full. Overflow\n");
                return;
        }
        s->top += 1;
        s->items[s->top] = elem;
}


int
pop(stack *s)
{
        int elem = 0;

        if (s->top == -1) {
                printf("\nEmpty stack. Underflow\n");
                return -1;
 	}
        elem = s->items[s->top];
        s->top -= 1;
        return elem;
}


void
display(stack *s)
{
        int i = s->top;

        printf("\nSTACK\n");
        while (i >= 0)
                printf("%d ", s->items[i--]);
}
