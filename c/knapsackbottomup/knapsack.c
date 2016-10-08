#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int
max (int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int 
main(int argc, char *argv[])
{
	int no_items = 0;
	int *wt_items = NULL;
	int *val_items = NULL;
	int **table = NULL;
	int capacity = 0;
	int total_val = 0;
	int i, j;

	printf("\nEnter the number of items\n");
	scanf(" %d", &no_items);
	wt_items = (int *) calloc(no_items, sizeof(int));
	val_items = (int *) calloc(no_items, sizeof(int));
	printf("\nEnter the weight and value for each of the %d items\n", no_items);
	for (i = 0; i < no_items; i++) {
		scanf(" %d %d", &wt_items[i], &val_items[i]);
	}
	printf("\nEnter the capacity of the knapsack\n");
	scanf(" %d", &capacity);
	table = (int **) calloc(no_items, sizeof(int *));
	for (i = 0; i < no_items; i++) {
		table[i] = (int *) calloc(capacity + 1, sizeof(int));
	}
	for (i = 0;  i < no_items; i++) {
		printf("\n");
		for (j = 0; j <= capacity; j++) {
			if (!j) {
				table[i][j] = 0;
				printf("%d ", table[i][j]);
				continue;
			}
			if (!i) {
				if (wt_items[i] <= j)
					table[i][j] = val_items[i];
				else
					table[i][j] = 0;
				printf("%d ", table[i][j]);
				continue;
			}
			if (wt_items[i] <= j) {
				table[i][j] = max(table[i - 1][j - wt_items[i]] + val_items[i], table[i - 1][j]);	
			} else {
				table[i][j] = table[i - 1][j];
			}
			printf("%d ", table[i][j]);
		}
	}	
	printf("\n\n");
	for (i = (no_items - 1); i >= 0; i--) {
		for (j = capacity; j > 0;) {
			if (table[i][j] == table[i - 1][j]) {
				i--;
				continue;
			}
			printf("%d ", i + 1);	
			total_val += val_items[i];
			j = j - wt_items[i];	
			i--;
		}
		if (!j)
			break;
	}
	printf("\n\nTotal Value: %d\n", total_val);
	free(wt_items);
	free(val_items);
	for (i = 0; i < no_items; i++) {
		free(table[i]);
	}
	free(table);

	return 0;
}
