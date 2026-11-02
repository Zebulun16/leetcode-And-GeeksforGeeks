int pivotIndex(int* nums, int numsSize) {
    int left = 0,right = 0,sum = 0;
    for(int i=0;i<numsSize;i++)
    {
        sum = sum + nums[i];
    }

    for(int i=0;i<numsSize;i++)
    {
        right = sum - nums[i] - left;

        

        if(left == right)
            return i;

        left += nums[i];

    }
    return -1;
}