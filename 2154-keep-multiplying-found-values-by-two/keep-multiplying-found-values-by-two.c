int search(int* nums, int numsSize, int original)
{
    int flag=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==original)
        {
            flag=1;
        }
    }
    if(flag==1)
        return original=search(nums,numsSize,2*original);
    else
        return original;
}
int findFinalValue(int* nums, int numsSize, int original) {
    int i,j;
    int og=search(nums,numsSize,original);
    return og;
}