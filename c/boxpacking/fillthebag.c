/* fillthebag.c */

/* Fill the bag with boxes of different weights and sizes (calculate volume). Assumptions: The bag is assumed to have an upper limit in terms of weight and volume. Boxes are cubes and are solid. We will try to maximize the number of boxes we can pack in the bag in every loading cycle and minimize the total number of loading cycles. For simplicity we consider the weight and size of the boxes to be integer and of some measurable unit. Also, that the available boxes can fit in the bag and are not of some incompatible size */

/* Author: Nishanth Nagendra */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define ITEM_COUNT 5


static float
max (float a, float b)
{
	return ( (a > b) ? a : b);
}


/* We calculate something called as the fit factor that is equal to max (wratio, vratio). wratio is (weight/volume) and vratio is (volume/weight). Boxes can be of any shape and size. In order to consider this we need two ratios to cover boxes which are heavier but less volume or vice versa. We then sort the boxes according to fit factor and fill them in the bag until they do not exceed the capacity of the bag (weight, volume). This is only a heuristic and can be expected to give an approximate solution only but not optimal. */


static void
sort_boxes (int *weight, int *size, int *volume)
{
	float fit_factor[ITEM_COUNT];
	int i, j;
	float temp;
	int tempval;
	bool swap = false;

	printf("\nCollection (weight, size, volume, fit factor)\n\n");
	for (i = 0; i < ITEM_COUNT; i++) {
		fit_factor[i] = max( (weight[i]/volume[i]), (volume[i]/weight[i]) );
                printf("Box %d: %d, %d, %d, %f\n", i + 1, weight[i], size[i], volume[i], fit_factor[i]);
        }

	/* Sort the weight and volume of the boxes according to their fit factor. Using bubble sort */
	for (i = 0; i < (ITEM_COUNT - 1); i++) {
		swap = false;
		for (j = 0; j < (ITEM_COUNT - i - 1); j++) {
			if (fit_factor[j] > fit_factor[j + 1]) {
				temp = fit_factor[j];
				fit_factor[j] = fit_factor[j + 1];
				fit_factor[j + 1] = temp;
				swap = true;

				tempval = weight[j];
				weight[j] = weight[j + 1];
				weight[j + 1] = tempval;
	
				tempval = volume[j];
				volume[j] = volume[j + 1];
				volume[j + 1] = tempval;
			}
		}
		if (!swap)
			break;  /* Bubble sort: No swap happened during the previous iteration hence we break as array is sorted */
	}	
	printf("\n\nAfter sorting the collection of boxes\n");
	printf("\nCollection (weight, size, volume, fit factor)\n\n");
        for (i = 0; i < ITEM_COUNT; i++)
                printf("Box %d: %d, %d, %d, %f\n", i + 1, weight[i], size[i], volume[i], fit_factor[i]);
}


/* Fill the bag according to the sorted boxes (by weight and volume) */

static void
fillthebag (int *weight, int *size, int *volume, int *bag_capacity)    /* bag_capacity[0] is weight of the bag and bag_capacity[1] is volume */
{
	bool select[ITEM_COUNT];
	int i;
	bool full;
	int fill_weight;
	int fill_volume;
	int fill_count;
	int item_count = ITEM_COUNT;	
	int cycles = 0;

	for (i = 0; i < ITEM_COUNT; i++) {
		select[i] = false;
	}
	sort_boxes(weight, size, volume);
	while (item_count) {
		full = false;
		fill_count = 0;
		fill_weight = 0;
		fill_volume = 0;
		fill_count = 0;
		i = 0;
		printf("\nLoading Cycle %d\n", cycles + 1);
		while (i < ITEM_COUNT) {
			if (select[i]) {
				i++;
				continue;
			}
			if ( ((fill_weight + weight[i]) <= bag_capacity[0]) &&
				((fill_volume + volume[i]) <= bag_capacity[1]) ) {
				printf("Box with weight %d and volume %d selected\n", weight[i], volume[i]);
				select[i] = true;
				fill_count++;
				fill_weight += weight[i];
				fill_volume += volume[i];
			}
			i++;
		}
		printf("Remaining capacity of the bag: Weight: %d, Volume: %d\n", (bag_capacity[0] - fill_weight), 
									(bag_capacity[1] - fill_volume) );
		printf("\n\n");
		item_count -= fill_count;
		cycles++;
	}
	printf("\nTotal number of loading cycles: %d\n", cycles);
}

int 
main (int argc, char *argv[])
{
	int weight[ITEM_COUNT];
	int size[ITEM_COUNT];
	int volume[ITEM_COUNT];
	int bag_capacity[2];
	int i;

	printf("\nEnter the capacity of the bag (weight and volume)\n");
	scanf(" %d %d", &bag_capacity[0], &bag_capacity[1]);
	
	for (i = 0; i < ITEM_COUNT; i++) {
		printf("Enter the weight and size of box %d\n", i + 1);
		scanf(" %d %d", &weight[i], &size[i]);
		volume[i] = size[i] * size[i] * size[i];
		if ( (weight[i] > bag_capacity[0]) || (volume[i] > bag_capacity[1]) ) {
			printf("\nIncorrect dimensions of the box to fit inside the bag. Please re enter\n");
			i--;
		}
	}	
/*
	printf("\nCollection (weight, volume)\n\n");
	for (i = 0; i < ITEM_COUNT; i++) {
		printf("Box %d: %d, %d\n", i + 1, weight[i], volume[i]);
	}	
*/
	fillthebag(weight, size, volume, bag_capacity);

	return 0;
}
