/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* luckyNumbers(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int *result = malloc(matrixSize * sizeof(int));

    int k = 0;

    // Find minimum element of each row
    for (int i = 0; i < matrixSize; i++)
    {
        int min = matrix[i][0];
        int col = 0;

        for (int j = 1; j < *matrixColSize; j++)
        {
            if (matrix[i][j] < min)
            {
                min = matrix[i][j];
                col = j;
            }
        }

        // Check whether the row minimum
        // is the maximum element in its column
        int lucky = 1;

        for (int j = 0; j < matrixSize; j++)
        {
            if (matrix[j][col] > min)
            {
                lucky = 0;
                break;
            }
        }

        if (lucky)
        {
            result[k] = min;
            k++;
        }
    }

    *returnSize = k;

    return result;
}