int min(int a,int b)
{
    return a < b ? a : b;
}
int minCost(int n, int* cuts, int cutsSize) {
    int m = cutsSize;
    for(int i=0;i<m;i++)
    {
        for(int j=i+1;j<m;j++)
        {
            if(cuts[i] > cuts[j])
            {
                int temp = cuts[i];
                cuts[i] = cuts[j];
                cuts[j] = temp;
            }
        }
    }

    int arr[m+2];
    arr[0] = 0;
    arr[m+1] = n;

    for(int i=1;i<=m;i++)
    {
        arr[i] = cuts[i-1];
    }

    int dp[m+2][m+2];
    for(int i=0;i<m+2;i++)
    {
        for(int j=0;j<m+2;j++)
        {
            dp[i][j] = 0;
        }
    }

    for(int i=m;i>=1;i--)
    {
        for(int j=i;j<=m;j++)
        {
            int mini = INT_MAX;
            for(int k=i;k<=j;k++)
            {
                int cost = arr[j+1] - arr[i-1] + dp[i][k-1]+dp[k+1][j];

                mini = min(mini,cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][m];
}