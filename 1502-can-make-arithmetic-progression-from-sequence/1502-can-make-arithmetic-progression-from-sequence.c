int *bubbleSort(int *arr, int arrSize){
    int temp,i,j;
    for(i=0;i<arrSize-1;i++){
        for(j=0;j<arrSize-i-1;j++){
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;  
}

bool canMakeArithmeticProgression(int* arr, int arrSize) {
    int i,diff;
    arr=bubbleSort(arr,arrSize);
    diff=arr[1]-arr[0];
    for(i=2;i<arrSize;i++){
        if(arr[i]-arr[i-1]!=diff){
            return false;
        }
    }
    return true;
}