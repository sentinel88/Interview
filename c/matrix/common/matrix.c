#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "matrix.h"

#define DEFAULT_COUNT_PATHS 0

MATRIX*
createMatrix (int rows, int cols)
{
    MATRIX *mptr = (MATRIX *)malloc(sizeof(MATRIX));
    int **ptr = NULL;
    if (!mptr)
    {
        printf("\nmemory allocation failure\n");
        exit(0);
    }
    mptr->ptr = NULL;
    mptr->rows = rows;
    mptr->cols = cols;
    mptr->count_paths = DEFAULT_COUNT_PATHS;
    ptr = create2DArray(rows, cols);
    if (!ptr)
    {
        free(mptr);
        exit(0);
    }
    mptr->ptr = ptr;
    printf("\nSuccessfully created the matrix\n");
    return mptr;
}


void
fillMatrix (const MATRIX *mat)
{
    printf("\nEnter the elements of the matrix\n");

    int **ptr = mat->ptr;
    int i, j;
    for (i = 0; i < mat->rows; i++)
    {
        for (j = 0; j < mat->cols; j++)
        {
            scanf("%d", &(ptr[i][j]));
        }
    }
}


int**
create2DArray (int dim1, int dim2)
{
    int **ptr = (int **)malloc(sizeof(MATRIX *) * dim1);
    int i;
    if (!ptr)
    {
        printf("\nUnable to allocate memory for 2d array\n");
        return NULL;
    }
    for (i = 0; i < dim1; i++)
    {
        ptr[i] = (int *)calloc(dim2, sizeof(int));
    }
    return ptr; 
}


void
displayMatrix (const MATRIX *mat)
{
    int **ptr = mat->ptr;
    int i, j;
    for (i = 0; i < mat->rows; i++)
    {
        for (j = 0; j < mat->cols; j++)
        {
            printf("%d ", ptr[i][j]);
        }
        printf("\n");
    }
}
