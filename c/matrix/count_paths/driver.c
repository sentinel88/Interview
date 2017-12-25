#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

static int
countPaths (MATRIX *mat)
{
    int **ptr = create2DArray(mat->rows, mat->cols);
    int i, j;
    int rows = mat->rows;
    int cols = mat->cols;

    if (!ptr)
    {
        printf("\nDue to memory allocation failure, count of paths is 0\n");
        exit(0);
    }
    for (i = 0; i < cols; i++)
    {
        ptr[0][i] = 1;
    }
    for (i = 0; i < rows; i++)
    {
        ptr[i][0] = 1;
    }
    for (i = 1; i < rows; i++)
    {
       for (j = 1; j < cols; j++)
       {
          ptr[i][j] = ptr[i][j - 1] + ptr[i - 1][j];
       }
    }
    printf("\nMatrix computed for counting paths\n\n");
    MATRIX mat1;
    mat1.rows = rows;
    mat1.cols = cols;
    mat1.count_paths = 0;
    mat1.ptr = ptr;
    displayMatrix(&mat1);
    mat1.count_paths = ptr[rows - 1][cols - 1];
}

int main (int argc, char *argv[])
{
    int rows, cols;

    printf ("\nEnter the number of rows and cols for the mxn matrix\n");    
    scanf ("%d %d", &rows, &cols);
    printf ("\nCreate the matrix\n");
    MATRIX *mat = createMatrix(rows, cols);
    printf ("\nFill the matrix\n");
    fillMatrix(mat);
    printf ("INPUT MATRIX\n\n");
    displayMatrix(mat);
    countPaths(mat);
    printf("\nTotal number of paths from top left to bottom right %d", mat->count_paths);

    return 0;
}
