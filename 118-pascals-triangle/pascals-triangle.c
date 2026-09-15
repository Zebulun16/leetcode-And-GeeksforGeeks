/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int **result = (int **)malloc(numRows * sizeof(int *));
    for(int i=0;i<numRows;i++)
    {
        result[i] = malloc((i+1) * sizeof(int));
    }

    for(int i=0;i<numRows;i++)
    {
       
        
      
        
        int num = 1;
        for(int j=0;j<=i;j++)
        {
            result[i][j] = num;
            num = num * (i-j)/(j+1);
        }
        
    }
    
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for(int i=0;i<numRows;i++)
    {
        (*returnColumnSizes)[i] = i+1;
    }

    *returnSize = numRows;
    return result;

}