int maxProfit(int* prices, int pricesSize) {
    int profit = 0,buy = prices[0];

    for(int i=1;i<pricesSize;i++)
    {
        if(prices[i] < buy)
            buy = prices[i];
        if(prices[i] - buy > profit)
            profit = prices[i] - buy;
    }
    return profit;
}