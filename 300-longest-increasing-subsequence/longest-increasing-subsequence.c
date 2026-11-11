int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize <= 0)
        return 0;

    int tails[numsSize];
    int len = 0;

    for(int i = 0; i < numsSize; i++)
    {
        int low = 0;
        int high = len;

        while(low < high)
        {
            int mid = low + (high - low) / 2;

            if(tails[mid] < nums[i])
                low = mid + 1;
            else
                high = mid;
        }

        tails[low] = nums[i];

        if(low == len)
            len++;
    }

    return len;
}