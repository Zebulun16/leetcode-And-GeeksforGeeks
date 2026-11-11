int findTargetSumWays(int* nums, int numsSize, int target) {
    int total = 0;
    for(int i=0;i<numsSize;i++)
    {
        total += nums[i];
    }

    if(abs(target) > total)
        return 0;
    if((target + total) % 2 != 0)
        return 0;

    int required = (target + total) / 2;
    int dp[required + 1];
    for(int i=0;i<=required;i++)
    {
        dp[i] = 0;
    }
    dp[0] = 1;
    for(int i=0;i<numsSize;i++)
    {
        for(int j=required;j>=nums[i];j--)
        {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[required];
}