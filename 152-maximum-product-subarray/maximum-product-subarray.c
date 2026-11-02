int maxProduct(int* nums, int numsSize) {
    int minimum_multi = nums[0],maximum_multi = nums[0],result = nums[0];
    for(int i=1;i<numsSize;i++)
    {
        int temp_max = maximum_multi;
        int temp_min = minimum_multi;
        
        maximum_multi = fmax(nums[i],fmax(temp_max * nums[i],temp_min * nums[i]));
        minimum_multi = fmin(nums[i],fmin(temp_max * nums[i],temp_min * nums[i]));

        if(maximum_multi > result)
        {
            result = maximum_multi;
        }
        
           
        
        
        
         
        

        
       
           
        
    }
    return result;
}