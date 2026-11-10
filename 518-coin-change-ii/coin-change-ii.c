int change(int amount, int* coins, int coinsSize) {
    long long dp[amount + 1];

    for(int i = 0; i <= amount; i++)
    {
        dp[i] = 0;
    }

    dp[0] = 1;

    for(int i = 0; i < coinsSize; i++)
    {
        for(int sum = coins[i]; sum <= amount; sum++)
        {
            dp[sum] += dp[sum - coins[i]];
            if(dp[sum] > INT_MAX)
            {
                dp[sum] = INT_MAX;
            }
        }
    }

    return (int)dp[amount];
}