int longestOnes(int* nums, int numsSize, int k) {
    int l = 0,r = 0,max = INT_MIN,len = 0;
    while(r < numsSize)
    {
        if(nums[r] == 1)
        {
            len = r - l + 1;
            if(len > max)
                max = len;
        }
        else if(nums[r] == 0 && k != 0)
        {
            k--;
            len = r - l + 1;
            if(len > max)
                max = len;
        }
        else if(nums[r] == 0 && k == 0)
        {
            while(k==0)
            {
                if(nums[l] == 0)
                   k++;

                l++;
            }
            k--;
            len = r - l + 1;
            if(len > max)
                max = len;
        }
        r++;
    }
    return max;
}