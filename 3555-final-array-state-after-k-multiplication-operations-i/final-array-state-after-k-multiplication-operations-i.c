/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int minIdx(int *a,int n)
{
    int idx=0,i,min;
    min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
        {
            min=a[i];
            idx=i;
        }
    }
    return idx;
}
int* getFinalState(int* nums, int numsSize, int k, int multiplier, int* returnSize) {
    int idx,i=0;
    while(i<k)
    {
        idx=minIdx(nums,numsSize);
        nums[idx]*=multiplier;
        i+=1;
    }
    *returnSize=numsSize;
    return nums;
}