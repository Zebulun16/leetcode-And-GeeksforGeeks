/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int prefix = 1,suffix = 1,count =0;
    int *res = malloc(numsSize * sizeof(int));

    for(int i=0;i<numsSize;i++)
    {
        res[i] = prefix;
        prefix *= nums[i];
    }

    for(int i = numsSize-1;i>=0;i--)
    {
        res[i] *= suffix;
        suffix *= nums[i];
        count++;
    }
    *returnSize = count;
    return res;
}