int pivotIndex(int* nums, int numsSize) {
    int *prefix = calloc(numsSize,sizeof(int));
    if(prefix == NULL)
        return 1;
    int *suffix = calloc(numsSize,sizeof(int));
    if(suffix == NULL)
        return 1;
    for(int i=1;i<numsSize;i++)
    {
        prefix[i] = prefix[i-1] + nums[i-1];
    }

    for(int i = numsSize - 2;i>=0;i--)
    {
        suffix[i] = suffix[i+1] + nums[i+1];
    }

    for(int i=0;i<numsSize;i++)
    {
        if(prefix[i] == suffix[i])
            return i;
    }
    return -1;
}