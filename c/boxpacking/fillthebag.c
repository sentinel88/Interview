/* Fill the bag with boxes of different weights and sizes (calculate volume). Assumptions: The bag is assumed to have an upper limit in terms of weight and volume. Boxes are cubes and are solid. We will try to maximize the number of boxes we can pack in the bag in every loading cycle and minimize the total number of loading cycles. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ITEM_COUNT 5

/* We calculate something called as the fit factor that is equal to max (wratio, vratio). wratio is (weight/volume) and vratio is (volume/weight). Boxes can be of any shape and size. In order to consider this we need two ratios to cover boxes which are heavier but less volume or vice versa. We then sort the boxes according to fit factor and fill them in the bag until they do not exceed the capacity of the bag (weight, volume). */

static void
fillthebag (int *weight, int *volume, int *bag_capacity)
{
	bool select[ITEM_COUNT];
	int i, j;
	int item_count = ITEM_COUNT;	
	bool full = false;

	memset(select, 0, ITEM_COUNT);	
	while (item_count) {
		fill_count = 0;
		full = false;
		while (!full) {
		}
		item_count -= fill_count;
	}
}

int 
main (int argc, char *argv[])
{
	int weight[ITEM_COUNT];
	int size[ITEM_COUNT];
	int volume[ITEM_COUNT];
	int bag_capacity[2];

	printf("\nEnter the capacity of the bag\n");
	scanf(" %d %d", &bag_capacity[0], &bag_capacity[1]);
	
	for (i = 0; i < ITEM_COUNT; i++) {
		printf("Enter the weight and size of box %d\n", i + 1);
		scanf(" %d %d", &weight[i], &size[i]);
		volume[i] = size[i] * size[i] * size[i];
	}	
	printf("\nCollection (weight, volume)\n\n");
	for (i = 0; i < ITEM_COUNT; i++) {
		printf("Box %d: %d, %d\n", i + 1, weight[i], volume[i]);
	}	
	fillthebag(weight, volume, bag_capacity);

	return 0;
}
