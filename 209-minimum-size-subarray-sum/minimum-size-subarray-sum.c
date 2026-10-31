int minSubArrayLen(int target, int* nums, int numsSize) {
    int left = 0,right = 0,len = 0,min = INT_MAX,sum = 0;
    while(right < numsSize)
    {
        sum += nums[right];
        while(sum >= target)
        {
            len = right - left + 1;
            if(len < min)
            {
                min = len;
            }

            sum -= nums[left];
            left++;
        }
        right++;
    }

    if(min == INT_MAX)
        return 0;
    else
        return min;
}