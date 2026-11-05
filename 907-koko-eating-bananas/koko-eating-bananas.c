int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = piles[0],mid;
    long long speed;
    for(int i=0;i<pilesSize;i++)
    {
        if(piles[i] > high)
        {
            high = piles[i];
        }
    }
    while(low <= high)
    {
        mid = low + (high - low) / 2;
        speed = 0;
        for(int i=0;i<pilesSize;i++)
        {
            speed += (piles[i] + mid - 1) / mid;
            
        }
        if(speed <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }

    }
    return low;
}