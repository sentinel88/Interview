#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define DIMENSIONS 2

static void
print (int **, int);


static bool
checkpos (int **board, int **positions, int level, int col, int num)
{
	bool conflict = false;
	int i, j, k;

	if (!level)
		return conflict;
	if (positions[1][col])
		return true;
	i = level - 1, j = col;
	k = 1;
	while (1) {
		if (i < 0)
			break;
		if (((j - k) >= 0) && board[i][j - k]) {
			conflict = true;
			break;
		}
		if (((j + k) < num) && board[i][j + k]) {
			conflict = true;
			break;
		}
		i--;
		k++;
	}		

	return conflict;
}


static bool
nqueens (int **board, int num, int level, int **positions)
{
	int i;
	bool solution = false;

	if (level == num) {
		print(board, num);
		return true;
	}
	for (i = 0; i < num; i++) {
		if (!checkpos(board, positions, level, i, num)) {
			positions[0][level] = 1;
			positions[1][i] = 1;
			board[level][i] = 1;
			solution = nqueens(board, num, level + 1, positions);
			if (solution)
				break;
			board[level][i] = 0;
		}
	}
	if (!solution)
		memset(board[level], 0, sizeof(int) * num);
	return solution;
}

static void
print (int **board, int num)
{
	int i, j;
	printf("\nChess Board\n");
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

int
main (int argc, char *argv[])
{
	int num;
	int **board = NULL;
	int **positions = NULL;
	int i;
	bool solution = false;

	printf("\nEnter the number of queens to be placed on the chess board\n");
	scanf(" %d", &num);
	board = (int **) malloc (num * sizeof(int *));
	positions = (int **) malloc (DIMENSIONS * sizeof(int *));
	for (i = 0; i < num; i++) {
		board[i] = (int *) calloc (num, sizeof(int));
	}
	for (i = 0; i < DIMENSIONS; i++) {
		positions[i] = (int *) calloc (num, sizeof(int));
	}
	solution = nqueens(board, num, 0, positions);
	if (solution) {
		for (i = 0; i < num; i++) {
			free(board[i]);	
		}
		free(board);
		for (i = 0; i < DIMENSIONS; i++) {
			free(positions[i]);
		}
		free(positions);
	} else {
		printf("\n%d Queens cannot be placed on the board without conflicts\n", num);
	}

	return 0;
}
