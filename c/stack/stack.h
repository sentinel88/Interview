#ifndef _STACK_H
#define _STACK_H

#define STACK_SIZE 10

typedef struct
{
        int size;
        int *items;
        int top;
} stack;


void
_init_stack (stack *s, int size);


void 
_free_stack (stack *s);


void
push (stack *s, int elem);


int 
pop (stack *s);


void
display (stack *s);


#endif
