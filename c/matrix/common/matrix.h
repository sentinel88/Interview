#ifndef _MATRIX_H
#define _MATRIX_H

typedef struct matrix
{
    int rows, cols;
    int **ptr;
    int count_paths;
} MATRIX;


MATRIX* 
createMatrix (int rows, int cols);

int**
create2DArray (int dim1, int dim2);

void 
fillMatrix (const MATRIX *mat);
                       
void 
displayMatrix (const MATRIX *mat);

void
freeMatrix (MATRIX *mat);

#endif
