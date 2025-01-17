/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int i,suffix=1,n=numsSize;
    int *ans=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        ans[i]=1;
    for(i=1;i<n;i++)
    {
        ans[i]=ans[i-1]*nums[i-1];
    }
    for(i=n-2;i>=0;i--)
    {
        suffix*=nums[i+1];
        ans[i]*=suffix;
    }
    *returnSize=n;
    return ans;
}