/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    int count = 0;
    char **result = malloc(n*sizeof(char *));
    for(int i=1;i<=n;i++)
    {
        if(i % 3 == 0 && i % 5 == 0)
        {
            result[i-1] = "FizzBuzz";
        }
        else if(i % 3 == 0)
        {
            result[i-1] = "Fizz";
        }
        else if(i % 5 == 0)
        {
            result[i-1] = "Buzz";
        }
        else
        {
            result[i-1] = malloc(12 * sizeof(char));
            sprintf(result[i-1],"%d",i);
        }
        count++;
    }
    *returnSize = count++;
    return result;
}