#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matrix.h"

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
