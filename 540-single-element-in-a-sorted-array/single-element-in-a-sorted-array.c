int singleNonDuplicate(int* nums, int numsSize) {
    int ans = 0;
    for(int i=0;i<numsSize;i++)
    {
        ans = ans ^ nums[i];
    }
    return ans;
}