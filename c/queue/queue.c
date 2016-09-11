#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 10

static int array[QUEUE_SIZE];
static int front = 0;
static int rear = -1;

static void
insert(int elem)
{
	if (rear == (QUEUE_SIZE - 1)) {
		printf("\nQueue is full. Overflow\n");
		return;
	}
	array[++rear] = elem;
}

static int
delete(void)
{
	int elem = 0;

	if (front > rear) {
		printf("\nEmpty queue. Underflow\n");
		return -1;
	}
	elem = array[front];
	front++;
	return elem;
}

static void
display(void)
{
	int i = front;

	printf("\nQUEUE\n");
	while (i <= rear)
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
                printf("\nQueue\n\n");
                printf("1. Insert\n");
                printf("2. Delete\n");
                printf("3. Display\n");
                printf("\nEnter your choice\n");
                scanf("%d", &choice);
                switch (choice)
                {
                        case 1:
                                printf("\nEnter an integer\n");
                                scanf(" %d", &value);
                                insert(value);
                                break;
                        case 2:
				data = delete();
				if (data >= 0)
					printf("\nRemoved element from the queue is %d\n", data);
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
