int rob_linear(int *nums,int start,int end)
{
    int prev2 = 0;
    int prev1 = 0;

    for(int i=start;i<=end;i++)
    {
        int take = nums[i] + prev2;
        int skip = prev1;
        int current = take > skip ? take : skip;
        prev2 = prev1;
        prev1 = current;
    }
    return prev1;
}
int rob(int* nums, int numsSize) {
    if(numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    int case1 = rob_linear(nums,0,numsSize-2);
    int case2 = rob_linear(nums,1,numsSize-1);

    return case1 > case2 ? case1 : case2;
}