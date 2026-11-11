int lengthOfLIS(int* nums, int numsSize) {
    int dp[numsSize];
    for(int i=0;i<numsSize;i++)
    {
        dp[i] = 1;
    }

    for(int i=1;i<numsSize;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(nums[i] > nums[j])
            {
                if(dp[j] + 1 > dp[i])
                {
                    dp[i] = dp[j] + 1;
                }
            }
        }
    }

    int max = 0;
    for(int i=0;i<numsSize;i++)
    {
        if(dp[i] > max)
        {
            max = dp[i];
        }
    }
    return max;
}