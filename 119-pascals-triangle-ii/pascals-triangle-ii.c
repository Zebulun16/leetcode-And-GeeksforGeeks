/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    int count = 0;

    int *result = malloc((rowIndex + 1) * sizeof(int));

    long long num = 1;

    for(int j = 0; j <= rowIndex; j++)
    {
        result[j] = num;
        count++;

        num = num * (rowIndex - j) / (j + 1);
    }

    *returnSize = count;

    return result;      
        
    
}