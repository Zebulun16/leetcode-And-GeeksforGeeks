int longestOnes(int* nums, int numsSize, int k) {
    int l = 0, r = 0;
    int max_len = 0;

    while(r < numsSize)
    {
        if(nums[r] == 0)
        {
            k--;
        }

        while(k < 0)
        {
            if(nums[l] == 0)
            {
                k++;
            }

            l++;
        }

        int len = r - l + 1;

        if(len > max_len)
        {
            max_len = len;
        }

        r++;
    }

    return max_len;
}