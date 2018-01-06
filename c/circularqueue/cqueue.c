#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QUEUE_SIZE 5

int array[QUEUE_SIZE];
int front = 0;
int rear = -1;

void
enqueue(int elem)
{
	if ( (rear != -1) && ((rear + 1) % QUEUE_SIZE == front)) {
		printf("\nQueue is full. Overflow\n");
		return;
	}
	if (front == -1)
		front = 0;
	rear = (rear + 1) % QUEUE_SIZE;
	array[rear] = elem;
	printf("\nFront: %d   Rear: %d\n", front, rear);
}

int
dequeue(void)
{
	int elem = 0;

	if (front == -1) {
		printf("\nEmpty queue. Underflow\n");
		return -1;
	}
	elem = array[front];
	if (front == rear) {
		front = -1;
	} else {
        	front = (front + 1) % QUEUE_SIZE;
	}
	printf("\nFront: %d   Rear: %d\n", front, rear);

	return elem;
}

void
display(void)
{
	int i = front;

	if (front == -1) {
		printf("\nEmpty Queue\n");
		return;
	}
	printf("\nQUEUE\n");
	while (1) {
		printf("\ni: %d   Rear: %d\t", i, rear);
		printf("%d ", array[i]);
		if (i == rear)
			break;
		i = (i + 1) % QUEUE_SIZE;
	}
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
                                enqueue(value);
                                break;
                        case 2:
				data = dequeue();
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
