bool canPartition(int* nums, int numsSize) {
    int total = 0;
    for(int i=0;i<numsSize;i++)
    {
        total += nums[i];
    }

    if(total % 2 != 0)
    {
        return false;
    }

    

    int target = total / 2;
    bool dp[target + 1];
    for(int i=0;i<=target;i++)
    {
        dp[i] = false;
    }

    dp[0] = true;
    for(int i=0;i<numsSize;i++)
    {
        for(int sum = target;sum >= nums[i];sum--)
        {
            dp[sum] = dp[sum] || dp[sum - nums[i]];
        }
    }
    return dp[target];
    
}