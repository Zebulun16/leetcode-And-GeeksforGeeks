/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize) {
    int *result = (int *)malloc(2*sizeof(int));
    int width =0,mid = 0,low = 1,high = area;
    while(low <= high)
    {
        mid = low + (high-low)/2;
        if(mid <= area / mid)
        {
            width = mid;
            low = mid + 1;
        }
        else
        {
            high = mid-1;
        }
        //width = mid;
    }
    while(width > 0 && area % width != 0)
    {
        width--;
    }
    int length = area/width;
    result[0] = length;
    result[1] = width;
    *returnSize = 2;
    return result;
}