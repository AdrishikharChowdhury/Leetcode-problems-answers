void sortColors(int* a, int numsSize) {
    int i,j,temp;
    for(i=0;i<numsSize;i++)
    {
        for(j=0;j<numsSize-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}