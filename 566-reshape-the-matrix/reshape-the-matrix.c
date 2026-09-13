/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    if(matSize * (*matColSize) != r * c)
    {
        *returnSize = matSize;

        *returnColumnSizes = malloc(matSize * sizeof(int));

        for(int i = 0; i < matSize; i++)
        {
            (*returnColumnSizes)[i] = matColSize[i];
        }

        return mat;
    }

    int **result = malloc(r * sizeof(int *));

    *returnColumnSizes = malloc(r * sizeof(int));

    for(int i = 0; i < r; i++)
    {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    int k = 0;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            result[i][j] =
                mat[k / (*matColSize)][k % (*matColSize)];

            k++;
        }
    }

    *returnSize = r;

    return result;
}