int missingNumber(int* nums, int n) {
    int arr=0;
    for(int i=0;i<n;i++)
    {
        arr=arr+nums[i];
    }
    int N=(n*(n+1))/2;
    return N-arr;
}