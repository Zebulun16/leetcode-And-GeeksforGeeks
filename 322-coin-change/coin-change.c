int coinChange(int* coins, int coinsSize, int amount) {
    int *dp = malloc((amount+ 1) * sizeof(int));

    if(dp == NULL)
    {
        return -1;
    }

    for(int i=0;i <= amount;i++)
    {
        dp[i] = INT_MAX;
    }

    dp[0] = 0;
    for(int i=0;i<coinsSize;i++)
    {
        for(int sum = coins[i];sum <= amount;sum++)
        {
            if(dp[sum - coins[i]] != INT_MAX)
            {
                int take = 1 + (dp[sum - coins[i]]);

                if(take < dp[sum])
                {
                    dp[sum] = take;
                }
            }
        }
    }

    int ans = dp[amount];
    free(dp);
    return (ans == INT_MAX) ? -1 : ans;
    

    
}