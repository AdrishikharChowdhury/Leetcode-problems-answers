int* sort(int *nums,int n)
{
    int t;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                t=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=t;
            }
        }
    }
    return nums;
}
bool canBeEqual(int* target, int targetSize, int* arr, int arrSize) {
    int *t,*a,c=0,ts=targetSize,as=arrSize;
    t=(int *)malloc(targetSize*sizeof(int));
    a=(int *)malloc(arrSize*sizeof(int));
    t=sort(target,ts);
    a=sort(arr,as);
    for(int i=0;i<targetSize;i++)
    {
        if(t[i]==a[i])
        c++;
    }
    if(c==arrSize)
    return true;
    else
    return false;
}