int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int prev2 = nums[0];
    int prev1 = nums[0] > nums[1] ? nums[0] : nums[1];

    for(int i=2;i<numsSize;i++)
    {
        int take = nums[i] + prev2;
        int skip = prev1;
        int current = take > skip ? take : skip;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
        
}