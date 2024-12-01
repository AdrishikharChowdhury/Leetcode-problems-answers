bool checkIfExist(int* arr, int arrSize) {
    int i,j;
    for(i=0;i<arrSize;i++)
    {
        for(j=arrSize-1;j>=0;j--)
        {
            if(i!=j && arr[i]==2*arr[j])
            {
                return true;
            }
        }
    }
    return false;
}